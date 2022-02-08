#include <ctime>
#include <iostream>

class Matrix
{
private:
  int** matrix;
  int* rowsArray;
  int m;
  int n;
public:
  Matrix(int cols, int rows);
  ~Matrix();
  void GetMatrix(); 
  void SetMatrix();  
  void SumOfRowsCols();
  Matrix operator+(Matrix &other);
  Matrix operator-(Matrix &other);
  Matrix operator*(Matrix &other);
  Matrix &operator=(Matrix other);
  Matrix transpose();
};

