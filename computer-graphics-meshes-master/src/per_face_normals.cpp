#include "per_face_normals.h"
#include "triangle_area_normal.h"

void per_face_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code:
  N = Eigen::MatrixXd::Zero(F.rows(),3);
  for (int i = 0; i < F.rows(); i++) {
    Eigen::RowVector3d vertex_a = V.row(F(i, 0));
    Eigen::RowVector3d vertex_b = V.row(F(i, 1));
    Eigen::RowVector3d vertex_c = V.row(F(i, 2));
    N.row(i) = triangle_area_normal(vertex_a, vertex_b, vertex_c).normalized();
  }
  ////////////////////////////////////////////////////////////////////////////
}
