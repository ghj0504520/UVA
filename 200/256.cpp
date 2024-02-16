#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int qn[4][100], s[4]={0};
    for(int i=0 ; i<10000; i++)
    {
        for(int j=0 ; j<10000; j++)
        {
            int shift=1;
            for(int l=0 ; l<4; l++)
            {
                shift*=10;
                if(((i+j)*(i+j)==i*shift+j)&&
                    i / shift == 0 && j / shift == 0)
                    qn[l][s[l]++] = i*shift+j;
            } 
        }
    }
    
    int n;
    while(cin>>n)
    {
        int idx=n/2-1;
        for(int i=0 ; i<s[idx];i++)
            printf( "%0*d\n", n, qn[idx][i] );;
    }
    return 0;
}
