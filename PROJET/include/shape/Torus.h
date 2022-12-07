#include "../structure/Shape.h"

/**************************************************************************************/
/* Function   -> display a "torus" shape with only square faces.                     */
/* Parameters -> shape "Shape", scale factor "G3Xvector", camera distance "double". */
/* Return     -> nothing.                                                          */
/**********************************************************************************/
void draw_faces_torus(struct _shape_* shape, G3Xvector scale_factor, double dcam);

/**************************************************************************************/
/* Function   -> display a "torus" shape with only pointes.                          */
/* Parameters -> shape "Shape", scale factor "G3Xvector", camera distance "double". */
/* Return     -> nothing.                                                          */
/**********************************************************************************/
void draw_points_torus(struct _shape_* shape, G3Xvector scale_factor, double dcam);

/****************************************************************************/
/* Function   -> initialize all parameters of the "torus" shape reference. */
/* Parameters -> nothing.                                                 */
/* Return     -> nothing.                                                */
/************************************************************************/
void draw_initialisation_torus(void);