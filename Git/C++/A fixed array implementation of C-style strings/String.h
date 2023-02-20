#include <iostream>

#define MAXLEN 128
using namespace std;

{   
    int String::strlen(const char * s );
    char * String::strcpy(char * dest,const char * src );
    char * String::strncpy(char * dest,const char * src,int n );
    char * String::strncat(char * dest,const char * src,int n );
    int  String::strcmp(const char * left,const char * right );

    int  String::strncmp(const char * left,const char * right,int n );

    void String::reverse_cpy(char * dest,const char * src );
    char * String::strchr(char * str,char c );
    char * String::strstr(char * haystack,const char * needle );
    const char * String::strstr(const char * haystack,const char * needle );


    
    String(const String &s );

    String & operator =(const String & s );

    char & operator [](int index );
    
    size_t String::strlen(const char *s);
    
    String reverse();

    int String:: indexOf(const char c );

    int String::indexOf(const String s );

    bool String::operator ==(const String s );
    bool String::operator !=(const String s );
    bool String::operator >(const String s);
    bool String::operator <(const String s );
    bool String::operator <=(const String s );
    bool String::operator >=(const String s );

    String::operator + (const String s);

    String:: & operator += (const String s);

    void String::print(ostream & out );

    void String::read(istream &in);
   
    bool String::in_bounds(int i){
        return i >= 0 && i < strlen(buf);
    }
}

ostream & operator << ( ostream & out, String s){   
    s.print(out);
    return out;
}
istream & operator >> ( istream & in, String & s){
    s.read(in);
    return in;
}