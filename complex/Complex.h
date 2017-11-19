#ifndef __COMPLEX_H__
#define __COMPLEX_H__

  #include <iostream>
  #include <cmath>

  class Complex
  {
    double Re, Im;
  public:
    Complex()
    {
      this->Re = 0;
      this->Im = 0;
    };

    Complex(const double& re)
    {
      this->Re = re;
      this->Im = 0;
    };

    Complex(const double& re, const double& im)
    {
      this->Re = re;
      this->Im = im;
    };

    Complex& operator+= (const Complex& right)
    {
      this->Re += right.Re;
      this->Im += right.Im;
      return *this;
    }

    Complex& operator-= (const Complex& right)
    {
      this->Re -= right.Re;
      this->Im -= right.Im;
      return *this;
    }

    Complex& operator*= (const Complex& right)
    {
      this->Re *= right.Re;
      this->Im *= right.Im;
      return *this;
    }

    Complex& operator/= (const Complex& right)
    {
      this->Re /= right.Re;
      this->Im /= right.Im;
      return *this;
    }

    bool operator== (const Complex& right)
    {
      if(this->Re == right.Re)
        if(this->Im == right.Im)
          return true;
      return false;
    }

    double Real()
    {
      return this->Re;
    }

    double Imaginary()
    {
      return this->Im;
    }

    double amp()
    {
      return sqrt(this->Re * this->Re + this->Im * this->Im);
    }

    double deg()
    {
      return atan2(this->Im, this->Re) * 180/3.14159265;
    }

    friend double Real(const Complex& number);
    friend double Imaginary(const Complex& number);
    friend double amp(const Complex& number);
    friend double deg(const Complex& number);

    friend std::ostream& operator<< (std::ostream& sth, const Complex& printable);
    friend Complex operator+ (const Complex& left, const Complex& right);
    friend Complex operator- (const Complex& left, const Complex& right);
    friend Complex operator* (const Complex& left, const Complex& right);
    friend Complex operator/ (const Complex& left, const Complex& right);
  };

#endif /* __COMPLEX_H__ */
