#define _USE_MATH_DEFINES
#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::vector<std::vector<int>> adjacents;
  vertex_triangle_adjacency(F, V.rows(), adjacents);
  
  for (int i = 0; i < F.rows(); i++) {
    Eigen::RowVector3d normal(0, 0, 0);
    normal = triangle_area_normal(V.row(F(i, 0)), V.row(F(i, 1)), V.row(F(i, 2))).normalized();
    for (int j = 0; j < F.cols(); j++) {
      Eigen::RowVector3d comp_normal(0,0,0);
      std::vector<int> face_index = adjacents[F(i, j)];
      for (int k: face_index) {
        Eigen::RowVector3d temp(0, 0, 0);
        temp = triangle_area_normal(V.row(F(k, 0)), V.row(F(k, 1)), V.row(F(k, 2))).normalized();
        if (normal.dot(temp) > cos((M_PI * corner_threshold) / 180)) {
          comp_normal = comp_normal + temp;
        }
      }
      N.row(i * 3 + j) = comp_normal.normalized();
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
