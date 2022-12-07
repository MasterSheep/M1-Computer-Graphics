#include "../../include/shape/Cylinder.h"

void draw_faces_cylinder (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j, k;

    // Construction with square-shaped faces
    glBegin(GL_QUADS);
    for (i = 0; i < cylinder.n1; i += step_theta) {              // Width of the cylinder
        i_min = min(i + step_theta, cylinder.n1) % cylinder.n1; //
        for (j = 0; j < cylinder.n2; j += step_phi) {          // Height of the cylinder 
            j_min = min(j + step_phi, cylinder.n2 - 1);
            // South-East
            g3x_Normal3dv(shape->norm[i * cylinder.n2 + j_min]);
            g3x_Vertex3dv(shape->vrtx[i * cylinder.n2 + j_min]);
            // North-East
            g3x_Normal3dv(shape->norm[i_min * cylinder.n2 + j_min]);
            g3x_Vertex3dv(shape->vrtx[i_min * cylinder.n2 + j_min]);
            // North-West
            g3x_Normal3dv(shape->norm[i_min * cylinder.n2 + j]);
            g3x_Vertex3dv(shape->vrtx[i_min * cylinder.n2 + j]);
            // South-West
            g3x_Normal3dv(shape->norm[i * cylinder.n2 + j]);
            g3x_Vertex3dv(shape->vrtx[i * cylinder.n2 + j]);
        }

        for (j = 0; j < cylinder.n3; j += step_theta) {    // Width of the circles
            j_min = min(j + step_theta, cylinder.n3 - 1); //
            for (k = 0; k < 2; k ++) {                   // Up and Down circle
                // South-East
                g3x_Normal3dv(shape->norm[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i * cylinder.n3 + j_min]);
                g3x_Vertex3dv(shape->vrtx[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i * cylinder.n3 + j_min]);
                // North-East
                g3x_Normal3dv(shape->norm[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i_min * cylinder.n3 + j_min]);
                g3x_Vertex3dv(shape->vrtx[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i_min * cylinder.n3 + j_min]);
                // North-West
                g3x_Normal3dv(shape->norm[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i_min * cylinder.n3 + j]);
                g3x_Vertex3dv(shape->vrtx[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i_min * cylinder.n3 + j]);
                // South-West
                g3x_Normal3dv(shape->norm[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i * cylinder.n3 + j]);
                g3x_Vertex3dv(shape->vrtx[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i * cylinder.n3 + j]);
            }
        }
    }
    glEnd();
}

void draw_points_cylinder (struct _shape_* shape, G3Xvector scale_factor, double dcam) {
    int step_theta = MAX(1, (int) sqrt(pow(1 / scale_factor.x, 2) + pow(1 / scale_factor.y, 2))) * dcam;
    int step_phi   = MAX(1, (int) M_PI / (4 * scale_factor.z) + 1) * dcam;
    int i_min, j_min, i, j, k;

    // Construction with points
    glBegin(GL_POINTS);
    for (i = -step_theta; i < cylinder.n1; i += step_theta) {    // Width of the cylinder
        i_min = min(i + step_theta, cylinder.n1) % cylinder.n1; //
        for (j = -step_phi; j < cylinder.n2; j += step_phi) {  // Height of the cylinder 
            j_min = min(j + step_phi, cylinder.n2 - 1);
            g3x_Normal3dv(shape->norm[i_min * cylinder.n2 + j_min]);
            g3x_Vertex3dv(shape->vrtx[i_min * cylinder.n2 + j_min]);
        }
        for (j = -step_theta; j < cylinder.n3; j += step_theta) { // Width of the circles
            j_min = min(j + step_theta, cylinder.n3 - 1);        //
            for (k = 0; k < 2; k ++) {                          // Up and Down circle
                g3x_Normal3dv(shape->norm[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i_min * cylinder.n3 + j_min]);
                g3x_Vertex3dv(shape->vrtx[k * cylinder.n1 * cylinder.n3 + (cylinder.n1 * cylinder.n2) + i_min * cylinder.n3 + j_min]);
            }
        }
    }
    glEnd();
}

void draw_initialisation_cylinder (void) {
    cylinder.n1 = NBM;
    cylinder.n2 = NBP;
    cylinder.n3 = NBC;
    cylinder.vrtx = (G3Xpoint *) malloc(cylinder.n1 * (cylinder.n2 + 2 * cylinder.n3) * sizeof(G3Xpoint));
    cylinder.norm = (G3Xpoint *) malloc(cylinder.n1 * (cylinder.n2 + 2 * cylinder.n3) * sizeof(G3Xpoint));

    double height = 2.;                         // Cylinder height
    double radius = 1.;                         // Cylinder radius
    double theta  = 2 * M_PI / cylinder.n1;     // Angle
    double t      = height / (cylinder.n2 - 1); // Height division
    double r      = radius / (cylinder.n3 - 1); // Radius division
    int i, j, k;
    
    for (i = 0; i < cylinder.n1; i++) {      // Width of the cylinder 
        for (j = 0; j < cylinder.n2; j++) { // Height of the cylinder 
            cylinder.vrtx[cylinder.n2 * i + j].x = radius * cos(i * theta);
            cylinder.vrtx[cylinder.n2 * i + j].y = radius * sin(i * theta);
            cylinder.vrtx[cylinder.n2 * i + j].z = (j * t) - (height / 2.);
            //
            cylinder.norm[cylinder.n2 * i + j].x = cos(i * theta);
            cylinder.norm[cylinder.n2 * i + j].y = sin(i * theta);
            cylinder.norm[cylinder.n2 * i + j].z = 0;
        }

        for (j = 0; j < cylinder.n3; j++) { // Width of the circles
            for (k = 0; k < 2; k++) {      // Up and Down circle
                cylinder.vrtx[k * cylinder.n1 * cylinder.n3 + cylinder.n1 * cylinder.n2 + i * cylinder.n3 + j].x = (j * r) * cos(i * theta);
                cylinder.vrtx[k * cylinder.n1 * cylinder.n3 + cylinder.n1 * cylinder.n2 + i * cylinder.n3 + j].y = (j * r) * sin(i * theta);
                cylinder.vrtx[k * cylinder.n1 * cylinder.n3 + cylinder.n1 * cylinder.n2 + i * cylinder.n3 + j].z = (height / 2.) * (-1 + (2 * k));
                //
                cylinder.norm[k * cylinder.n1 * cylinder.n3 + cylinder.n1 * cylinder.n2 + i * cylinder.n3 + j].x = 0;
                cylinder.norm[k * cylinder.n1 * cylinder.n3 + cylinder.n1 * cylinder.n2 + i * cylinder.n3 + j].y = 0;
                cylinder.norm[k * cylinder.n1 * cylinder.n3 + cylinder.n1 * cylinder.n2 + i * cylinder.n3 + j].z = 1. * (-1 + (2 * k));
            }
        }
    }

    cylinder.draw_faces = draw_faces_cylinder;
    cylinder.draw_points = draw_points_cylinder;
}