#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::ofstream myfile;
  myfile.open(filename);
  if (myfile.fail()) {
    std::cout << "Opening the file failed";
    return false;
  }

  myfile << "# List of geometric vertices\n";
  for (int i = 0; i < V.rows(); i++) {
    myfile << "v ";
    myfile << V(i, 0) << " " << V(i, 1) << " " << V(i, 2) << "\n";
  }

  myfile << "# List of texture coordinates\n";
  for (int i = 0; i < UV.rows(); i++) {
    myfile << "vt ";
    myfile << UV(i, 0) << " " << UV(i, 1) << "\n";
  }

  myfile << "# List of vertex normals in (x,y,z) form\n";
  for (int i = 0; i < NV.rows(); i++) {
    myfile << "vn ";
    myfile << NV(i, 0) << " " << NV(i, 1) << " " << NV(i, 2) << "\n";
  }

  myfile << "# Polygonal face element\n";
  for (int i = 0; i < F.rows(); i++) {
    myfile << "f ";
    for (int j = 0; j < F.cols(); j++) {
      myfile << F(i, j) + 1 << "/" << UF(i, j) + 1 << "/" << NF(i, j) + 1 << " ";
    }
    myfile << "\n";
  }

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
