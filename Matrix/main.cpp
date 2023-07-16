#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Matrix;
std::ostream& operator>>(std::ostream& os, const Matrix& obj);
std::ostream& operator<<(std::ostream& os, const Matrix& obj);
Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(Matrix left, Matrix right);

class Matrix
{
	int rows;
	int cols;
	double** matrix;
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	double** get_matrix()
	{
		return matrix;
	}

	Matrix(int rows)
	{
		this->rows = rows;
		this->rows = 1;
		for (int i = 0; i < rows; i++)
			cout << "1ArgConstructor:\t" << this << endl;
	}

	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->matrix = matrix;
		for (int i = 0; i < rows; i++)
			cout << "Constructor:\t" << this << endl;
	}
	Matrix(const Matrix& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = other.matrix;
		cout << "CopyConstructor:\t" << this << endl;
	}

	Matrix(Matrix&& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = other.matrix;
		other.rows = 0;
		other.cols = 0;
		other.matrix = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
};

Matrix operator+(const Matrix& left, const Matrix& right)
{
	Matrix Plus(left.get_rows(), left.get_cols());
	if(left.get_rows() ==  right.get_cols() && left.get_cols() == right.get_rows());
	{		
		for (int i = 0; i < right.get_rows(); i++)
			for (int j = 0; j < right.get_cols(); j++)
			{
				return Plus;
			}				
	}
} 

Matrix operator-(const Matrix& left, const Matrix& right)
{
	Matrix Plus(left.get_rows(), left.get_cols());
	if (left.get_rows() == right.get_cols() && left.get_cols() == right.get_rows());
	{
		for (int i = 0; i < right.get_rows(); i++)
			for (int j = 0; j < right.get_cols(); j++)
			{
				return Plus;
			}
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
	return os << obj.get_rows();
}

std::ostream& operator>>(std::ostream& os, const Matrix& obj)
{
	return os << obj.get_cols();
}

Matrix operator/(const Matrix& left, const Matrix& right)
{
	return left.get_rows() *  right.get_cols();
}

Matrix operator*(Matrix left, Matrix right)
{
	left.get_rows();
	right.get_cols();
	return Matrix
	(
		left.get_cols() * right.get_cols(),
		left.get_rows() * right.get_cols()
	).get_rows();
}

void main()
{
	setlocale(LC_ALL, "");		
	Matrix M1(2);
	std::cout << "Матрица 1" << std::endl << M1 << std::endl;
	Matrix M2(3, 3);
	std::cout << "Матрица 2" << std::endl << M2 << std::endl;
	Matrix M3 = M1 + M2;
	std::cout << "Сумма" << std::endl << M3<< std::endl;
	Matrix M4 = M1 - M2;
	std::cout << "Разность" << std::endl << M4 << std::endl;
	Matrix M5 = M1 * M2;
	std::cout << "Умножение" << std::endl << M5 << std::endl;
	Matrix M6 = M1 / M2;
	std::cout << "Деление" << std::endl << M6 << std::endl;
}