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


};


#endif // STRING_DS_HPP