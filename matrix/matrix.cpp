#include "matrix.hpp"

Matrix::Matrix()
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  prc = nullptr;
}

Matrix::Matrix(int col)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  wakeMeUp(col, col);
}

Matrix::Matrix(int row, int col)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  wakeMeUp(row, col);
}

Matrix::Matrix(Matrix& copy)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  this->prc = copy.prc;
  if(prc == nullptr) return;
  ++prc->n;
}

void Matrix::wakeMeUp(int row, int col)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(row < 1 || col < 1) throw Autism();
  prc = new rc(row, col);
  for(int i = 0; i < row; ++i)
  {
    for(int j = 0; j < col; ++j)
    {
      prc->matrixPointer[i][j] = 0;
    }
  }
}


double Matrix::operator()(int row, int col) const
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc == nullptr) throw OUTOFSCOPE();
  if(row < 0 || col < 0 || this->prc->rows < row || this->prc->cols < col) throw OUTOFSCOPE();

  return this->prc->matrixPointer[row][col];
}

Matrix Matrix::operator+(const Matrix& right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc->rows != right.prc->rows || prc->cols != right.prc->cols) throw iCannotDoThatSir();
  Matrix temp(this->prc->cols, this->prc->rows);
  for(int row = 0; row < this->prc->rows; ++row)
    for(int col = 0; col < this->prc->cols; ++col)
      temp(row, col) = (*this)(row, col) + right(row, col);

  return temp;
}

Matrix & Matrix::operator+=(const Matrix &right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc->rows != right.prc->rows || prc->cols != right.prc->cols) throw iCannotDoThatSir();
  *this = *this + right;

  return *this;
}

Matrix Matrix::operator-(const Matrix& right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc->rows != right.prc->rows || prc->cols != right.prc->cols) throw iCannotDoThatSir();
  Matrix temp(this->prc->cols, this->prc->rows);
  for(int row = 0; row < this->prc->rows; ++row)
    for(int col = 0; col < this->prc->cols; ++col)
      temp(row, col) = (*this)(row, col) - right(row, col);

  return temp;
}

Matrix& Matrix::operator-=(const Matrix& right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc->rows != right.prc->rows || prc->cols != right.prc->cols) throw iCannotDoThatSir();
  *this = *this - right;

  return *this;
}

Matrix Matrix::operator*(const Matrix& right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc->rows != right.prc->rows || prc->cols != right.prc->cols) throw iCannotDoThatSir();
  Matrix temp(this->prc->cols, this->prc->rows);
  for(int row = 0; row < this->prc->rows; ++row)
    for(int col = 0; col < this->prc->cols; ++col)
      temp(row, col) = multiply(right, row, col);

  return temp;
}

double Matrix::multiply(const Matrix& right, int row, int col)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  double mul = 0;
  for(int _i = 0; _i < prc->rows; ++_i)
    mul += (*this)(row, _i) * right(_i, col);

  return mul;
}

Matrix& Matrix::operator*=(const Matrix &right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  (*this) = (*this) * right;

  return (*this);
}

Matrix& Matrix::operator=(const Matrix& right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(this->prc == right.prc)
    return *this;
  DelMatrix();
  this->prc = right.prc;
  ++this->prc->n;

  return *this;
}

Matrix& Matrix::transpose() const
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  Matrix temp(prc->rows, prc->cols);
  for(int i = 0; i < prc->rows; ++i)
  {
    for(int j = 0; j < prc->cols; ++j)
    {
      temp(i, j) = prc->matrixPointer[i][j];
    }
  }
}

Matrix::el Matrix::operator()(int row, int col)
{//mat(1,3);
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc == nullptr)
    throw Autism();
  if(row < 0 || col < 0 || this->prc->rows < row || this->prc->cols < col) throw OUTOFSCOPE();

  return el(this, row, col);
}

void Matrix::detach(double val, int el_row, int el_col)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  rc *NewOne = nullptr;
  if(prc != nullptr)
  {
    NewOne = new rc(prc);
    --prc->n;
    NewOne->matrixPointer[el_row][el_col] = val;
  }
  prc = NewOne;
}

int Matrix::getSizeY() const
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  return this->prc->rows;
}

int Matrix::getSizeX() const
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  return this->prc->cols;
}

int Matrix::getRC() const
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  return this->prc->n;
}

bool Matrix::empty() const
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  return !this->prc;
}

Matrix::~Matrix()
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  DelMatrix();
}

void Matrix::DelMatrix()
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(prc == nullptr) return;
  if(prc->n-- != 1) return;
  delete prc;
  prc = nullptr;
}

Matrix::rc::rc(int row, int col)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  matrixPointer = new double*[row];
  for(int _i = 0; _i < row; ++_i)
  {
    matrixPointer[_i] = new double[col];
  }
  n = 1;
  this->cols = col;
  this->rows = row;
}

Matrix::rc::rc(rc* OldOne)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  cols = OldOne->cols;
  rows = OldOne->rows;
  n = 1;

  matrixPointer = new double*[rows];
  for(int _i = 0; _i < rows; ++_i)
  {
    matrixPointer[_i] = new double[cols];
    std::copy(OldOne->matrixPointer[_i], OldOne->matrixPointer[_i] + cols, matrixPointer[_i]);
  }
}

Matrix::rc::~rc()
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  for(int _i = 0; _i < rows; ++_i)
    delete [] matrixPointer[_i];
  delete [] matrixPointer;
  //std::cout << "HAHA\n";
}


Matrix::el::el(Matrix* matrix, int r, int c): el_row(r), el_col(c), parrent(matrix)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  elementPointer = &matrix->prc->matrixPointer[r][c];
}

Matrix::el::operator double() //domyslnie uzywany jak kompilator ma wątpliwości co do typu
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  return *elementPointer;  //referencja do dabubla
}

Matrix::el& Matrix::el::operator=(double right)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(parrent->prc->n != 1)
  {
    parrent->detach(right, el_row, el_col);
  }
  else
  {
    *elementPointer = right;
  }

  return *this;
}


std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  if(matrix.empty())
    return output << "NULLMATRIX\n";

  for(int _rows = 0; _rows < matrix.getSizeY(); ++_rows)
  {
    for(int _cols = 0; _cols < matrix.getSizeX(); ++_cols)
    {
      output << matrix(_rows, _cols);
      std::cout << "  ";
    }
    std::cout << std::endl;
  }
  return output;
}

std::ifstream& operator>>(std::ifstream& input, Matrix& matrix)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  int in_rows, in_cols;
  std::string line;
  std::getline(input, line);
  std::stringstream dim(line);
  dim >> in_rows;
  dim >> in_cols;

  if(!dim.eof()) throw inputError();

  matrix = Matrix(in_rows, in_cols);
  for(int i = 0; i < in_rows; ++i)
  {
    line = "";
    std::getline(input, line);
    std::stringstream _rows(line);
    try
    {
      matrix.processInput(_rows, i);
    }
    catch(inputError&)
    {
      matrix.DelMatrix();
      throw;
    }
  }

  line = "";
  std::getline(input, line);
  if(line.size() != 0) throw inputError();

  return input;
}

void Matrix::processInput(std::stringstream& input, int i)
{
  if(__DEBUG__) std::cout << "++DEBUG++     " << __PRETTY_FUNCTION__ << std::endl;

  for(int j = 0; j < prc->cols; ++j)
  {
    double temp;
    input >> temp;
    if(input.fail()) throw inputError();
    prc->matrixPointer[i][j] = temp;
  }
  if(!input.eof()) throw inputError();
}
