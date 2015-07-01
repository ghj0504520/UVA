#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int run_t;
    while(cin>>run_t)
    {
        for(int i=0;i<run_t;i++)
        {
            int n;
            cin>>n;
            int location[n];
            for(int j=0;j<n;j++)
            {
                cin>>location[j];
            }
            sort(location,location+n);
            cout<<(location[n-1]-location[0])*2<<endl;
            
        }
    }

}
