#include "../include/shape/Sphere.h"
#include "../include/shape/Torus.h"
#include "../include/shape/Cylinder.h"
#include "../include/shape/Cone.h"
#include "../include/shape/Cube.h"
#include "../include/structure/Display.h"

/* tailles de la fenêtre (en pixel) */
static int WWIDTH=512, WHEIGHT=512; 

/* paramètres de 'matière' des objets */
static double alpha = 0.5;
static double ambi  = 0.2;
static double diff  = 0.3;
static double spec  = 0.4;
static double shin  = 0.5;

/* des couleurs prédéfinies */
static G3Xcolor rouge   = {1.0, 0.0,  0.0, 1.0};
static G3Xcolor jaune   = {1.0, 1.0,  0.0, 1.0};
static G3Xcolor vert    = {0.0, 1.0,  0.0, 1.0};
static G3Xcolor cyan    = {0.0, 1.0,  1.0, 1.0};
static G3Xcolor bleu    = {0.0, 0.0,  1.0, 1.0};
static G3Xcolor magenta = {1.0, 0.0,  1.0, 1.0};
static G3Xcolor blanc   = {1.0, 1.0,  1.0, 1.0};
static G3Xcolor gris    = {0.5, 0.5,  0.5, 1.0};
static G3Xcolor marron  = {0.3, 0.15, 0.0, 1.0};

/* */
static bool FLAG_FACES = true;

/* */
static SceneTree scene;

SceneTree create_ground() {
  SceneTree sol = creat_node_empty();
  add_color(sol, blanc);
  add_matrix(sol, g3x_Translation3d(0., 0., -0.26));
  add_matrix(sol, g3x_Homothetie3d(2., 2., 0.01));
  add_scale_factor(sol, creat_g3xvector(0.5, 0.5, 1.));

  SceneTree NW = creat_node_shape(&cube);
  add_matrix(NW, g3x_Translation3d(-1., -1., 0.));
  add_child(sol, NW);

  SceneTree NE = creat_node_shape(&cube);
  add_color(NE, gris);
  add_matrix(NE, g3x_Translation3d(-1., 1., 0.));
  add_child(sol, NE);

  SceneTree SE = creat_node_shape(&cube);
  add_matrix(SE, g3x_Translation3d(1., 1., 0.));
  add_child(sol, SE);

  SceneTree SW = creat_node_shape(&cube);
  add_color(SW, gris);
  add_matrix(SW, g3x_Translation3d(1., -1., 0.));
  add_child(sol, SW);
  return sol;
}

SceneTree create_table_square() {
  SceneTree table = creat_node_empty();

  SceneTree block = creat_node_shape(&cube);
  add_color(block, marron);
  //add_scale_factor(table, creat_g3xvector(0.5, 0.5, 1.));
  add_matrix(block, g3x_Homothetie3d(1., 0.5, 0.1));
  add_child(table, block);

  SceneTree pieds = creat_node_empty();
  add_color(pieds, gris);
  add_matrix(pieds, g3x_Homothetie3d(0.1, 0.1, 0.60));
  add_matrix(pieds, g3x_Translation3d(0., 0., -1.1));
  add_child(table, pieds);

  SceneTree NW = creat_node_shape(&cube);
  add_matrix(NW, g3x_Translation3d(-8., -3., 0.));
  add_child(pieds, NW);

  SceneTree NE = creat_node_shape(&cube);
  add_matrix(NE, g3x_Translation3d(-8., 3., 0.));
  add_child(pieds, NE);

  SceneTree SE = creat_node_shape(&cube);
  add_matrix(SE, g3x_Translation3d(8., 3., 0.));
  add_child(pieds, SE);

  SceneTree SW = creat_node_shape(&cube);
  add_matrix(SW, g3x_Translation3d(8., -3., 0.));
  add_child(pieds, SW);
  return table;
}

SceneTree create_table_circle() {
  SceneTree table = creat_node_empty();

  SceneTree block = creat_node_shape(&cylinder);
  add_color(block, jaune);
  add_matrix(block, g3x_Homothetie3d(1.25, 1.25, 0.1));
  add_child(table, block);

  SceneTree pieds = creat_node_empty();
  add_color(pieds, gris);
  add_matrix(pieds, g3x_Homothetie3d(0.1, 0.1, 0.60));
  add_matrix(pieds, g3x_Translation3d(0., 0., -1.1));
  add_child(table, pieds);

  SceneTree NW = creat_node_shape(&cube);
  add_matrix(NW, g3x_Translation3d(-6., -6., 0.));
  add_child(pieds, NW);

  SceneTree NE = creat_node_shape(&cube);
  add_matrix(NE, g3x_Translation3d(-6., 6., 0.));
  add_child(pieds, NE);

  SceneTree SE = creat_node_shape(&cube);
  add_matrix(SE, g3x_Translation3d(6., 6., 0.));
  add_child(pieds, SE);

  SceneTree SW = creat_node_shape(&cube);
  add_matrix(SW, g3x_Translation3d(6., -6., 0.));
  add_child(pieds, SW);
  return table;
}

/* la fonction d'initialisation : appelée 1 seule fois, au début */
static void init(void)
{ 
  // Initialisation des formes
  draw_initialisation_sphere();
  draw_initialisation_torus();
  draw_initialisation_cylinder();
  draw_initialisation_cone();
  draw_initialisation_cube();
  //
  scene = creat_node_empty();
  add_material(scene, creat_material(ambi, diff, spec, shin));
  add_scale_factor(scene, creat_g3xvector(1., 1., 1.));
  //
  SceneTree sol = create_ground();
  add_child(scene, sol);
  //
  SceneTree pack = creat_node_empty();
  add_matrix(pack, g3x_Translation3d(-2., -1., 0.));
  add_child(scene, pack);

  SceneTree table = create_table_square();
  add_matrix(table, g3x_Translation3d(0., 0., 1.2));
  add_matrix(table, g3x_RotationZ(4.0));
  add_matrix(table, g3x_RotationX(3.1415));
  add_child(pack, table);

  SceneTree table2 = create_table_circle();
  add_matrix(table2, g3x_Translation3d(0., 0., 1.));
  add_child(pack, table2);
  //
  SceneTree table3 = create_table_square();
  add_matrix(table3, g3x_Translation3d(0., 2., 1.2));
  add_matrix(table3, g3x_RotationZ(5.0));
  add_child(scene, table3);

  SceneTree table4 = create_table_circle();
  add_matrix(table4, g3x_Translation3d(2., -2., 1.));
  add_child(scene, table4);

  //
  g3x_SetLightAmbient (1.,1.,1.);
  g3x_SetLightDiffuse (1.,1.,1.);
  g3x_SetLightSpecular(1.,1.,1.);
  g3x_SetLightPosition (3.,3.,3.);
}

/* la fonction de contrôle : appelée 1 seule fois, juste après <init> */
static void ctrl(void)
{
  /* des boutons 'switch' associés à une variable booléene (on/off) */
  g3x_CreateSwitch("Faces",&FLAG_FACES,"affiche les formes avec faces/points");
}

/* la fonction de dessin : appelée en boucle */
static void draw(void)
{
  if(FLAG_FACES)
    display_tree_faces(scene);
  else
    display_tree_points(scene);
}

/* la fonction d'animation (facultatif) */
static void anim(void)
{
  
}

/* la fonction de sortie  (facultatif) -- atexit() */
static void quit(void)
{
}

/***************************************/
/* La fonction principale :            */
/***************************************/
int main(int argc, char **argv)
{
  /* creation de la fenetre - titre et tailles (pixels) */
  g3x_InitWindow(*argv,WWIDTH,WHEIGHT);

  g3x_SetInitFunction(init); /* fonction d'initialisation */
  g3x_SetCtrlFunction(ctrl); /* fonction de contrôle      */
  g3x_SetDrawFunction(draw); /* fonction de dessin        */
  g3x_SetAnimFunction(anim); /* fonction d'animation      */
  g3x_SetExitFunction(quit); /* fonction de sortie        */

  /* lancement de la boucle principale */
  return g3x_MainStart();
}
