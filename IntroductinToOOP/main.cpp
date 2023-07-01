#include<iostream>
using namespace std;

#define delimeter "\n---------------------------------\n"
class Point
{
	double x;
	double y;
public:
	double get_x(void)const
	{

		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	/*Point()
	{
		x = y = double();
		cout << "DefaultConstructor:\t\t" << this << endl;
	}

	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Cinstructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//				Operators
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator++() // Prefix increment
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point& operator-=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator/=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator*=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator <(const Point& other)
	{
		this->x < other.x;
		this->y < other.y;
		return *this;
	}

	bool operator >(const Point& other)
	{
		this->x > other.x;
		this->y > other.y;
		return this;
	}

	bool operator ==(const Point& other)
	{
		this->x == other.x;
		this->y == other.y;
		return this;
	}

	bool operator !=(const Point& other)
	{
		this->x != other.x;
		this->y != other.y;
		return this;
	}


	//				Methods
	double distance(const Point& other)const
	{		
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	//return sqrt(x_distance * x_distance + y_distance * y_distance);
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;

	/*Point result
	(
	left.get_x() + right.get_x(), 
	left.get_y() + right.get_y()
	);*/

	/*return Point
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);*/	
}

Point operator-(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() - right.get_x());
	result.set_y(left.get_y() - right.get_y());
	return result;
}

Point operator/(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() / right.get_x());
	result.set_y(left.get_y() / right.get_y());
	return result;
}

Point operator *(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() * right.get_x());
	result.set_y(left.get_y() * right.get_y());
	return result;
}

Point operator <(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() * right.get_x());
	result.set_y(left.get_y() * right.get_y());
	return result;
}


//#define STRAK_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
#define INCREMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRAK_POINT
	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRAK_POINT

#ifdef DISTANCE_CHECK

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "B:\t" << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimeter << endl;	
	cout << "Расстояние от точки 'A' до точки 'B':\t" << A.distance(B) << endl;
	cout << delimeter << endl;	
	cout << "Расстояние от точки 'B' до точки 'A':\t" << B.distance(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками 'A' и 'B':\t " << distance(A, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками 'B' и 'A':\t " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	cout << char() << endl;
	Point A;
	A.print();

	Point B = 5;
	B.print();
	Point C(2, 3);

	Point D = C;
	D.print();

	Point E;
	E = D;
	E.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	A = B = C = Point(2, 3);

	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK

#ifdef INCREMENT_CHECK
	/*int a = 2;
	int b = 3;
	int c = a + b;
	cout << c << endl;*/

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	/*++A;
	A.print();*/
#endif // INCREMENT_CHECK

	/*Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	A += B;
	A.print();

	cout << A << endl;*/
	
	Point D(10, 9);
	Point E(7, 8);
	Point F = D - E;
	F.print();
	
	Point G(2, 3);
	Point H(4, 6);
	Point I = D / H;
	I.print();

	Point J(2, 3);
	Point K(5, 6);
	Point L = J * K;
	L.print();


}
