#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  //Construct the quad mesh of a cube including parameterization and per-face normals.
  //Hint: Draw out on paper and label with indices the 3D cube, the 2D parameterized cube,
  //and the normals.
  //   V  8 by 3 list of 3D corner vertex positions
  //   F  6 by 4 list of quad face indices into rows of V
  //   UV  14 by 2 list of corner parameterization positions
  //   UF  6 by 4 list of quad face indices into rows of UV
  //   NV  6 by 3 list of 3D unit normal vectors
  //   NF  6 by 4 list of quad face indices into rows of NV
  ////////////////////////////////////////////////////////////////////////////

  ////Hint:
  V.resize(8,3);
  F.resize(6,4);
  UV.resize(14,2);
  UF.resize(6,4);
  NV.resize(6,3);
  NF.resize(6,4);

  //comma initializer
  /*
  V << 0, 0, 0, //Left Front Bottom
    1, 0, 0, //Right Front Bottom
    1, 1, 0, //Right Back Bottom
    0, 1, 0, //Left Back Bottom
    0, 0, 1, //Left Front Top
    1, 0, 1, //Right Front Top
    1, 1, 1, //Right Back Top
    0, 1, 1; //Left Back Top

  F << 0, 1, 2, 3, //BOTTOM
    4, 5, 6, 7, //TOP
    0, 1, 5, 4, //FRONT
    1, 2, 6, 5, //RIGHT
    2, 3, 7, 6, //BACK
    3, 0, 4, 7; //LEFT

  UV << 0.25, 0.0,
    0.5, 0.0,
    0.0, 0.25,
    0.25, 0.25,
    0.5, 0.25,
    0.75, 0.25,
    1.0, 0.25,
    0.0, 0.5,
    0.25, 0.5,
    0.5, 0.5,
    0.75, 0.5,
    1.0, 0.5,
    0.25, 0.75,
    0.5, 0.75;

  UF << 0, 3, 4, 1, //bottom
    2, 7, 8, 3, // left
    3, 8, 9, 4, //front
    4, 9, 10, 5, // right
    5, 10, 11, 6, //behind
    9, 12, 13, 9; //top

  NV << -1, 0, 0,
    0, -1, 0,
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
    0, 0, -1;

  NF << 0, 0, 0, 0,
    1, 1, 1, 1,
    2, 2, 2, 2,
    3, 3, 3, 3,
    4, 4, 4, 4,
    5, 5, 5, 5;*/
  V << 0, 0, 0,
    0, 1, 0,
    1, 1, 0,
    1, 0, 0,
    0, 0, 1,
    0, 1, 1,
    1, 1, 1,
    1, 0, 1;

  F << 0, 1, 2, 3,
    0, 4, 5, 1,
    1, 5, 6, 2,
    2, 6, 7, 3,
    0, 3, 7, 4,
    4, 7, 6, 5;

  UV << 0, 0.25,
    0.25, 0.25,
    0.25, 0.5,
    0, 0.5,
    0.5, 0.25,
    0.5, 0.5,
    0.5, 0.75,
    0.25, 0.75,
    0.25, 0,
    0.5, 0,
    0.75, 0.5,
    0.75, 0.25,
    1, 0.25,
    1, 0.5;

  UF << 1, 8, 9, 4,
    1, 2, 3, 0,
    12, 13, 10, 11,
    11, 10, 5, 4,
    1, 4, 5, 2,
    2, 5, 6, 7;

  NV << 0, 0, -1,
    -1, 0, 0,
    0, 1, 0,
    1, 0, 0,
    0, -1, 0,
    0, 0, 1;

  NF << 0, 0, 0, 0,
    1, 1, 1, 1,
    2, 2, 2, 2,
    3, 3, 3, 3,
    4, 4, 4, 4,
    5, 5, 5, 5;
}
