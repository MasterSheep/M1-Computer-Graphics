#include "../../include/shape/Cube.h"

void draw_faces_cube (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_x = dcam * (1 / scale_factor.x);
    int step_y = dcam * (1 / scale_factor.y);
    int step_z = dcam * (1 / scale_factor.z);
    int i_min, j_min, k_min, i, j, k, l;


    // Construction with square-shaped faces
    glBegin(GL_QUADS);
    for (i = 0; i < cube.n1; i += step_x) {          // X
        i_min = min(i + step_x, cube.n1 - 1);       //
        for (j = 0; j < cube.n1; j += step_y) {    // Y
            j_min = min(j + step_y, cube.n1 - 1); //
            for (l = 0; l < 6; l += 3) {         // UP then DOWN
                // South-East
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + i     * cube.n1 + j_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + i     * cube.n1 + j_min]);
                // North-East
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + i_min * cube.n1 + j_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + i_min * cube.n1 + j_min]);
                // North-West
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + i_min * cube.n1 + j     ]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + i_min * cube.n1 + j     ]);
                // South-West
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + i     * cube.n1 + j     ]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + i     * cube.n1 + j     ]);
            }
        }
    }
    for (k = 0; k < cube.n1; k += step_z) {          // Z
        k_min = min(k + step_z, cube.n1 - 1);       //
        for (i = 0; i < cube.n1; i += step_x) {    // X
            i_min = min(i + step_x, cube.n1 - 1); //
            for (l = 1; l < 6; l += 3) {         // RIGHT-FORWARD then LEFT-BACK 
                // South-East
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + k     * cube.n1 + i_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + k     * cube.n1 + i_min]);
                // North-East
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + k_min * cube.n1 + i_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + k_min * cube.n1 + i_min]);
                // North-West
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + k_min * cube.n1 + i     ]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + k_min * cube.n1 + i     ]);
                // South-West
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + k     * cube.n1 + i     ]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + k     * cube.n1 + i     ]);
            }
        }
    }
    for (j = 0; j < cube.n1; j += step_y) {          // Y
        j_min = min(j + step_y, cube.n1 - 1);       //
        for (k = 0; k < cube.n1; k += step_z) {    // X
            k_min = min(k + step_z, cube.n1 - 1); //
            for (l = 2; l < 6; l += 3) {         // LEFT-FORWARD then RIGHT-BACK
                // South-East
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + j     * cube.n1 + k_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + j     * cube.n1 + k_min]);
                // North-East
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + j_min * cube.n1 + k_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + j_min * cube.n1 + k_min]);
                // North-West
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + j_min * cube.n1 + k     ]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + j_min * cube.n1 + k     ]);
                // South-West
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + j     * cube.n1 + k     ]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + j     * cube.n1 + k     ]);
            }
        }
    }
    glEnd();
}

void draw_points_cube (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_x = dcam * (1 / scale_factor.x);
    int step_y = dcam * (1 / scale_factor.y);
    int step_z = dcam * (1 / scale_factor.z);
    int i_min, j_min, k_min, i, j, k, l;

    // Construction with points
    glBegin(GL_POINTS);
    for (i = -step_x; i < cube.n1; i += step_x) {       // X
        i_min = min(i + step_x, cube.n1 - 1);          //
        for (j = -step_y; j < cube.n1; j += step_y) { // Y
            j_min = min(j + step_y, cube.n1 - 1);    //
            for (l = 0; l < 6; l += 3) {            // UP then DOWN
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + i_min * cube.n1 + j_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + i_min * cube.n1 + j_min]);
            }
        }
    }
    for (k = -step_z; k < cube.n1; k += step_z) {       // Z
        k_min = min(k + step_z, cube.n1 - 1);          //
        for (i = -step_x; i < cube.n1; i += step_x) { // X
            i_min = min(i + step_x, cube.n1 - 1);    //
            for (l = 1; l < 6; l += 3) {            // RIGHT-FORWARD then LEFT-BACK 
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + k_min * cube.n1 + i_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + k_min * cube.n1 + i_min]);
            }
        }
    }
    for (j = -step_y; j < cube.n1; j += step_y) {       // Y
        j_min = min(j + step_y, cube.n1 - 1);          //
        for (k = -step_z; k < cube.n1; k += step_z) { // X
            k_min = min(k + step_z, cube.n1 - 1);    //
            for (l = 2; l < 6; l += 3) {            // LEFT-FORWARD then RIGHT-BACK
                g3x_Normal3dv(shape->norm[l * (cube.n1 * cube.n1) + j_min * cube.n1 + k_min]);
                g3x_Vertex3dv(shape->vrtx[l * (cube.n1 * cube.n1) + j_min * cube.n1 + k_min]);
            }
        }
    }
    glEnd();
}

void draw_initialisation_cube(void) {
    cube.n1   = NBM;
    cube.vrtx = (G3Xpoint *) malloc(6 * cube.n1 * cube.n1 * sizeof(G3Xpoint));
    cube.norm = (G3Xpoint *) malloc(6 * cube.n1 * cube.n1 * sizeof(G3Xpoint));

    double width = 2.;                     // Cube width
    double size  = width / (cube.n1 - 1);  // Width division 
    int i, j;
    
    for (i = 0; i < cube.n1; i++) {      // Width
        for (j = 0; j < cube.n1; j++) { // Height
            // UP
            cube.vrtx[0 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = size * i - width / 2.;
            cube.vrtx[0 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = size * j - width / 2.;
            cube.vrtx[0 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = width / 2.;
            //
            cube.norm[0 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = 0;
            cube.norm[0 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = 0;
            cube.norm[0 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = 1;
            // RIGHT-FORWARD
            cube.vrtx[1 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = size * j - width / 2.;
            cube.vrtx[1 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = width / 2.;
            cube.vrtx[1 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = size * i - width / 2.;
            //
            cube.norm[1 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = 0;
            cube.norm[1 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = 1;
            cube.norm[1 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = 0;
            // LEFT-FORWARD
            cube.vrtx[2 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = width / 2.;
            cube.vrtx[2 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = size * i - width / 2.;
            cube.vrtx[2 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = size * j - width / 2.;
            //
            cube.norm[2 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = 1;
            cube.norm[2 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = 0;
            cube.norm[2 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = 0;
            // DOWN
            cube.vrtx[3 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = size * (cube.n1 - 1 - i) - width / 2.;
            cube.vrtx[3 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = size * (cube.n1 - 1 - j) - width / 2.;
            cube.vrtx[3 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = -width / 2.;
            //
            cube.norm[3 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = 0;
            cube.norm[3 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = 0;
            cube.norm[3 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = -1;
            // LEFT-BACK
            cube.vrtx[4 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = size * (cube.n1 - 1 - j) - width / 2.;
            cube.vrtx[4 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = -width / 2.;
            cube.vrtx[4 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = size * (cube.n1 - 1 - i) - width / 2.;
            //
            cube.norm[4 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = 0;
            cube.norm[4 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = -1;
            cube.norm[4 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = 0;
            // RIGHT-BACK
            cube.vrtx[5 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = -width / 2.;
            cube.vrtx[5 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = size * (cube.n1 - 1 - i) - width / 2.;
            cube.vrtx[5 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = size * (cube.n1 - 1 - j) - width / 2.;
            //
            cube.norm[5 * (cube.n1 * cube.n1) + (i * cube.n1) + j].x = -1;
            cube.norm[5 * (cube.n1 * cube.n1) + (i * cube.n1) + j].y = 0;
            cube.norm[5 * (cube.n1 * cube.n1) + (i * cube.n1) + j].z = 0;
        }
    }
    
    cube.draw_faces = draw_faces_cube;
    cube.draw_points = draw_points_cube;
}