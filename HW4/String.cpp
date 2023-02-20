#include "String.h"
#include "Alloc.h"
int String::strlen(const char* s)
{
    int len = 0;
    while (*s++)
    {
        ++len;
    }
    return len;
}
char* String::strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}
char* String::strncpy(char* dest, const char* src, int n)
{
    int len = strlen(src);
    int i;
    for (i = 0; i < n && i < len; i++)
    {
        dest[i] = src[i];
    }
    for (; i < n; i++)
    {
        dest[i] = '\0';
    }
    return dest;
}
char* String::strcat(char* dest, const char* src)
{
    int dest_len = strlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
char* String::strncat(char* dest, const char* src, int n)
{
    int dest_len = strlen(dest);
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
int String::strcmp(const char* left, const char* right)
{
    while (*left && (*left == *right))
    {
        ++left;
        ++right;
    }
    return *left - *right;
}
int String::strncmp(const char* left, const char* right, int n)
{
    if (n <= 0)
        return 0;
    while (--n && (*left) != '\0' && (*right) != '\0' && *left == *right)
    {
        left++;
        right++;
    }
    return (*left - *right);
}
void String::reverse_cpy(char* dest, const char* src)
{
    int lengthSrc = strlen(src);
    int indexSrc = lengthSrc - 1;
    int indexDes = 0;
    for (; indexDes < lengthSrc; ++indexDes, --indexSrc)
    {
        dest[indexDes] = src[indexSrc];
    }
    dest[indexDes] = '\0';
}
char* String::strchr(char* str, char c)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == c)
            return str + i;
    }
    return nullptr;
}
char* String::strstr(char* haystack, const char* needle)
{
    char* cp = (char*)haystack;
    char* s1, * s2;
    if (strlen(needle) == 0) {
        cp = haystack + strlen(haystack);
        return cp;
    }
    if (!*needle)
        return ((char*)haystack);
    while (*cp)
    {
        s1 = cp;
        s2 = (char*)needle;
        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;
        if (!*s2)
            return (cp);
        cp++;
    }
    return nullptr;
}
const char* String::strstr(const char* haystack, const char* needle)
{
    return strstr((char*)haystack, needle);
}


String::String(const char* s)
{
    buf = strdup(s);
}
String::String(const String& s)
{
    buf = strdup(s.buf);
}
String::String(String && s)
{
    Alloc::delete_char_array(buf);
    buf = s.buf;
    s.buf = nullptr;
}

String & String::operator = (String && s)
{
    Alloc::delete_char_array(buf);
    buf = s.buf;
    s.buf = nullptr;
    return *this;
}
String& String::operator=(const String& s)
{
    strcpy(buf, s.buf);
    return *this;
}
char& String::operator [] (int index)
{
    if (!in_bounds(index))
    {
        cerr << "ERROR:Index out of Bounds" << std::endl;
    }
    return buf[index];
}
size_t String::size()
{
    return strlen(buf);
}
String String::reverse()
{
    char* temp = Alloc::new_char_array(strlen(buf)+1);
    reverse_cpy(temp, buf);
    String ret(temp);
    Alloc::delete_char_array(temp);
    return ret;
}
int String::indexOf(const char c)
{
    char* ret = strchr(this->buf, c);
    if (ret != nullptr)
        return (ret - buf);
    else
        return -1;
}
int String::indexOf(const String s)
{
    char* p = strstr(buf, s.buf);

    if (p != nullptr)

        return (p - buf);

    else

        return -1;

}
bool String::operator == (const String s)
{
    return strcmp(buf, s.buf) == 0;
}

bool String::operator != (const String s)
{
    return strcmp(buf, s.buf) != 0;
}

bool String::operator > (const String s)
{
    return strcmp(buf, s.buf) > 0;
}

bool String::operator < (const String s)
{
    return strcmp(buf, s.buf) < 0;
}

bool String::operator <= (const String s)
{
    return strcmp(buf, s.buf) <= 0;

}

bool String::operator >= (const String s)
{
    return strcmp(buf, s.buf) >= 0;
}


String String::operator +(const String s)
{
    int len = strlen(buf) + strlen(s.buf);
    Alloc* alloc = new Alloc();
    char* temp = alloc->new_char_array(len + 1);
    strcpy(temp, buf);
    strcat(temp, s.buf);
    String result(temp);  
    alloc->delete_char_array(temp);
    delete(alloc);
    return result;
}
String& String::operator +=(const String s)
{
    int len = strlen(buf) + strlen(s.buf);
    Alloc* alloc = new Alloc();
    char* temp = alloc->new_char_array(len + 1);
    strcpy(temp, buf);
    strcat(temp, s.buf);
    alloc->delete_char_array(buf);
    buf = temp;
    delete(alloc);
    return *this;
}

void String::print(ostream& out)
{
    out << buf;
}

void String::read(istream& in)
{
    in >> buf;
}
String::~String()
{
    if (buf == nullptr) return;
    Alloc* alloc = new Alloc();
    alloc->delete_char_array(buf);
    delete(alloc);
    buf = nullptr;
}
bool String::in_bounds(int i)
{
    return i >= 0 && i < strlen(buf);
}
char* String::strdup(const char* s)
{
    int len = strlen(s);
    Alloc* alloc = new Alloc();
    char* ret = alloc->new_char_array(len + 1);
    strcpy(ret, s);
    delete(alloc);
    return ret;
}
ostream& operator << (ostream& out, String s)
{
    s.print(out);
    return out;
}

istream& operator >>(istream& in, String& s)
{
    s.read(in);
    return in;
}
