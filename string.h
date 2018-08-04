#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <cstring>
#include <cstdlib>
#include <assert.h>

namespace pax
{
    template <typename T>
    class basic_string
    {
    public:
        basic_string() : _len(0), _str(nullptr)
        {
        }

        explicit basic_string(const T *str)
        {
            if (str && str[0])
            {
                _set(str, strlen(str));
            }
            else
            {
                _str = nullptr;
                _len = 0;
            }
        }

        basic_string(const T *str, size_t len)
        {

            _set(str, len);
        }

        basic_string(const basic_string &other)
        {
            if (other._len)
            {
                _set(other._str, other._len);
            }
            else
            {
                _len = 0;
                _str = nullptr;
            }
        }

        ~basic_string()
        {
            free(_str);
        }

        size_t length() const
        {
            return _len;
        }

        T *c_str() const
        {
            return _str;
        }

        T& operator [](size_t index)
        {
            assert(index < _len);
            return _str[index];
        }

        basic_string& operator =(const T *str)
        {
            if (_len)
            {
                _len = 0;
                free(_str);
            }

            if (str && str[0])
            {
                _set(str, strlen(str));
            }
            else
            {
                _str = nullptr;
                _len = 0;
            }

            return *this;
        }

        basic_string& operator =(const basic_string& other)
        {
            if (_len)
            {
                _len = 0;
                free(_str);
            }

            if (other._len)
            {
                _set(other._str, other._len);
            }
            else
            {
                _len = 0;
                _str = nullptr;
            }

            return *this;
        }

        basic_string& append(const T *str)
        {
            if (str && str[0])
            {
                _append(str, strlen(str));
            }

            return *this;
        }

        basic_string& append(const T *str, size_t len)
        {
            if (str && str[0])
            {
                _append(str, strlen(str));
            }

            return *this;
        }

        basic_string& append(const basic_string& str)
        {
            if (str._len)
            {
                _append(str._str, str._len);
            }

            return *this;
        }

    private:
        void _set(const T *str, size_t len)
        {
            _str = (T *)malloc(sizeof(T) * (len + 1));

            _len = len;
            memcpy(_str, str, sizeof(T) * len);

            _str[_len] = 0;
        }

        void _append(const T *str, size_t len)
        {
            T *sTmp = (T *)malloc(sizeof(T) * (_len + len + 1));

            memcpy(sTmp, _str, sizeof(T) * _len);
            memcpy(sTmp + _len, str, sizeof(T) * len);
            sTmp[_len + len] = 0;

            free(_str);
            _str = sTmp;
            _len += len;
        }

        size_t _len;
        T *_str;
    };

    typedef basic_string<char> string;
    typedef basic_string<unsigned char> bytes;
}

#endif // !STRING_STRING_H
