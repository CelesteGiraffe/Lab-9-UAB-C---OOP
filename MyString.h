#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
public:
    // Constructors and Destructor
    MyString();
    MyString(const std::string& str);
    MyString(const MyString& other); 
    ~MyString();

    // Methods
    std::string toString() const;
    int length() const;
    MyString substr(int start, int n = -1) const;

    // Mathmatical Operators
    MyString operator+(const MyString& other) const;
    MyString& operator=(const MyString& other);

    // Comparison Operators
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    // Friend Functions
    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);

private:
    char* data; // Pointer to character data
    int len;    // Length of the string
};

#endif // MYSTRING_H
