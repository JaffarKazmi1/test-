//#include "MyString.h"
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//MyString::MyString()
//{
//	size = 0;
//	capacity = 0;
//	cs = nullptr;
//
//}
//MyString::MyString(const MyString& s)
//{
//	deepcopy(s.cs);
//}
//MyString::MyString(int t, char c)
//{
//	size = t;
//	capacity = size * 2;
//
//	cs = new char[capacity] {'\0'};
//
//	for (int i = 0; i < size; i++)
//	{
//		cs[i] = c;
//	}
//	cs[size] = '\0';
//
//}
//MyString::MyString(int s, char* c)
//{
//	size = s;
//	capacity = capacity * 2;
//
//	cs = new char[capacity] {'\0'};
//
//	deepcopy(c);
//}
//MyString::MyString(const char* AString)
//{
//	deepcopy(AString);
//}
//
//void MyString::regrow1d()
//{
//	capacity = capacity * 2;
//	char* newarr = new char[capacity] {};
//
//	for (int i = 0; i < size; i++)
//	{
//		newarr[i] = cs[i];
//	}
//
//	delete[]cs;
//	cs = newarr;
//}
//void MyString::deepcopy(const char* AString)
//{
//	size = STRLEN(AString);
//
//	capacity = size * 2;
//
//	cs = new char[capacity] {};
//
//	for (int i = 0; i <= size; i++)
//	{
//		cs[i] = AString[i];
//	}
//}
//int MyString::STRLEN(const char* AString)
//{
//	if (AString == nullptr)
//	{
//		return 0;
//	}
//
//	int c = 0;
//	while (AString[c] != '\0')
//	{
//		c++;
//	}
//
//	return c;
//}
//void MyString::input()
//{
//	char ch;
//
//	size = 0;
//
//	cout << "Enter string : " << endl;
//
//	while (true)
//	{
//		ch = cin.get();
//
//		if (ch == '\n')
//		{
//			break;
//		}
//
//		if (size > capacity)
//		{
//			regrow1d();
//		}
//
//		cs[size] = ch;
//		size++;
//	}
//
//	cs[size] = '\0';
//}
//void MyString::print()const
//{
//	cout << cs;
//}
//bool MyString::is_equal(const MyString& s)const
//{
//	if (size != s.size)
//	{
//		return false;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		if (cs[i] != s.cs[i])
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//bool MyString::is_less(const MyString& s)const
//{
//	if (cs[0] != s.cs[0] && cs[0] < s[0])
//	{
//		return true;
//	}
//
//	int lesser = 0;
//	if (size < s.size)
//	{
//		lesser = size;
//	}
//	else
//	{
//		lesser = s.size;
//	}
//
//	for (int i = 0; i < lesser; i++)
//	{
//		if (cs[i] < s.cs[i])
//		{
//			return true;
//		}
//		else if (cs[i] > s.cs[i])
//		{
//			return false;
//		}
//	}
//
//}
//bool MyString::is_greater(const MyString& s)const
//{
//	if (cs[0] != s[0] && cs[0] > s[0])
//	{
//		return true;
//	}
//
//	int lesser = 0;
//	if (size < s.size)
//	{
//		lesser = size;
//	}
//	else
//	{
//		lesser = s.size;
//	}
//
//	for (int i = 0; i < lesser; i++)
//	{
//		if (cs[i] > s.cs[i])
//		{
//			return true;
//		}
//		else if (cs[i] < s.cs[i])
//		{
//			return false;
//		}
//	}
//
//
//}
//int MyString::CMP(const MyString& s)const
//{
//	int i = 0;
//	for (int i = 0; (i != size && i != s.size); i++)
//	{
//		if (cs[i] < s.cs[i])
//		{
//			return -1;
//		}
//		if (cs[i] > s.cs[i])
//		{
//			return 1;
//		}
//	}
//
//	if (size == s.size)
//	{
//		return 0;
//	}
//	if (size < s.size)
//	{
//		return -1;
//	}
//
//	return 1;
//
//}
//void MyString::ReplaceFirstChar(char ch)
//{
//	cs[0] = ch;
//}
//int  MyString::findall(char ch)
//{
//	int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (cs[i] == ch)
//		{
//			count++;
//		}
//	}
//	int* is = new int[count];
//
//	for (int i = 0, j = 0; i < size; i++)
//	{
//		if (cs[i] == ch)
//		{
//			is[j] = i;
//			j++;
//		}
//	}
//	return count;
//}
//void MyString::clear()
//{
//	for (int i = 0; i < size; i++)
//	{
//		cs[i] = '\0';
//	}
//	size = 0;
//
//
//}
//void MyString::remove_first(char ch)
//{
//	int i = 0;
//	for (i = 0; i < STRLEN(cs); i++)
//	{
//		if (cs[i] == ch)
//		{
//			break;
//		}
//	}
//	int len = STRLEN(cs);
//
//	if (len == 0)
//	{
//		return;
//	}
//
//	for (int j = i; i < len - 1; j++)
//	{
//		cs[j] = cs[j + 1];
//	}
//
//	cs[len - 1] = '\0';
//}
//void MyString::remove_last(char ch)
//{
//	int i = -1;
//
//	for (int j = size - 1; j >= 0; j--)
//	{
//		if (cs[j] == ch)
//		{
//			i = j;
//			break;
//		}
//	}
//
//	while (i == -1)
//	{
//		cout << "Character not present in string, re-enter character: ";
//		cin >> ch;
//
//		for (int j = size - 1; j >= 0; j--)
//		{
//			if (cs[j] == ch)
//			{
//				i = j;
//				break;
//			}
//		}
//	}
//
//	for (int j = i; i < size - 1; j++)
//	{
//		cs[j] = cs[j + 1];
//	}
//
//	size = size - 1;
//	cs[size] = '\0';
//}
//void MyString::remove_all(char ch)
//{
//	int i = -1;
//
//	for (int j = size - 1; j >= 0; j--)
//	{
//		if (cs[j] == ch)
//		{
//			i = j;
//			break;
//		}
//	}
//
//	while (i == -1)
//	{
//		cout << "Character not present in string, re-enter character: ";
//		cin >> ch;
//
//		for (int j = size - 1; j >= 0; j--)
//		{
//			if (cs[j] == ch)
//			{
//				i = j;
//				break;
//			}
//		}
//	}
//	int newsize = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (cs[i] != ch)
//		{
//			cs[newsize] = cs[i];
//			newsize++;
//		}
//	}
//
//
//	size = newsize;
//	cs[size] = '\0';
//
//
//}
//const MyString MyString::concat(const MyString& s)const
//{
//	MyString CS;
//	CS.size = size + s.size;
//	CS.capacity = CS.size * 2;
//
//
//	CS.cs = new char[capacity];
//
//
//	for (int i = 0; i < size; i++)
//	{
//		CS.cs[i] = cs[i];
//	}
//
//	for (int i = 0; i < s.size; i++)
//	{
//		CS.cs[size + i] = s.cs[i];
//	}
//	CS.cs[size] = '\0';
//	return CS;
//
//}
//void MyString::insert_at(int i, char ch)
//{
//	if (i < 0 && i > size)
//	{
//		while (i > size)
//		{
//			cout << "invalid index, re-enter index : " << endl;
//			cin >> i;
//		}
//	}
//
//	cs[i] = ch;
//}
//void MyString::insert_at(int i, const MyString sub)
//{
//	if (i < 0 && i>size)
//	{
//		while (i > size)
//		{
//			cout << "invalid index, re-enter index : " << endl;
//			cin >> i;
//		}
//	}
//
//	MyString left;
//	MyString right;
//
//	left.size = i;
//	left.capacity = left.size * 2;
//
//	left.cs = new char[left.capacity] {'\0'};
//
//	for (int j = 0; j < left.size; j++)
//	{
//		left.cs[j] = cs[j];
//	}
//
//	left.cs[left.size] = '\0';
//
//	right.size = size - 1;
//	right.capacity = right.size * 2;
//
//	right.cs = new char[right.capacity] {'\0'};
//
//	for (int j = i; j < size; j++)
//	{
//		right.cs[j - i] = cs[j];
//	}
//
//	right.cs[right.size] = '\0';
//
//	MyString temp = left.concat(sub).concat(right);
//
//	*this = temp;
//
//
//}
//void MyString::to_upper()
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (cs[i] >= 97 && cs[i] <= 122)
//		{
//			cs[i] = cs[i] - 32;
//		}
//	}
//}
//void MyString::to_lower()
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (cs[i] >= 97 && cs[i] <= 122)
//		{
//			cs[i] = cs[i] + 32;
//		}
//	}
//}
//void MyString::trim()
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (cs[i] == '\n' || cs[i] == '\t')
//		{
//			for (int j = i; i < size - 1; j++)
//			{
//				cs[j] = cs[j + 1];
//			}
//			cs[size - 1] = '\0';
//			size--;
//			i--;
//		}
//	}
//
//}
//char MyString :: operator[](int i) const
//{
//	if (i<0 && i>size)
//	{
//		cout << "invalid index";
//		return '\0';
//	}
//	return cs[i];
//}
//ostream& operator<<(ostream& out, const MyString& str)
//{
//	cout << str.cs;
//
//	return out;
//}
//istream& operator>>(istream& in, MyString& str)
//{
//	int i = 0;
//	char ch;
//	str.cs = NULL;
//	while (in.get(ch)) {
//		if (ch == ' ') {
//			break;
//		}
//		if (str.cs == nullptr) {
//			str.cs = new char[str.capacity + 1] {};
//			str.capacity = 1;
//		}
//		str.cs[i++] = ch;
//		str.size++;
//		if (i >= str.capacity) {
//			str.regrow1d();
//		}
//	}
//	return in;
//}
//ifstream& operator>>(ifstream& in, MyString& str)
//{
//	int i = 0;
//	char ch;
//	str.cs = NULL;
//	while (in.get(ch)) {
//		if (ch == ' ') {
//			break;
//		}
//		if (str.cs == nullptr) {
//			str.cs = new char[str.capacity + 1] {};
//			str.capacity = 1;
//		}
//		str.cs[i++] = ch;
//		str.size++;
//		if (i >= str.capacity) {
//			str.regrow1d();
//		}
//	}
//	return in;
//}
//MyString& MyString::operator=(const MyString& s)
//{
//	if (this != &s)
//	{
//		delete[] cs;
//
//		size = s.size;
//		capacity = s.capacity;
//		cs = new char[capacity];
//
//		for (int i = 0; i <= size; i++)
//		{
//			cs[i] = s.cs[i];
//		}
//	}
//	return *this;
//}
//char& MyString ::  operator[](int i)
//{
//	while (i<0 && i>size)
//	{
//		cout << "invalid index, re-enter index :" << endl;
//		cin >> i;
//	}
//
//	return cs[i];
//}
//MyString::~MyString()
//{
//	delete[]cs;
//	cs = nullptr;
//}
//const char* MyString::getString() const { return cs; }
//
//int main90()
//{
//
//	char ch[] = "Hello ";
//	MyString s1(ch);
//	cout << "First string : " << endl;
//	s1.print();
//
//	cout << endl;
//
//	char ch2[] = "World";
//	MyString s2(ch2);
//	cout << "Second string : " << endl;
//	s2.print();
//	cout << endl;
//	cout << endl;
//
//	int choice = 0;
//
//	while (true)
//	{
//		cout << "=====STRING LIBRARY=====" << endl;
//		cout << "Enter 1 to check equality : " << endl;
//		cout << "Enter 2 to check weather first string is lesser the other : " << endl;
//		cout << "Enter 3 to check  weather first string is greater the other : " << endl;
//		cout << "Enter 5 to replace first character : " << endl;
//		cout << "Enter 6 to find all occurences of a character : " << endl;
//		cout << "Enter 7 to clear string : " << endl;
//		cout << "Enter 8 to remove first occurence of a character : " << endl;
//		cout << "Enter 9 to remove last occurence of a character : " << endl;
//		cout << "Enter 10 to remove all occurence of a character : " << endl;
//		cout << "Enter 11 to concatenate both string : " << endl;
//		cout << "Enter 12 to insert a character at a certain index : " << endl;
//		cout << "Enter 13 to insert a string at a certain index : " << endl;
//		cout << "Enter 14 to convert string to lower case : " << endl;
//		cout << "Enter 15 to convert string to upper case : " << endl;
//		cout << "Enter 16 to trim string : " << endl;
//		cout << "Enter 17 to exit : " << endl;
//		cin >> choice;
//
//		if (choice == 1)
//		{
//			bool check = s1.is_equal(s2);
//			if (check == true)
//			{
//				cout << "Both strings are equal " << endl;
//
//			}
//			else
//			{
//				cout << "Both strings are not equal " << endl;
//			}
//			cout << endl;
//		}
//		else if (choice == 2)
//		{
//			bool check = s1.is_less(s2);
//			if (check == true)
//			{
//				cout << "Frist string appears first in dictionary " << endl;
//
//			}
//			else
//			{
//				cout << "Frist string appears later in dictionary" << endl;
//			}
//			cout << endl;
//		}
//		else if (choice == 3)
//		{
//			bool check = s1.is_greater(s2);
//			if (check == true)
//			{
//				cout << "Frist string appears later in dictionary" << endl;
//
//			}
//			else
//			{
//				cout << " Frist string appears first in dictionary " << endl;
//			}
//			cout << endl;
//		}
//		else if (choice == 5)
//		{
//			char ch;
//
//			cout << "Enter replacment character  : " << endl;
//			cin >> ch;
//
//			s1.ReplaceFirstChar(ch);
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 6)
//		{
//			char ch;
//
//			cout << "Enter search character  : " << endl;
//			cin >> ch;
//
//			int ct = s1.findall(ch);
//
//			cout << "No.of occurences = " << ct << endl;
//
//		}
//		else if (choice == 7)
//		{
//			s1.clear();
//			cout << "String after clearing : " << endl;
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 8)
//		{
//			char ch;
//			cout << "Enter character to remove it's first occurence : " << endl;
//			cin >> ch;
//			s1.remove_first(ch);
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 9)
//		{
//			char ch;
//			cout << "Enter character to remove it's last occurence : " << endl;
//			cin >> ch;
//			s1.remove_last(ch);
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 10)
//		{
//			char ch;
//			cout << "Enter character to remove it's all occurence : " << endl;
//			cin >> ch;
//			s1.remove_all(ch);
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 11)
//		{
//			cout << "After concatenation : " << endl;
//			MyString s3 = s1.concat(s2);
//			s3.print();
//			cout << endl;
//		}
//		else if (choice == 12)
//		{
//			char ch;
//			int i;
//			cout << "Enter insertion character and index : " << endl;
//			cin >> ch >> i;
//
//			s1.insert_at(ch, i);
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 13)
//		{
//			int i;
//			cout << "s2 will be inserted at your index : " << endl;
//			cin >> i;
//
//			s1.insert_at(i, s2);
//			s1.print();
//			cout << endl;
//
//		}
//		else if (choice == 14)
//		{
//			cout << "After converting to lower case : " << endl;
//			s1.to_lower();
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 15)
//		{
//			cout << "After converting to upper case : " << endl;
//			s1.to_upper();
//			s1.print();
//			cout << endl;
//		}
//		else if (choice == 16)
//		{
//			cout << "After trim : " << endl;
//			s1.trim();
//			s1.print();
//			cout << endl;
//
//		}
//		else
//		{
//			break;
//		}
//	}
//
//
//
//
//	return 0;
//}


#include<iostream>
#include<fstream>
#include<conio.h>
#include "MyString.h"
using namespace std;
void intregrow(int*& arr, int& size) {
    int* temp = new int[size + 1] {};
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    size = size + 1;
    delete[] arr;
    arr = temp;
}
MyString::MyString() :len{ 0 }, cap{ 1 }, str{ nullptr } {}
int MyString::StringLength(const char* arr) const {
    int length = 0;
    for (int i = 0; arr[i] != 0; i++) {
        length++;
    }
    return length;
}
MyString::MyString(const char* arr) :len{ StringLength(arr) }, cap{ StringLength(arr) }, str{ this->str = new char[this->len] {} } {
    for (int i = 0; i < this->len; i++) {
        this->str[i] = arr[i];
    }
}
MyString::MyString(int cap, char a) :len{ cap }, cap{ cap }, str{ new char[cap] {} } {
    for (int i = 0; i < this->len; i++) {
        this->str[i] = a;
    }
}
MyString::MyString(const MyString& obj) {
    this->len = obj.len;
    this->cap = obj.cap + 2;
    this->str = new char[this->cap] {};
    for (int i = 0; i < obj.len; i++) {
        this->str[i] = obj.str[i];
    }
}
MyString& MyString::operator=(const MyString& obj) {
    this->len = obj.len;
    this->cap = obj.cap;
    this->str = new char[obj.cap] {};
    for (int i = 0; i < obj.len; i++) {
        this->str[i] = obj.str[i];
    }
    return *this;
}
MyString MyString::int_to_str(int num) const {
    MyString str;
    int temp = num;
    while (temp > 0) {
        temp = temp / 10;
        str.len++;
    }
    str.cap = str.len + 1;
    str.str = new char[str.cap] {};
    for (int i = str.len - 1; i > -1; i--) {
        str.str[i] = num % 10;
        num = num / 10;
    }
    return str;
}
MyString::MyString(int num) {
    *this = int_to_str(num);
}
void MyString::regrow() {
    char* arr = new char[this->cap + this->cap + 1] {'\0'};
    for (int i = 0; i < this->len; i++) {
        arr[i] = this->str[i];
    }
    this->cap = (this->cap * 2) + 1;
    delete[] this->str;
    this->str = arr;
}
void MyString::string_reg(MyString*& obj, int& size) {
    MyString* s = new MyString[size + 1];
    for (int i = 0; i < size; i++) {
        s[i] = obj[i];
    }
    size = size + 1;
    delete[] obj;
    obj = s;
}
void MyString::ShallowCopy(const MyString& obj) {
    this->len = obj.len;
    this->cap = obj.cap;
    this->str = obj.str;
}
char MyString::operator[](int i)const {
    return this->str[i];
}
char& MyString::operator[](int i) {
    return this->str[i];
}
void MyString::insert_at(char a, int idx) {
    if (idx > -1) {
        if (this->len >= this->cap - 1 || idx >= this->cap - 1) {
            this->regrow();
        }
        this->str[idx] = a;
    }
}
void MyString::insert_at(int idx, const MyString& sub) {
    if (idx > -1 && idx < this->len) {
        MyString s;
        s.cap = this->cap + sub.cap;
        s.len = this->len + sub.len;
        s.str = new char[s.cap] {};
        int i = 0, j = 0, k = 0;
        while (i < idx) {
            s.insert_at(this->str[i], k);
            i++;
            k++;
        }
        while (j < sub.len) {
            s.insert_at(sub.str[j], k);
            j++;
            k++;
        }
        while (i < this->len) {
            s.insert_at(this->str[i], k);
            i++;
            k++;
        }
        *this = s;
    }
}
void MyString::inputstring(char chr) {
    this->cap = 1;
    this->len = 0;
    this->str = new char[this->cap] {};
    char ch;
    while (true) {
        ch = _getche();
        char t;
        if (chr == '\n') {
            t = '\r';
        }
        else {
            t = chr;
        }
        if (ch == t) {
            break;
        }
        else if (ch == '\b') {
            this->len = this->len - 1;
            cout << ' ' << '\b';
        }
        else {
            this->str[this->len] = ch;
            this->len++;
        }
        if (this->len >= this->cap - 1) {
            this->regrow();
        }
    }
    cout << endl;
}
ostream& operator<<(ostream& fout, const  MyString& str) {
    for (int i = 0; i < str.len; i++) {
        fout << str.str[i];
    }
    return fout;
}
istream& operator>>(istream& fout, MyString& str)
{
    getline(fout, str, '\n');
    cout << '\n';
    return fout;
}
istream& getline(istream& fin, MyString& str, char ch) {
    str.inputstring(ch);
    return fin;
}
bool MyString::operator==(const MyString& str2)const {
    if (this->len != str2.len) {
        return false;
    }
    for (int i = 0; i < this->len; i++) {
        if (this->str[i] != str2.str[i]) {
            return false;
        }
    }
    return true;
}
bool MyString::operator!=(const MyString& str2)const {
    if (*this == str2) {
        return false;
    }
    return true;
}
bool MyString::operator<(const MyString& str2)const {
    int i = 0, j = 0;
    if (*this == str2) {
        return false;
    }
    while (i < this->len && j < str2.len) {
        if (this->str[i] > str2.str[j]) {
            return false;
        }
        else if (this->str[i] < str2.str[j]) {
            return true;
        }
        else {
            i++;
            j++;
        }
    }
    if (i < this->len) {
        return false;
    }
    else {
        return true;
    }
}
bool MyString::operator<=(const MyString& str2)const {
    if (*this > str2) {
        return false;
    }
    return true;
}
bool MyString::operator>(const MyString& str2)const {
    int i = 0, j = 0;
    if (*this == str2) {
        return false;
    }
    while (i < this->len && j < str2.len) {
        if (this->str[i] < str2.str[j]) {
            return false;
        }
        else if (this->str[i] > str2.str[j]) {
            return true;
        }
        else {
            i++;
            j++;
        }
    }
    if (i < this->len) {
        return true;
    }
    return false;
}
bool MyString::operator>=(const MyString& str2)const {
    if (*this < str2) {
        return false;
    }
    return true;
}
MyString operator+(const MyString& s1, const MyString& str2) {
    MyString new_str;
    new_str.cap = s1.cap + str2.cap;
    new_str.str = new char[new_str.cap] {};
    new_str.len = s1.len + str2.len;
    int i = 0, j = 0, k = 0;
    while (i < s1.len) {
        new_str.str[k++] = s1.str[i++];
    }
    while (j < s1.len) {
        new_str.str[k++] = str2.str[j++];
    }
    return new_str;
}
MyString& MyString::operator+=(const MyString& str2) {
    *this = *this + str2;
    return *this;
}
int* MyString::all_chars(char ch, int& count) const {
    int size = 1, ct = 0;
    int* idx = new int[size] {};
    for (int i = 0; i < this->len; i++) {
        if (this->str[i] == ch) {
            count++;
            if (ct >= size) {
                intregrow(idx, size);
            }
            idx[ct++] = i;
        }
    }
    return idx;
}
MyString* MyString::split(const char ch, int& count)const {
    int* idx = this->all_chars(ch, count);
    MyString* s = new MyString[count + 1];
    int i = 0, j = 0;
    while (i < count) {
        s[i].str = new char[s[i].cap] {'\0'};
        int k = 0;
        while (j < idx[i]) {
            if (k >= s[i].cap - 1) {
                s[i].regrow();
            }
            s[i].str[k++] = this->str[j];
            s[i].len++;
            j++;
        }
        j++;
        i++;
    }
    int k = 0;
    s[i].str = new char[s[i].cap] {'\0'};
    while (j < this->len) {
        if (k >= s[i].cap - 1) {
            s[i].regrow();
        }
        s[i].str[k++] = this->str[j++];
        s[i].len++;
    }
    count++;
    return s;
}
int* MyString::all_sub_str(char* arr, int& count) const {
    int length = this->StringLength(arr);
    int size = 1, ct = 0;
    int* idx = new int[size] {};
    for (int i = 0; i < this->len; i++) {
        int j = 0;
        if (this->str[i] == arr[j]) {
            bool flag = true;
            int k = i;
            while (j < length) {
                if (this->str[i] != arr[j]) {
                    flag = false;
                    break;
                }
                if (i < this->len) {
                    i++;
                }
                else {
                    flag = false;
                    break;
                }
                j++;
            }
            if (flag) {
                count++;
                if (ct >= size) {
                    intregrow(idx, size);
                }
                idx[ct++] = k;
            }
        }
    }
    return idx;
}
MyString* MyString::tokenize(char* arr, int& count)const {
    int* idx = this->all_sub_str(arr, count);
    int length = this->StringLength(arr);
    MyString* s = new MyString[count + 1];
    int i = 0, j = 0;
    while (i < count) {
        s[i].str = new char[s[i].cap] {'\0'};
        int k = 0;
        while (j < idx[i]) {
            if (k >= s[i].cap - 1) {
                s[i].regrow();
            }
            s[i].str[k++] = this->str[j];
            s[i].len++;
            j++;
        }
        j += length;
        i++;
    }
    int k = 0;
    s[i].str = new char[s[i].cap] {'\0'};
    while (j < this->len) {
        if (k >= s[i].cap - 1) {
            s[i].regrow();
        }
        s[i].str[k++] = this->str[j++];
        s[i].len++;
    }
    count++;
    return s;
}
int MyString::first_idx(const char ch)const {
    int count = 0;
    int* idx = this->all_chars(ch, count);
    return idx[0];
}
int MyString::last_idx(const char ch)const {
    int count = 0;
    int* idx = this->all_chars(ch, count);
    return idx[count - 1];
}

void MyString::remove_at(int idx) {
    if (idx > -1 && idx < this->len) {
        char* temp = new char[this->cap] {};
        for (int i = 0, j = 0; i < this->len; i++) {
            if (i != idx) {
                temp[j++] = this->str[i];
            }
        }
        this->len--;
        delete[] this->str;
        this->str = temp;
    }
}
void MyString::remove_first(char ch) {
    int count = 0;
    int* idx = all_chars(ch, count);
    if (count != 0) {
        this->remove_at(idx[0]);
    }
}
void MyString::remove_last(char ch) {
    int count = 0;
    int* idx = all_chars(ch, count);
    if (count != 0) {
        this->remove_at(idx[count - 1]);
    }
}
MyString::~MyString() {
    delete[] this->str;
}
