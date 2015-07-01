#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        int data[num];
        for(int i=0;i<num;i++)
            cin>>data[i];
        sort(data,data+num);
        int sum=0,flag=1;
        for(int i=num-1;i>=0;i--)
        {
            
            if(!(flag%3))
            {
                sum+=data[i];
                flag=0;
            }flag++;
        }cout<<sum<<"\n";
    }
    return 0;
}
