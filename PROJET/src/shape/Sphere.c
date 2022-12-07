#include "../../include/shape/Sphere.h"

void draw_faces_sphere(struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j;

    // Construction with square-shaped faces
    glBegin(GL_QUADS);
    for (i = 0; i < sphere.n1; i += step_theta) {            // Width
        i_min = min(i + step_theta, sphere.n1) % sphere.n1; //
        for (j = 0; j < sphere.n2 - 1; j += step_phi) {    // Height
            j_min = min(j + step_phi, sphere.n2 - 1);
            // South-East
            g3x_Normal3dv(shape->norm[sphere.n2 * i     + j_min]);
            g3x_Vertex3dv(shape->vrtx[sphere.n2 * i     + j_min]);
            // North-East
            g3x_Normal3dv(shape->norm[sphere.n2 * i_min + j_min]);
            g3x_Vertex3dv(shape->vrtx[sphere.n2 * i_min + j_min]);
            // North-West
            g3x_Normal3dv(shape->norm[sphere.n2 * i_min + j    ]);
            g3x_Vertex3dv(shape->vrtx[sphere.n2 * i_min + j    ]);
            // South-West
            g3x_Normal3dv(shape->norm[sphere.n2 * i     + j    ]);
            g3x_Vertex3dv(shape->vrtx[sphere.n2 * i     + j    ]);
        }
    }
    glEnd();
}

void draw_points_sphere(struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j;

    // Construction with points
    glBegin(GL_POINTS);
    for (i = -step_theta; i < sphere.n1; i += step_theta) {       // Width
        i_min = min(i + step_theta, sphere.n1) % sphere.n1;      //
        for (j = -step_phi; j < sphere.n2 - 1; j += step_phi) { // Height
            j_min = min(j + step_phi, sphere.n2 - 1);
            g3x_Normal3dv(shape->norm[i_min * sphere.n2 + j_min]);
            g3x_Vertex3dv(shape->vrtx[i_min * sphere.n2 + j_min]);
        }
    }
    glEnd();
}

void draw_initialisation_sphere(void) {
    sphere.n1 = NBM;
    sphere.n2 = NBP;
    sphere.vrtx = (G3Xpoint *) malloc(sphere.n1 * sphere.n2 * sizeof(G3Xpoint));
    sphere.norm = (G3Xpoint *) malloc(sphere.n1 * sphere.n2 * sizeof(G3Xpoint));

    double radius = 1.;                     // Sphere radius
    double theta  = 2 * M_PI / sphere.n1;   // Angle for width
    double phi    = M_PI / (sphere.n2 - 1); // Angle for height
    int i, j;
    
    for (i = 0; i < sphere.n1; i++) {      // Width
        for (j = 0; j < sphere.n2; j++) { // Height;
            sphere.vrtx[(i * sphere.n2) + j].x = radius * cos(i * theta) * sin(j * phi);
            sphere.vrtx[(i * sphere.n2) + j].y = radius * sin(i * theta) * sin(j * phi);
            sphere.vrtx[(i * sphere.n2) + j].z = radius * cos(j * phi);
            //
            sphere.norm[(i * sphere.n2) + j].x = cos(i * theta) * sin(j * phi);
            sphere.norm[(i * sphere.n2) + j].y = sin(i * theta) * sin(j * phi);
            sphere.norm[(i * sphere.n2) + j].z = cos(j * phi);
        }
    } 
    
    sphere.draw_faces = draw_faces_sphere;
    sphere.draw_points = draw_points_sphere;
}