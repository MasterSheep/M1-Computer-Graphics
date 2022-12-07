#ifndef __SHAPE__
#define __SHAPE__

#include <g3x.h>

#define NBM 128   // Number of meridians (vertical lines)
#define NBP 128  // Number of parallels (horizontal lines)
#define NBC 64  // Number of circles on bases

/**************************************************************************/
/* Struct -> represents an geometric shape, with it's points and display */
/************************************************************************/
typedef struct _shape_ {
    int n1,n2,n3; // Max sample values
    G3Xpoint *vrtx; // Array of vertex
    G3Xvector *norm; // Array of normals
    /* Display method */
    void (*draw_points)(struct _shape_*, G3Xvector scale_factor, double dcam); // GL_POINTS mode
    void (*draw_faces )(struct _shape_*, G3Xvector scale_factor, double dcam); // GL_QUADS mode
} Shape;

extern Shape sphere, cube, cylinder, torus, cone; // 5 basic object

/*********************************************************************************/
/* Function   -> returns the minimum parameter value and converts it to an int. */
/* Parameters -> two "double" variable.                                        */
/* Return     -> the minimum with "int" type.                                 */
/*****************************************************************************/
int min(double a, double b);

#endif