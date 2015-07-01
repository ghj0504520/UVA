#include<iostream>
using namespace std;
int main()
{
    int t_ime;
    while(cin>>t_ime)
    {
        for(int i=0;i<t_ime;i++)
        {
            int d_ata[3];
            cin>>d_ata[0]>>d_ata[1]>>d_ata[2];
            bool judge =1;
            for(int i=0;i<3;i++)
            {
                if(d_ata[i]>20)
                {
                    judge=0;
                    break;
                }
            }
            cout<<"Case "<<i+1<<": ";
            judge==0? cout<<"bad":cout<<"good";
            cout<<'\n';
        }
    }
    return 0;
}
