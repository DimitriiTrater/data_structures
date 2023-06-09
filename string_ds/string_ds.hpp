#ifndef STRING_DS_HPP
#define STRING_DS_HPP

#include <cstring>
#include <iostream>
class string
{

char* _str;
int _len;


public:
    string(): _str(nullptr), _len(0) {}


    string(const char* str) : _str(new char[strlen(str)+1]), _len(strlen(str))
    {
        for (int i = 0; i < _len; i++)
            _str[i] = str[i];
        _str[_len] = '\0';
    }


    string(const string& other) : _str(new char[other._len+1]), _len(other._len) 
    {
        for (int i = 0; i < _len; i++)
            _str[i] = other._str[i];
        _str[_len] = '\0';
    }


    string(string&& other) : _str(other._str), _len(other._len)
    {
        other._str = nullptr;
    }

    ~string() { delete [] _str; }


    string& operator=(const string& other)
    {
        if(!_str) delete [] _str;
        _len = other._len;
        _str = new char[_len+1];

        for (int i = 0; i < _len; i++)
            _str[i] = other._str[i];
        _str[_len] = '\0';
        return *this;
    }


    string operator+(const string& other) const
    {
        string result;

        result._len = _len + other._len;

        result._str = new char[result._len+1];
        
        int i = 0;
        
        for (; i < _len; i++)
            result._str[i] = _str[i];

        for (int j = 0; j < other._len; i++, j++)
            result._str[i] = other._str[j];
        
        result._str[result._len] = '\0';

        return result;
    }


    bool operator==(const string& other) const
    {
        if(_len != other._len) return false;
        for (int i = 0; i < _len; i++) 
            if (_str[i]!= other._str[i]) return false;
        return true;
    }


    bool operator!=(const string& other) const 
    { return !(this->operator==(other)); }


    char& operator[](int i)
    {
        return _str[i];
    }


    int length() const { return _len; }
    int size()   const { return _len; }

    friend std::ostream& operator<<(std::ostream& stream, const string& str);
    friend std::istream& operator>>(std::istream& stream, string& str);


};

inline std::ostream& operator<<(std::ostream& stream, const string& str)
{
    stream << str._str;
    return stream;
}


inline std::istream& operator>>(std::istream& stream, string& str)
{
    stream >> str._str;
    str._len = strlen(str._str);
    str[str._len+1] = '\0';
    
    return stream;
}

#endif // STRING_DS_HPP