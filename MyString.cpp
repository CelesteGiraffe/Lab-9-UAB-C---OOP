#include "MyString.h"

// Default Constructor
MyString::MyString() {
    len = 0;
    data = new char[1];
    data[0] = '\0';
}
// Constructor from std::string
MyString::MyString(const std::string& str) {
    // Get the length of the input string
    len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // add extra space for the null terminator
    data = new char[len + 1];

    // move the string into the data array
    for (int i = 0; i < len; ++i) {
        data[i] = str[i];
    }

    // append the null term
    data[len] = '\0';
}

// Copy from another MyString object
MyString::MyString(const MyString& other) {
    len = other.len;

    // add extra space for the null terminaor
    data = new char[len + 1];

    // move into the data array
    for (int i = 0; i < len; ++i) {
        data[i] = other.data[i];
    }

    // append the null term
    data[len] = '\0';
}

// Destructor
MyString::~MyString() {
    delete[] data;
}

// Converts the MyString to a standard string
std::string MyString::toString() const {
    std::string result;
    for (int i = 0; i < len; ++i) {
        result += data[i];
    }
    return result;
}

// Returns the length of the string
int MyString::length() const {
    return len;
}

// Returns a substring starting at 'start' position and of length 'n' characters
MyString MyString::substr(int start, int n) const {
    // make sure the start is within bounds
    if (start < 0 || start >= len) {
        return MyString("");
    }

    // make sure n is within bounds
    if (n < 0 || start + n > len) {
        n = len - start;
    }

    // create the memory for the substring
    char* subData = new char[n + 1];

    // Copy the substring characters
    for (int i = 0; i < n; ++i) {
        subData[i] = data[start + i];
    }

    // null term
    subData[n] = '\0';

    // Create a MyString object from the substring data
    MyString subStr((std::string(subData)));

    // Deallocate the temporary substring data
    delete[] subData;

    return subStr;
}

// Overload +
MyString MyString::operator+(const MyString& other) const {
    // get the new length
    int newLen = len + other.len;

    // allocate memory for the new data
    char* newData = new char[newLen + 1];

    // Copy data from the first string
    for (int i = 0; i < len; ++i) {
        newData[i] = data[i];
    }

    // Copy data from the second string
    for (int i = 0; i < other.len; ++i) {
        newData[len + i] = other.data[i];
    }

    // null term
    newData[newLen] = '\0';

    // Create a MyString object from the new data
    MyString result((std::string(newData)));

    // delete the coppy data
    delete[] newData;

    return result;
}

// Overload =
MyString& MyString::operator=(const MyString& other) {
    // Check for self-assignment
    if (this != &other) {
        // delete the current data
        delete[] data;

        len = other.len;

        data = new char[len + 1];

        // Copy the data
        for (int i = 0; i < len; ++i) {
            data[i] = other.data[i];
        }

        // null term
        data[len] = '\0';
    }
    return *this;
}

// Overload <<
std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
    for (int i = 0; i < myStr.len; ++i) {
        os << myStr.data[i];
    }
    return os;
}

// Overloads ==
bool MyString::operator==(const MyString& other) const {
    // If lengths are different, strings are not equal
    if (len != other.len) {
        return false;
    }

    // Compare each char and return false if any are different
    for (int i = 0; i < len; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

// Overloads !=
bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

// Overload <
bool MyString::operator<(const MyString& other) const {
    int minLen = (len < other.len) ? len : other.len;

    // each character is compared 
    for (int i = 0; i < minLen; ++i) {
        if (data[i] < other.data[i]) {
            return true;
        } else if (data[i] > other.data[i]) {
            return false;
        }
    }

    // If all characters are equal, shorter string is considered less
    return len < other.len;
}

// Overload <=
bool MyString::operator<=(const MyString& other) const {
    return (*this < other) || (*this == other);
}

// Overload >
bool MyString::operator>(const MyString& other) const {
    return !(*this <= other);
}

// Overload 
bool MyString::operator>=(const MyString& other) const {
    return !(*this < other);
}
