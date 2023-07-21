#include<iostream>
#include"Fraction.h"
#define _CRT_SECURE_NO_WARNINGS

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPEARTORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define INPUT_CHECK_1
//#define TYPE_CONVERSION_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHET

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK

	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;
	E.print();

	Fraction F;
	F = D;
	F.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ARITHMETICAL_OPEARTORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*A.to_improper();
	A.print();

	A.to_proper();
	A.print();*/

	/*Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();*/

	A *= B;
	A.print();
#endif // ARITHMETICAL_OPEARTORS_CHECK
#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A >= B) << endl;
#endif // COMPARISON_OPERATORS_CHECK
#ifdef INPUT_CHECK_1
	Fraction A(5, 10);
	cout << "¬ведите простую дробь: "; cin >> A;
	cout << A << endl;
	A.reduce();
	cout << A << endl;
#endif // INPUT_CHECK_1	
#ifdef TYPE_CONVERSION_BASICS
	/*Fraction A, B, C;
	cout << "¬ведите три простые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B<<"\t" << C << endl;*/

	int a = 2;
	double b = 3;
	int c = b;
	int d = 5.7;
	cout << 7. / 2 << endl;
#endif // TYPE_CONVERSION_BASICS
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B;
	cout << delimiter << endl;
	B = Fraction(8);
	cout << delimiter << endl;
	cout << B << endl;
	/*Fraction C(12);*/
	Fraction C{ 12 };
	cout << C << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHET
	Fraction A(2, 1, 2);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHET

	/*Fraction A = 2.77;
	cout << A << endl;

	Fraction B = 3.333;
	cout << B << endl;*/
}