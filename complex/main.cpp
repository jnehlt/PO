#include "Complex.h"

int main()
{
  Complex c(-2, -8);
  Complex x(12);
  Complex y(0, 3);

  std::cout << "    x: " << x << std::endl;
  std::cout << "    y: " << y << std::endl;
  std::cout << "    c: " << c << std::endl;

  std::cout << "\n7+x+y+c: " << 7 + x + y + c << std::endl;
  std::cout << "x+y-c-40: " << x + y - c - 27 << std::endl;

  std::cout << "\n====Proof====\nx = " << x << "\ny = " << y << "\nc = " << c << "\n=============\n";

  x += Complex(10, 20);
  std::cout << "x += rvalue(10, 20): " << x << std::endl;

  std::cout << "x += rvalue(10, 10) += 5 = " << (x += Complex(10, 10) += 5) << std::endl;

  Complex z = x;

  if(x == y)
    std::cout << "x is equal to y\n";
  else
    std::cout << "x is not equal to y\n";

  if(x == z)
    std::cout << "x is equal to z\n";
  else
    std::cout << "x is not equal to z\n";

  std::cout << "imag = " << Imaginary(Complex(9, 17)) << std::endl;
  std::cout << "real = " << Real(Complex(28)) << std::endl;
  std::cout << "amp = " << amp(x) << std::endl;
  std::cout << "deg = " << deg(x) << " degrees\n";

  std::cout << x << std::endl;
  std::cout << x.Real() << std::endl;
  std::cout << x.Imaginary() << std::endl;
  std::cout << x.amp() << std::endl;
  std::cout << x.deg() << std::endl;
}
