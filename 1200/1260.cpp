#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<int> sale;
        int n,tmp;
        cin>>n;
        while(n--)
        {
            cin>>tmp;
            sale.push_back(tmp);
        }
        int sum=0;
        n=sale.size();
        for(int i=1 ; i<n; i++)
        {
            for(int j=0 ; j<i; j++)
            {
                if(sale[i]>=sale[j])
                    sum++;
            }    
        }
        cout<<sum<<"\n";
    }
    return 0;
}
