#ifndef MYSTRING_H
#define MYSTRING_H
#include<fstream>
#include<iostream>
using namespace std;
class MyString
{
    int len;
    int cap;
    char* str;
public:
    MyString();
    int StringLength(const char* arr) const;
    MyString(const char* arr);
    MyString(int cap, char a);
    MyString(const MyString& obj);
    MyString& operator=(const MyString& obj);
    MyString int_to_str(int num) const;
    MyString(int num);
    void regrow();
    void string_reg(MyString*& obj, int& size);
    void ShallowCopy(const MyString& obj);
    char operator[](int i)const;
    char& operator[](int i);
    void insert_at(char a, int idx);
    void insert_at(int idx, const MyString& sub);
    void inputstring(char chr);
    friend std::ostream& operator<<(std::ostream& fout, const  MyString& str);
    friend std::istream& operator>>(std::istream& fout, MyString& str);
    
    friend std::istream& getline(std::istream& fin, MyString& str, char ch);
    bool operator==(const MyString& str2)const;
    bool operator!=(const MyString& str2)const;
    bool operator<(const MyString& str2)const;
    bool operator<=(const MyString& str2)const;
    bool operator>(const MyString& str2)const;
    bool operator>=(const MyString& str2)const;
    friend MyString operator+(const MyString& s1, const MyString& str2);
    MyString& operator+=(const MyString& str2);
    int* all_chars(char ch, int& count) const;
    MyString* split(const char ch, int& count)const;
    int* all_sub_str(char* arr, int& count) const;
    MyString* tokenize(char* arr, int& count)const;
    int first_idx(const char ch)const;
    int last_idx(const char ch)const;
    void remove_at(int idx);
    void remove_first(char ch);
    void remove_last(char ch);
    ~MyString();
};

#endif // !
