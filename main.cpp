#include "Matrix.h"

int size = 10;

int main() {

  Matrix m(size, size);
  Matrix result(size, size);
  m.SetMatrix();
  std::cout << "Sum of rows and columns: " << std::endl;
  m.SumOfRowsCols();

  std::cout << std::endl;

  result = m.transpose();
  std::cout<<"Transposed matrix: "<< std::endl;
  result.GetMatrix();

  std::cout << std::endl;

  Matrix m2(size, size);
  m2.SetMatrix();
  auto addition = (m + m2);
  auto substruction = (m - m2);
  auto multiplication = (m * m2);

  return 0;
}