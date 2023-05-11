#ifndef STRING_DS_HPP
#define STRING_DS_HPP

#include <cstring>
class string
{

char* _str;
int _len;


public:
    string(): _str(nullptr) {}


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


    int length() const { return _len; }
    int size()   const { return _len; }

};


#endif // STRING_DS_HPP