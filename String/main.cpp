#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------\n"

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

//							Constructors:
	explicit String(int size = 80):size(size), str(new char[size]{})
	{
		/*this->size = size;
		this->str = new char [size] {};*/
		cout << "DefConstructor: \t" << this << endl;
	}
	String(const char* str):size(strlen(str)+1), str(new char[size]{})
	{
		int a(2);
		/*this->size = strlen(str) + 1;
		this->str = new char[size] {};*/
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):size(other.size), str(new char[size]{})
	{
		//Deep copy
		/*this->size = other.size;
		this->str = new char[size] {};*/
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//Shallow copy:
		/*this->size = other.size;
		this->str = other.str;*/
		other.size = 0;
		other.str = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor: \t" << this << endl;
	}
	
	
	//					Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		int a = 2;
		int b = 3;
		a = b;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
 	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char operator[](int i)
	{
		return str[i];
	}

	//					Methods:
	void print() const
	{
		cout << "Size:\t" << endl;
		cout << "Str:\t" << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

#define BASE_CHECK


void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK

	cout << sizeof("Hello") << endl;
	String str(5);
	str.print();
	 
	String str1 = "Hello";
	cout << str1 << endl;
	
	String str2 = "World";
	cout << str2 << endl;

	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;

	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;

	String str5 = str4;
	cout << str5 << endl;
#endif // BASE_CHECK

	

}