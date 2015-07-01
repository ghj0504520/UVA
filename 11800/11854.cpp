#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    long long side[3];
    while(cin>>side[0]>>side[1]>>side[2])
    {
        if(!side[0]&&!side[1]&&!side[2])
            break;
        sort(side ,side+3);
        if(side[2]*side[2]==side[0]*side[0]+side[1]*side[1])
        {
            cout<<"right\n";
        }else
            cout<<"wrong\n";
    }
    return 0;
}
