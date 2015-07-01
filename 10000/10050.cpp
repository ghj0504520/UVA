#include<iostream>

using namespace std;
int main()
{
    int run;
    cin>>run;
    while(run--)
    {
        int day;
        cin>>day;
        int num;
        cin>>num;
        int data[num];
        for(int i=0;i<num;i++)
            cin>>data[i];
        int hartal=0;
        for(int d=1;d<=day;d++)
        {
            if(!(d%7==6||d%7==0))
            {
                for(int it=0;it<num;it++)
                {
                    if(d%data[it]==0)
                    {
                        hartal++;
                        break;
                    }
                }
            }
        }cout<<hartal<<'\n';
        
    }
    return 0;
}
