#include "../../include/shape/Torus.h"

void draw_faces_torus (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j;

    // Construction with square-shaped faces
    glBegin(GL_QUADS);
    for (i = 0; i < torus.n1; i += step_theta) {           // Width 
        i_min = min(i + step_theta, torus.n1) % torus.n1; //
        for (j = 0; j < torus.n2 - 1; j +=  step_phi) {  // Height
            j_min = min(j + step_phi, torus.n2 - 1);
            // South-East
            g3x_Normal3dv(shape->norm[torus.n2 * i     + j_min]);
            g3x_Vertex3dv(shape->vrtx[torus.n2 * i     + j_min]);
            // North-East
            g3x_Normal3dv(shape->norm[torus.n2 * i_min + j_min]);
            g3x_Vertex3dv(shape->vrtx[torus.n2 * i_min + j_min]);
            // North-West
            g3x_Normal3dv(shape->norm[torus.n2 * i_min + j    ]);
            g3x_Vertex3dv(shape->vrtx[torus.n2 * i_min + j    ]);
            // South-West
            g3x_Normal3dv(shape->norm[torus.n2 * i     + j    ]);
            g3x_Vertex3dv(shape->vrtx[torus.n2 * i     + j    ]);
        }
    }
    glEnd();
}

void draw_points_torus (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j;

    // Construction with points
    glBegin(GL_POINTS);
    for (i = -step_theta; i < torus.n1; i += step_theta) {        // Width 
        i_min = min(i + step_theta, torus.n1) % torus.n1;        //
        for (j = -step_phi; j < torus.n2 - 1; j +=  step_phi) { // Height
            j_min = min(j + step_phi, torus.n2 - 1);
            g3x_Normal3dv(shape->norm[i_min * torus.n2 + j_min]);
            g3x_Vertex3dv(shape->vrtx[i_min * torus.n2 + j_min]);
        }
    }
    glEnd();
}

void draw_initialisation_torus(void) {
    torus.n1 = NBM;
    torus.n2 = NBP;
    torus.vrtx = (G3Xpoint *) malloc(torus.n1 * torus.n2 * sizeof(G3Xpoint));
    torus.norm = (G3Xpoint *) malloc(torus.n1 * torus.n2 * sizeof(G3Xpoint));

    double radius    = 1.0;                       // Torus radius (from the center to the end)
    double thickness = 0.5;                       // Torus thickness
    double theta     = 2 * M_PI /  torus.n1;       // Angle for width
    double phi       = 2 * M_PI / (torus.n2 - 1); // Angle for height
    int i, j;
    
    for (i = 0; i < torus.n1; i++) {      // Width 
        for (j = 0; j < torus.n2; j++) { // Height
            torus.vrtx[(i * torus.n2) + j].x =  cos(i * theta) * (radius + thickness * cos(j * phi));
            torus.vrtx[(i * torus.n2) + j].y = -sin(i * theta) * (radius + thickness * cos(j * phi));
            torus.vrtx[(i * torus.n2) + j].z =  sin(j * phi) * thickness; 
            //
            torus.norm[(i * torus.n2) + j].x =  cos(i * theta) * sin(j * phi);
            torus.norm[(i * torus.n2) + j].y = -sin(i * theta) * cos(j * phi);
            torus.norm[(i * torus.n2) + j].z =  sin(j * phi);
        }
    }

    torus.draw_faces = draw_faces_torus;
    torus.draw_points = draw_points_torus;
}