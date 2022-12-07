#ifndef __DISPLAY__
#define __DISPLAY__

#include "../structure/Tree.h"

/********************************************************************************************************************/
/* Function   -> checks all parameters are positive or null, otherwise the color "G3Xcolor" is considered as null. */
/* Parameters -> color "G3Xcolor".                                                                                */
/* Return     -> nothing.                                                                                        */
/****************************************************************************************************************/
int color_is_null(G3Xcolor color);

/********************************************************************************************************************/
/* Function   -> checks all parameters are positive or null, otherwise the color "Material" is considered as null. */
/* Parameters -> material "Material".                                                                             */
/* Return     -> nothing.                                                                                        */
/****************************************************************************************************************/
int material_is_null(Material material);

/****************************************************************************************************************************/
/* Function   -> checks all parameters are positive or null, otherwise the scale factor "G3Xvector" is considered as null. */
/* Parameters -> scale factor "G3Xvector".                                                                                */
/* Return     -> nothing.                                                                                                */
/************************************************************************************************************************/
int scale_is_null(G3Xvector scale_factor);

/*************************************************************/
/* Function   -> adaptaion of values avoiding the negative. */
/* Parameters -> scale factor "G3Xvector".                 */
/* Return     -> the new scale_factor "G3Xvector".        */
/*********************************************************/
G3Xvector scale_adaptation(G3Xvector scale_factor);

/**********************************************************************************************************/
/* Function   -> calcul distance between an object and the camera. the result is divided by 2 at the end */
/* Parameters -> three "double", representing the 3 coordinates of the object.                          */
/* Return     -> the result with "double" type.                                                        */
/******************************************************************************************************/
double step_calcul(double x, double y, double z);

/*****************************************************************************************************************************/
/* Function   -> recursively traverse the tree "SceneTree" given in parameter.                                              */
/*               apply colors, matrices and materials before calling the display function of the object if it ever exists. */
/* Parameters -> tree "SceneTree" to display.                                                                             */
/* Return     -> nothing.                                                                                                */
/************************************************************************************************************************/
void display_tree_recursif(SceneTree node, G3Xhmat matrice, G3Xcolor color, Material material, G3Xvector scale_factor,  unsigned int flag);

/**********************************************************************************************/
/* Function   -> call the actual display function and set it correctly for a "face" display. */
/* Parameters -> node "SceneTree" to display.                                               */
/* Return     -> nothing.                                                                  */
/******************************************************************************************/
void display_tree_faces(SceneTree node); 

/***********************************************************************************************/
/* Function   -> call the actual display function and set it correctly for a "point" display. */
/* Parameters -> node "SceneTree" to display.                                                */
/* Return     -> nothing.                                                                   */
/*******************************************************************************************/
void display_tree_points(SceneTree node);

#endif