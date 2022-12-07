#include "../../include/structure/Display.h"

/**************************************************************/
/*                  HELP FOR DISPLAY SECTION                 */
/************************************************************/

int color_is_null(G3Xcolor color) {
    return color.r < 0.|| color.g < 0. || color.b < 0. || color.a < 0.;
}

int material_is_null(Material material) {
    return material.ambi < 0. || material.diff < 0. || material.spec < 0. || material.shine < 0.;
}

int scale_is_null(G3Xvector scale_factor) {
    return scale_factor.x < 0. || scale_factor.y < 0. || scale_factor.z < 0.;
}

G3Xvector scale_adaptation(G3Xvector scale_factor) {
    if(scale_factor.x < 0)
        scale_factor.x *= -1;
    if(scale_factor.y < 0)
        scale_factor.y *= -1;
    if(scale_factor.z < 0)
        scale_factor.z *= -1;
    return scale_factor;
}

double step_calcul(double x, double y, double z) {
    G3Xpoint * campos = g3x_GetCamera()->pos;
    return MAX(sqrt(SQR(campos->x - x) + SQR(campos->y - y) + SQR(campos->z - z)) / 2.0, 1.);
}

/*****************************************************/
/*                  DISPLAY SECTION                 */
/***************************************************/

void display_tree_recursif(SceneTree node, G3Xhmat matrice, G3Xcolor color, Material material, G3Xvector scale_factor, bool flag) {
    if(node->next != NULL) // Transfer to next child of the parents
        display_tree_recursif(node->next, matrice, color, material, scale_factor, flag);

    if(!scale_is_null(node->scale_factor)) // IF scale factor exist in the node, change currange scale factor
        scale_factor = node->scale_factor;
    if(!color_is_null(node->col)) // IF color exist in the node, change current color
        color = node->col;
    if(!material_is_null(node->mat)) // IF material exist in the node, change current material
        material = node->mat;

    g3x_Material(color, material.ambi, material.diff, material.spec, material.shine, 0.);
    matrice = g3x_Mat_x_Mat(matrice, node->Md);
    
    
    if(node->instance != NULL) {
        glPushMatrix();
            glMultMatrixd(matrice.m); // Local matrix loading 
            scale_factor = g3x_Mat_x_Vector(matrice, scale_factor); // New scale_factor with the matrix
            scale_factor = scale_adaptation(scale_factor);
            if(flag)
                node->instance->draw_faces(node->instance, scale_factor, step_calcul(matrice.m[12],matrice.m[13],matrice.m[14]));
            else
                node->instance->draw_points(node->instance, scale_factor, step_calcul(matrice.m[12],matrice.m[13],matrice.m[14]));           
        glPopMatrix();
    }

    if(node->down != NULL) // Transfer to down child of this node
        display_tree_recursif(node->down, matrice, color, material, scale_factor, flag);
}

void display_tree_faces(SceneTree node) {
    display_tree_recursif(node, g3x_Identity(), node->col, node->mat, node->scale_factor, true);
}

void display_tree_points(SceneTree node) {
    display_tree_recursif(node, g3x_Identity(), node->col, node->mat, node->scale_factor, false);
}