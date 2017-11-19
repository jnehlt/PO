#include "Complex.h"

std::ostream& operator<< (std::ostream& sth, const Complex& printable)
{
  if(printable.Im < 0)
    return sth << printable.Re << " - " << -printable.Im << "i";
  return sth << printable.Re << " + " << printable.Im << "i";
}

Complex operator+ (const Complex& left, const Complex& right)
{
  return Complex(left.Re + right.Re, left.Im + right.Im);
}

Complex operator- (const Complex& left, const Complex& right)
{
  return Complex(left.Re - right.Re, left.Im - right.Im);
}

Complex operator* (const Complex& left, const Complex& right)
{
  return Complex(left.Re * right.Re, left.Im * right.Im);
}

Complex operator/ (const Complex& left, const Complex& right)
{
  return Complex(left.Re * right.Re, left.Im * right.Im);
}

//external friend functions to returning; real, imaginary, amplitude or phase
double Real(const Complex& number)
{
  return number.Re;
}

double Imaginary(const Complex& number)
{
  return number.Im;
}

double amp(const Complex& number)
{
  return sqrt(number.Re * number.Re + number.Im * number.Im);
}

double deg(const Complex& number)
{
  return atan2(number.Im, number.Re) * 180/3.14159265;
}
