#include<iostream>
using namespace std;
#define MAXLEN 128

class String
{
    char buf[MAXLEN];

    static int strlen(const char * s)
    {
        int len = 0;
        while(*s++)
        {
            ++len;
        }
        return len;
    }

    static char * strcpy(char * dest,const char * src)
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
    static char * strncpy(char * dest, const char * src, int n)
    {
        int len = strlen(src);

        int i;

        for (i = 0; i < n && i < len; i++)

            {
                dest[i] = src[i];

            }

        for ( ; i < n; i++)

            {
                dest[i] = '\0';

            }

        return dest;
    }

    static char * strcat(char * dest, const char *src)
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

    static char * strncat(char * dest, const char * src, int n)
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

    static int strcmp(const char * left, const char * right)
    {
        while(*left && (*left==*right))
        {
            ++left;
            ++right;
        }
        return *left-*right;
    }

    static int strncmp(const char * left, const char *right, int n)
    {
        if(n<=0)

        return 0;


            while(--n && (*left) != '\0' && (*right) != '\0' && *left == *right)
            {
                left++;
                right++;
            }

        return (*left - *right);

    }


    static void reverse_cpy(char * dest, const char * src)
    {
        int lengthSrc = strlen(src);
	    int indexSrc = lengthSrc - 1;
	    int indexDes = 0;
	    for( ; indexDes < lengthSrc; ++indexDes, --indexSrc)
	    {
		  dest[indexDes] = src[indexSrc];
	    } 
	    dest[indexDes] = '\0';
    }

    static char * strchr(char * str, char c)
    {
        for (int i = 0; str[i] != '\0'; ++i)
            {
                if (str[i] == c)
                    return str + i;
            }

            return nullptr;
    }


    static char * strstr(char *haystack, const char *needle)
    {
        char *cp = (char *) haystack;
        char *s1,*s2;
		if(strlen(needle)==0){
			cp = haystack + strlen(haystack);
			return cp;
		}
		 if (!*needle)
             return ((char *) haystack);
        while (*cp)
        {
            s1 = cp;
            s2 = (char *) needle;
            while (*s1 && *s2 && !(*s1 - *s2))
                s1++, s2++;
            if (!*s2)
                return (cp);
            cp++;
        }
        return nullptr;
    }
    static const char * strstr(const char * haystack,const char * needle)
    {
        return strstr((char*)haystack, needle);
    }

public:

    //constructs this string from a C string, defaults to empty string

    explicit String (const char * s= "" )
    {
        int len = strlen(s);
        if(len>MAXLEN){
            cerr<<"ERROR:String Capcity Exceeded\n";
        }
        else
        {
           strncpy(buf,s,MAXLEN);
        }
    }

    String(const String & s)
    {
        strncpy(buf, s.buf,MAXLEN);

    }

    String & operator=(const String & s)
    {
        strcpy(buf, s.buf);
        return *this;
    }

    char & operator [] (int index)
    {
        if(!in_bounds(index))
        {
            cerr << "ERROR:Index out of Bounds" <<std::endl;
        }
        return buf[index];
    }

    size_t size()
    {
        return strlen(buf);
    }

    String reverse()
    {
        String r(buf);
        reverse_cpy(r.buf,buf);
        return r;
    }

    int indexOf(const char c)
    {
        char *ret = strchr(this->buf, c);
        if (ret != nullptr)
            return (ret - buf);
        else
            return -1;
    }
    int indexOf(const String s)
    {
        char *p = strstr(buf, s.buf);

        if (p != nullptr)

            return (p - buf);

        else

            return -1;

    }

    bool operator == (const String s)
    {
        return strcmp(buf, s.buf) == 0;
    }

    bool operator != (const String s)
    {
        return strcmp(buf, s.buf) != 0;
    }

    bool operator > (const String s)
    {
        return strcmp(buf, s.buf) > 0;
    }

    bool operator < (const String s)
    {
        return strcmp(buf, s.buf) < 0;
    }

    bool operator <= (const String s)
    {
        return strcmp(buf, s.buf) <= 0;
    }

    bool operator >= (const String s)
    {
        return strcmp(buf, s.buf) >= 0;
    }


    String operator +(const String s)
    {
	  String result;
      strncat(result.buf, buf, MAXLEN);
      strncat(result.buf, s.buf, MAXLEN - strlen(result.buf));
      return result;
    }

    String & operator +=(const String s)
    {
        strncat(buf, s.buf, MAXLEN - strlen(buf));
        return *this;
    }

    void print(ostream & out)
    {
        out<<buf;
    }

    void read(istream & in)
    {
        in>>buf;
    }

    ~String() = default;

private:
    bool in_bounds(int i)
    {
        return i>= 0 && i<strlen(buf);
    }
};

ostream & operator << (ostream & out, String s)
{
    s.print(out);
   return out;
}

istream & operator >>(istream & in, String & s)
{
    s.read(in);
    return in;
}