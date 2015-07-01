#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char input[100];
    while(scanf("%s",input)!=EOF)
    {
        int num;
        if(input[0]=='-')
            break;
        else if(input[1]=='x')
        {
            sscanf(input,"0x%X",&num);
            printf("%d\n",num);
        }
        else
        {
            sscanf(input,"%d",&num);
            printf("0x%X\n",num);
        }
    }
}
