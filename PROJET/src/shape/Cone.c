#include "../../include/shape/Cone.h"

void draw_faces_cone (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j;

    // Construction with square-shaped faces
    glBegin(GL_QUADS);
    for (i = 0; i < cone.n1; i += step_theta) {          // Width of the cone 
        i_min = min(i + step_theta, cone.n1) % cone.n1; //
        for (j = 0; j < cone.n2; j += step_phi) {      // Height of the cone 
            j_min = min(j + step_phi, cone.n2 - 1);
            // South-East
            g3x_Normal3dv(shape->norm[cone.n2 * i     + j_min]);
            g3x_Vertex3dv(shape->vrtx[cone.n2 * i     + j_min]);
            // North-East
            g3x_Normal3dv(shape->norm[cone.n2 * i_min + j_min]);
            g3x_Vertex3dv(shape->vrtx[cone.n2 * i_min + j_min]);
            // North-West
            g3x_Normal3dv(shape->norm[cone.n2 * i_min + j    ]);
            g3x_Vertex3dv(shape->vrtx[cone.n2 * i_min + j    ]);
            // South-West
            g3x_Normal3dv(shape->norm[cone.n2 * i     + j    ]);
            g3x_Vertex3dv(shape->vrtx[cone.n2 * i     + j    ]);
        }
        for (j = 0; j < cone.n3; j += step_theta) { // Width of the circle
            j_min = min(j + step_theta, cone.n3 - 1);
            // South-East
            g3x_Normal3dv(shape->norm[(cone.n1 * cone.n2) + cone.n3 * i     + j_min]);
            g3x_Vertex3dv(shape->vrtx[(cone.n1 * cone.n2) + cone.n3 * i     + j_min]);
            // North-East
            g3x_Normal3dv(shape->norm[(cone.n1 * cone.n2) + cone.n3 * i_min + j_min]);
            g3x_Vertex3dv(shape->vrtx[(cone.n1 * cone.n2) + cone.n3 * i_min + j_min]);
            // North-West
            g3x_Normal3dv(shape->norm[(cone.n1 * cone.n2) + cone.n3 * i_min + j    ]);
            g3x_Vertex3dv(shape->vrtx[(cone.n1 * cone.n2) + cone.n3 * i_min + j    ]);
            // South-West
            g3x_Normal3dv(shape->norm[(cone.n1 * cone.n2) + cone.n3 * i     + j    ]);
            g3x_Vertex3dv(shape->vrtx[(cone.n1 * cone.n2) + cone.n3 * i     + j    ]);
        }
    }
    glEnd();
}

void draw_points_cone (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j;

    // Construction with points
    glBegin(GL_POINTS);
    for (i = -step_theta; i < cone.n1; i += step_theta) {   // Width of the cone 
        i_min = min(i + step_theta, cone.n1) % cone.n1;    //
        for (j = -step_phi; j < cone.n2; j += step_phi) { // Height of the cone 
            j_min = min(j + step_phi, cone.n2 - 1);
            g3x_Normal3dv(shape->norm[i_min * cone.n2 + j_min]);
            g3x_Vertex3dv(shape->vrtx[i_min * cone.n2 + j_min]);
        }
        for (j = -step_theta; j < cone.n3; j += step_theta) { // Width of the circle
            j_min = min(j + step_theta, cone.n3 - 1);
            g3x_Normal3dv(shape->norm[(cone.n1 * cone.n2) + i_min * cone.n3 + j_min]);
            g3x_Vertex3dv(shape->vrtx[(cone.n1 * cone.n2) + i_min * cone.n3 + j_min]);
        }
    }
    glEnd();
}

void draw_initialisation_cone(void) {
    cone.n1   = NBM;
    cone.n2   = NBP;
    cone.n3   = NBC;
    cone.vrtx = (G3Xpoint *) malloc(cone.n1 * (cone.n2 + cone.n3 ) * sizeof(G3Xpoint));
    cone.norm = (G3Xpoint *) malloc(cone.n1 * (cone.n2 + cone.n3 ) * sizeof(G3Xpoint));

    double height = 2.;                      // Cone height
    double radius = 1.;                      // Cone radius
    double theta  = 2 * M_PI / cone.n1;      // Angle
    double t      = height / (cone.n2 - 1);  // Height division
    double r      = radius / (cone.n3  - 1); // Radius division
    int i, j;

    for (i = 0; i < cone.n1; i++) {      // Width of the cone 
        for (j = 0; j < cone.n2; j++) { // Height of the cone 
            cone.vrtx[cone.n2 * i + j].x = ((height - j * t) / height) * radius * cos(i * theta);
            cone.vrtx[cone.n2 * i + j].y = ((height - j * t) / height) * radius * sin(i * theta);
            cone.vrtx[cone.n2 * i + j].z = (j * t) - (height / 2.);
            //
            cone.norm[cone.n2 * i + j].x = cos(i * theta);
            cone.norm[cone.n2 * i + j].y = sin(i * theta);
            cone.norm[cone.n2 * i + j].z = 1;
        }

        for (j = 0; j < cone.n3; j++) { // Width of the circle
            cone.vrtx[(cone.n1 * cone.n2) + cone.n3  * i + j].x = (j * r) * cos(i * theta);
            cone.vrtx[(cone.n1 * cone.n2) + cone.n3  * i + j].y = (j * r) * sin(i * theta);
            cone.vrtx[(cone.n1 * cone.n2) + cone.n3  * i + j].z = -height / 2.;
            //
            cone.norm[(cone.n1 * cone.n2) + cone.n3  * i + j].x = 0;
            cone.norm[(cone.n1 * cone.n2) + cone.n3  * i + j].y = 0;
            cone.norm[(cone.n1 * cone.n2) + cone.n3  * i + j].z = -1.;
        }
    }
    
    cone.draw_faces = draw_faces_cone;
    cone.draw_points = draw_points_cone;
}