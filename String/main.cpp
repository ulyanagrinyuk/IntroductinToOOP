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
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//							Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//					Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);
	//					Methods:
	void print() const;
};

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//							Constructors:
 String::String(int size) :size(size), str(new char[size] {})
{

	cout << "DefConstructor: \t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy:
	/*this->size = other.size;
	this->str = other.str;*/
	other.size = 0;
	other.str = 0;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor: \t" << this << endl;
}

//					Operators:
String& String::operator=(const String& other)
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
String& String::operator=(String&& other)
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
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//					Methods:
void String::print() const
{
	cout << "Size:\t" << endl;
	cout << "Str:\t" << endl;
}


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