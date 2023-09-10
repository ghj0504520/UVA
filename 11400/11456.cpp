#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> cars;
        cars.reserve(n*2);

        int e;
        for (int i=0 ; i<n ; i++)
        {
            cin>>e;
            cars[n+i]=e;
            cars[n-1-i]=e;
        }

        vector<int> LIS;
        for (int i=0 ; i<2*n ; i++)
        {
            LIS.push_back(1);
        }

        int ans=0;
        for (int i=0 ; i<2*n ; i++)
        {
            for (int j=i+1 ; j<2*n ; j++)
            {  
                if(cars[i]>cars[j])
                    LIS[j] = max(LIS[i]+1,LIS[j]);
            }
            if(ans<LIS[i])
                ans=LIS[i];
        }
        cout<<ans<<"\n";

    }
    return 0;
}