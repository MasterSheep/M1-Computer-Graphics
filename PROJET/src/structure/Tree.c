#include "../../include/structure/Tree.h"

/***********************************************************/
/*                  HELP FOR NODE SECTION                 */
/*********************************************************/

Material creat_material(double ambi, double diff, double spec, double shine) {
    Material mat;
    mat.ambi = ambi;
    mat.diff = diff;
    mat.spec = spec;
    mat.shine = shine;
    return mat;
}

G3Xvector creat_g3xvector(double x, double y, double z) {
    G3Xvector vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

G3Xcolor creat_color(double r, double g, double b, double a) {
    G3Xcolor color = {r, g, b, a};
    return color;
}

/**************************************************/
/*                  NODE SECTION                 */
/************************************************/

SceneTree node_allocation(void) {
    SceneTree cell;
    cell = (Node*) malloc(sizeof(Node));
    if (cell != NULL) {
        cell->down = NULL;
        cell->next = NULL;
        cell->instance = NULL;
        cell->mat;
    }
    return cell;
}

SceneTree creat_node_empty(void) {
    SceneTree node = node_allocation();
    node->Md = g3x_Identity();
    node->col = creat_color(-1., -1., -1., -1.);
    node->mat = creat_material(-1., -1., -1., -1.);
    node->scale_factor.x = node->scale_factor.y = node->scale_factor.z = -1.0;
    return node;
}

SceneTree creat_node_shape(Shape * instance) {
    SceneTree node = node_allocation();
    node->Md = g3x_Identity();
    node->col = creat_color(-1., -1., -1., -1.);
    node->mat = creat_material(-1., -1., -1., -1.);
    node->scale_factor.x = node->scale_factor.y = node->scale_factor.z = -1.0;
    node->instance = instance;
    return node;
}

SceneTree creat_node_property(G3Xhmat Md, G3Xcolor col, Material mat, G3Xvector scale_factor) {
    SceneTree node = node_allocation();
    node->Md = Md;
    node->col = col;
    node->mat = mat;
    node->scale_factor = scale_factor;
    return node;
}


SceneTree creat_node(Shape * instance, G3Xhmat Md, G3Xcolor col, Material mat, G3Xvector scale_factor) {
    SceneTree node = node_allocation();
    node->Md = Md;
    node->col = col;
    node->mat = mat;
    node->scale_factor = scale_factor;
    node->instance = instance;
    return node;
}

/**************************************************/
/*                  ADD SECTION                  */
/************************************************/

void add_matrix(Node * node, G3Xhmat Md) {
    node->Md = g3x_Mat_x_Mat(node->Md, Md);
}

void add_color(Node * node, G3Xcolor col) {
    node->col = col;
}

void add_material(Node * node, Material mat) {
    node->mat = mat;
}

void add_scale_factor(Node * node, G3Xvector scale_factor) {
    node->scale_factor = scale_factor;
}

void add_child(Node * parents, Node * child) {
    if(parents->down == NULL) {
        parents->down = child;
    } else {
        child->next = parents->down;
        parents->down = child;
    }
}