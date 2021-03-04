#define _USE_MATH_DEFINES
#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v, //latitude / horizontal
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  int num_vertices = (num_faces_u + 1) * (num_faces_v + 1);
  int num_faces = num_faces_u * num_faces_v;
  V.resize(num_vertices, 3);
  F.resize(num_faces, 4);
  UV.resize(num_vertices, 2);
  UF.resize(num_faces, 4);
  NV.resize(num_vertices, 3);
  NF.resize(num_faces, 4);
  //Every point on the surface of sphere is the same distance from the centre
  //set radius to 1
  
  double r = 1.0;
  double theta, phi, x, y, z;
  int k = 0;
  for (int i = 0; i < num_faces_u + 1; i++) {
    phi = M_PI / 2 - M_PI * i / num_faces_u;
    for (int j = 0; j < num_faces_v + 1; j++) {
      theta = 2 * M_PI * j / num_faces_v;
      x = -r * cos(phi) * cos(theta);
      y = -r * cos(phi) * sin(theta);
      z = -r * sin(phi);
      V.row(k) = Eigen::RowVector3d(x, y, z);
      NV.row(k) = Eigen::RowVector3d(x * 1.0 / r, y * 1.0 / r, z * 1.0 / r);
      UV.row(k) = Eigen::RowVector2d(double(j) / num_faces_v,
        double(i) / num_faces_u);
      k++;
    }
  }
  
  k = 0;
  for (int i = 0; i < num_faces_u; i++) {
    for (int j = 0; j < num_faces_v; j++) {
      int ver_a = i * (num_faces_v + 1) + j; //upper left
      int ver_b = ver_a + 1; //upper right
      int ver_d = ver_a + (num_faces_v + 1); //lower left
      int ver_c = ver_d + 1; //lower right
      F.row(k) = Eigen::RowVector4i(ver_a, ver_b, ver_c, ver_d);
      UF.row(k) = Eigen::RowVector4i(ver_a, ver_b, ver_c, ver_d);
      NF.row(k) = Eigen::RowVector4i(ver_a, ver_b, ver_c, ver_d);
      k++;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
