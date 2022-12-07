#ifndef __TREE__
#define __TREE__

#include "../structure/Shape.h"

/********************************************************************************************/
/* Struct -> represents a material dedicated to a geometric shape used by openGL functions */
/******************************************************************************************/
typedef struct _material_ {
    double ambi;
    double diff;
    double spec;
    double shine;
} Material;

/*************************************************/
/* Struct -> represents a node for a scene tree */
/***********************************************/
typedef struct _node_ {
    struct _node_ *down,*next;  // Chaining 
    G3Xhmat Md;                // Direct transformation matrix
    G3Xcolor col;             // RGBA color 
    Material mat;            // 4 double between [0,1]
    G3Xvector scale_factor; // Local scale factors in x,y,z
    Shape *instance;       // Possible object instance
} Node, *SceneTree;


/*******************************************************************************************/
/* Function   -> create a "Material" object, set it with the parameters before return it. */
/* Parameters -> four "double" variable, for all parameters of the "Material" struct.    */
/* Return     -> new "Material" object.                                                 */
/***************************************************************************************/
Material creat_material(double ambin, double diff, double spec, double shine);

/********************************************************************************************/
/* Function   -> create a "G3Xvector" object, set it with the parameters before return it. */
/* Parameters -> three "double" variable, for all parameters of the "G3Xvector" struct.   */
/* Return     -> new "G3Xvector" object.                                                 */
/****************************************************************************************/
G3Xvector creat_g3xvector(double x, double y, double z);

/**************************************************************************************************/
/* Function   -> create a "G3Xcolor" object, set it with the parameters before before return it. */
/* Parameters -> four "double" variable, for all parameters of the "G3Xcolor" struct.           */
/* Return     -> new "G3Xcolor" object.                                                        */
/**********************************************************************************************/
G3Xcolor creat_color(double r, double g, double b, double a);

/**********************************************************************************/
/* Function   -> create a "SceneTree" object, NULL all pointer before return it. */
/* Parameters -> nothing.                                                       */
/* Return     -> new "SceneTree" object.                                       */
/******************************************************************************/
SceneTree node_allocation(void);

/**************************************************************************/
/* Function   -> create a "SceneTree" object, set nothing and return it. */
/* Parameters -> pointer of a "Shape".                                  */
/* Return     -> new "SceneTree" object.                               */
/**********************************************************************/
SceneTree creat_node_empty(void);

/************************************************************************************/
/* Function   -> create a "SceneTree" object, set only the shape before return it. */
/* Parameters -> pointer of a "Shape".                                            */
/* Return     -> new "SceneTree" object.                                         */
/********************************************************************************/
SceneTree creat_node_shape(Shape *instance);

/*******************************************************************************************************************************/
/* Function   -> create a "SceneTree" object, set everything except the shape and the links oh the newt nodes (chained list). */
/* Parameters -> matrix "G3Xhmat", color "G3Xcolor", material "Material" and scale factor "G3Xvector".                       */
/* Return     -> new "SceneTree" object.                                                                                    */
/***************************************************************************************************************************/
SceneTree creat_node_property(G3Xhmat Md, G3Xcolor col, Material mat, G3Xvector scale_factor);

/**********************************************************************************************************/
/* Function   -> create a "SceneTree" object, set everything the links of the next nodes (chained list). */
/* Parameters -> matrix "G3Xhmat", color "G3Xcolor", material "Material" and scale factor "G3Xvector".  */
/* Return     -> new "SceneTree" object.                                                               */
/******************************************************************************************************/
SceneTree creat_node(Shape *instance, G3Xhmat Md, G3Xcolor col, Material mat, G3Xvector scale_factor);

/****************************************************************************/
/* Function   -> add a matrix "G3Xhmat" at a node of a "SceneTree" object. */
/* Parameters -> node "SceneTree" and matrix "G3Xhmat".                   */
/* Return     -> nothing.                                                */
/************************************************************************/
void add_matrix(Node * node, G3Xhmat Md);

/*****************************************************************************/
/* Function   -> add a matrix "G3Xcolor" at a node of a "SceneTree" object. */
/* Parameters -> node "SceneTree" and color "G3Xcolor".                    */
/* Return     -> nothing.                                                 */
/*************************************************************************/
void add_color(Node * node, G3Xcolor col);

/*****************************************************************************/
/* Function   -> add a matrix "Material" at a node of a "SceneTree" object. */
/* Parameters -> node "SceneTree" and material "Material".                 */
/* Return     -> nothing.                                                 */
/*************************************************************************/
void add_material(Node * node, Material mat);

/******************************************************************************/
/* Function   -> add a matrix "G3Xvector" at a node of a "SceneTree" object. */
/* Parameters -> node "SceneTree" and scale factor "G3Xvector".             */
/* Return     -> nothing.                                                  */
/**************************************************************************/
void add_scale_factor(Node * node, G3Xvector scale_factor);

/************************************************************************/
/* Function   -> add a lower node in the node of a "SceneTree" object. */
/* Parameters -> two node "SceneTree", parent -> child.               */
/* Return     -> nothing.                                            */
/********************************************************************/
void add_child(Node * parents, Node * child);

#endif