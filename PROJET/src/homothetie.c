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
static G3Xcolor rouge   = {1.0, 0.0, 0.0, 1.0};
static G3Xcolor jaune   = {1.0, 1.0, 0.0, 1.0};
static G3Xcolor vert    = {0.0, 1.0, 0.0, 1.0};
static G3Xcolor cyan    = {0.0, 1.0, 1.0, 1.0};
static G3Xcolor bleu    = {0.0, 0.0, 1.0, 1.0};
static G3Xcolor magenta = {1.0, 0.0, 1.0, 1.0};

/* */
static bool FLAG_FACES = true;

/* */
static SceneTree scene;

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
  scene = creat_node_property(g3x_Identity(), cyan, creat_material(ambi, diff, spec, shin), creat_g3xvector(1., 1., 1.));
  
  SceneTree feuille1 = creat_node_shape(&cube);
  add_matrix(feuille1, g3x_Translation3d(-0.5, -0.5, 0.));
  add_child(scene, feuille1);

  SceneTree feuille2 = creat_node_shape(&cube);
  add_color(feuille2, rouge);
  add_matrix(feuille2, g3x_Translation3d(0., 1., -0.5));
  add_matrix(feuille2, g3x_Homothetie3d(0.5, 0.5, 0.5));
  add_child(scene, feuille2);

  SceneTree feuille3 = creat_node_shape(&cube);
  add_color(feuille3, magenta);
  add_matrix(feuille3, g3x_Translation3d(1.25, -0.25, -0.25));
  add_matrix(feuille3, g3x_Homothetie3d(0.75, 0.75, 0.75));
  add_child(scene, feuille3);

  SceneTree feuille4 = creat_node_shape(&cube);
  add_color(feuille4, vert);
  add_matrix(feuille4, g3x_Translation3d(0.75, 0.75, -0.75));
  add_matrix(feuille4, g3x_Homothetie3d(0.25, 0.25, 0.25));
  add_child(scene, feuille4);

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
