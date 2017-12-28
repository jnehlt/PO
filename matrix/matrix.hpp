#ifndef __MATRIX_H__
#define __MATRIX_H__
  #define __DEBUG__ 1

  #include <iostream>
  #include <fstream>
  #include <sstream>
  #include <algorithm>

  class OUTOFSCOPE {};  //nieprawidłowe indeksowanie
  class Autism {};
  class iCannotDoThatSir {};  //niekomptatybilne macierze
  class inputError {};  //błędny plik wejściowy

  class Matrix
  {
    struct rc
    {
      rc(int, int);
      rc(rc*);
      ~rc();

      int n, rows, cols;
      double** matrixPointer;
    };

    struct el
    {
      public:
        el(Matrix*, int, int);
        el& operator=(double);
        el& operator=(el&) = delete;
        operator double();
      private:
        int el_row, el_col;
        double* elementPointer;
        Matrix* parrent;
    };

    rc* prc;

    void wakeMeUp(int, int);
    double multiply(const Matrix&, int, int);
    void detach(double, int, int);
    void DelMatrix();
    void processInput(std::stringstream&, int);

  public:
    Matrix();
    Matrix(int);
    Matrix(int, int);
    Matrix(Matrix&);            /* konstruktor kopiujący */
    ~Matrix();

    el operator()(int, int);    /* operator indeksujący */
    double operator()(int, int) const;
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix& operator=(const Matrix& right);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    bool operator==(const Matrix&);
    Matrix& transpose() const;

    int getSizeX() const;
    int getSizeY() const;
    int getRC() const;
    bool empty() const;

    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::ifstream& operator>>(std::ifstream&, Matrix&);
  };

#endif /* __MATRIX_H__ */
