#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string dataCase;
    int t_ime;
    while(cin>>t_ime)
    {
        getchar();
        while(t_ime--)
        {
            getline(cin,dataCase);
            int len=dataCase.length();
            int M = 0,F = 0;
            for(int i = 0;i < len;i ++)
            {
                if(dataCase[i] == 'M')
                    M++;
                else if(dataCase[i] == 'F')
                    F++;
            }
            (M == F && M != 1)? cout<<"LOOP": cout<<"NO LOOP";
            cout<<'\n';
        }
    }
    return 0;
}
