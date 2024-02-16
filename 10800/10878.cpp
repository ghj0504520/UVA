#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    char ASCII;
    while( getline( cin, s ) ){
        if( s[0] == '_' )
            continue;
        ASCII = 0;
        int len=s.size();
        for( int i = 0 ; i < len ; i++ )
            if( s[i] == ' ' )
                ASCII *= 2;
            else if( s[i] == 'o' )
                ASCII = ASCII * 2 + 1;
        cout<<(char)ASCII;
    }
    return 0;
  }
