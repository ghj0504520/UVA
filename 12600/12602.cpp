#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        char car[100];
        while(t--)
        {
            cin>>car;
            char letter[50];
            int num;
            sscanf(car,"%[^-]-%d",letter, &num);
            int a=26*26,b=26,c=1;
            int first=(letter[0]-65)*a+(letter[1]-65)*b+(letter[2]-65)*c;
            abs(first-num)<=100 ? cout<<"nice\n":cout<<"not nice\n";
        }
    }
}
