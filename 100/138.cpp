#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    double hn=1;
    for(int i=0; i<10 ; i++)
    {
        bool isA =0;
        while(!isA)
        {
            ++hn;
            double ln = ((double)-1+sqrt(1+8*hn*hn))/2;
            if(ln ==floor(ln))
            {
                printf("%10.0lf%10.0lf\n", hn, ln);
                isA = true;
            }
        }
    }    
}
