#include "matrix.hpp"

int main()
{
	Matrix iz(1);
	std::ifstream iFile;
	iFile.open("one.txt");
	iFile >> iz;
	iFile.close();

	std::cout << "iz\n" << iz << std::endl;
	std::cout << "rc iz = " << iz.getRC() << std::endl;

	Matrix x;
	std::cout << "x:\n" << x << std::endl;
	Matrix z(3,6);
	std::cout << "rc = " << z.getRC() << std::endl;
	Matrix a(z);
	std::cout << "rc = " << a.getRC() << std::endl;
	Matrix b(z);
	std::cout << "rc = " << b.getRC() << std::endl;
	Matrix c(z);
	std::cout << "rc = " << c.getRC() << std::endl;
	Matrix d(z);
	std::cout << "rc = " << d.getRC() << std::endl;
	Matrix e(z);
	std::cout << "Z:\n" << z << e << std::endl;

	Matrix y(3);
	Matrix yf(y);
	std::cout << "rc y = " << y.getRC() << std::endl;

	y(0,0) = 1;
	y(0,1) = 2;
	y(0,2) = 3;
	y(1,0) = 4;
	y(1,1) = 5;
	y(1,2) = 6;
	y(2,0) = 7;
	y(2,1) = 8;
	y(2,2) = 9;

	std::cout << "y:\n" << y << std::endl;
	std::cout << "yf\n" << yf << std::endl;
	std::cout << "rc y = " << y.getRC() << std::endl;

	e(0,2) = 13;
	b = e;
	std::cout << "b = e\nrc e = " << e.getRC() << std::endl;
	std::cout << "e(0,2) = " << e(0,2) << std::endl;

	e(1,2) = e(0,2);
	std::cout << "rc e = " << e.getRC() << std::endl;


	std::cout << "e:\n" << e << std::endl;
	std::cout << "Z:\n" << z << std::endl;
	std::cout << "b:\n" << b << std::endl;
	std::cout << "rc a = " << a.getRC() << std::endl;
	std::cout << "rc e = " << e.getRC() << std::endl;
	std::cout << "rc b = " << b.getRC() << std::endl;
	std::cout << "rc yf = " << yf.getRC() << std::endl;


}
