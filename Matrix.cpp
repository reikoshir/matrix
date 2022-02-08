#include "Matrix.h"
#include "Timer.h"


Matrix::Matrix(int cols, int rows): m(cols), n(rows)
{
  rowsArray = new int[n];
  for (int i = 0; i < n; i++)
  {
    rowsArray[i] = 0;
  }
  matrix = new int* [m];
  for (int i = 0; i < m; i++)
  {
    matrix[i] = new int[n]();
  }
};


Matrix::~Matrix() 
{
    delete[] matrix;
    delete[] rowsArray;
};

void Matrix::SetMatrix()
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[i][j] = rand() % 10;
    }
  }
};

void Matrix::GetMatrix()
{
  Timer timer(__FUNCTION__);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << matrix[i][j] << "  ";
     

    }
    std::cout << std::endl;
  }
};

void Matrix::SumOfRowsCols()
{
  Timer timer(__FUNCTION__);
  int sumRow = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << matrix[i][j] << "  ";
      sumRow += matrix[i][j];
      rowsArray[j] += matrix[i][j];
    }
    std::cout << "| " << sumRow << std::endl;
    sumRow = 0;
  }

  for (int i = 0; i < n; i++)
    std::cout << "-- ";
  std::cout << std::endl;
  for (int i = 0; i < n; i++)
    std::cout << rowsArray[i] << " ";
    std::cout<<std::endl;
}

Matrix Matrix::operator+(Matrix &param)
{
  Timer timer(__FUNCTION__);
  Matrix temp(m, n);
  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n;j++)
    {
      temp.matrix[i][j] = param.matrix[i][j] + matrix[i][j];
    }
  }
  return temp;
}

Matrix &Matrix::operator=(Matrix other)
{
  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n;j++)
    {
      matrix[i][j] = other.matrix[i][j];
     }
    }
    return *this;
}

Matrix Matrix::operator-(Matrix &param)
{
  Timer timer(__FUNCTION__);
  Matrix temp(m,n);
  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n;j++)
    {

      temp.matrix[i][j] = matrix[i][j] - param.matrix[i][j];
    }
  }
  return temp;
}

Matrix Matrix::operator*(Matrix &param)
{
  Timer timer(__FUNCTION__);
  Matrix temp(m,n);
  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n;j++)
    {
      temp.matrix[i][j] = 0;
    for(int k = 0; k<n; k++)
      temp.matrix[i][j]+=matrix[i][k]*param.matrix[k][j];
    }
  }
  return temp;
}

Matrix Matrix::transpose()
{
  Timer timer(__FUNCTION__);
  Matrix temp(n,m);
  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n;j++)
    {
      temp.matrix[j][i] = matrix[i][j];
    }
  }
    return temp;
}