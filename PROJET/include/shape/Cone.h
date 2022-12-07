#include "../structure/Shape.h"

/**************************************************************************************/
/* Function   -> display a "cone" shape with only square faces.                      */
/* Parameters -> shape "Shape", scale factor "G3Xvector", camera distance "double". */
/* Return     -> nothing.                                                          */
/**********************************************************************************/
void draw_faces_cone (struct _shape_* shape, G3Xvector scale_factor, double dcam);

/**************************************************************************************/
/* Function   -> display a "cone" shape with only pointes.                           */
/* Parameters -> shape "Shape", scale factor "G3Xvector", camera distance "double". */
/* Return     -> nothing.                                                          */
/**********************************************************************************/
void draw_points_cone (struct _shape_* shape, G3Xvector scale_factor, double dcam);

/***************************************************************************/
/* Function   -> initialize all parameters of the "cone" shape reference. */
/* Parameters -> nothing.                                                */
/* Return     -> nothing.                                               */
/***********************************************************************/
void draw_initialisation_cone(void);