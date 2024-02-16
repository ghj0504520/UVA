#include<iostream>
#include<cmath>
using namespace std;
bool check(char c, string m[])
{
    if(m[0][0]==c&&m[0][1]==c&&m[0][2]==c)return 1;
    if(m[1][0]==c&&m[1][1]==c&&m[1][2]==c)return 1;
    if(m[2][0]==c&&m[2][1]==c&&m[2][2]==c)return 1;
    if(m[0][0]==c&&m[1][0]==c&&m[2][0]==c)return 1;
    if(m[0][1]==c&&m[1][1]==c&&m[2][1]==c)return 1;
    if(m[0][2]==c&&m[1][2]==c&&m[2][2]==c)return 1;
    if(m[0][0]==c&&m[1][1]==c&&m[2][2]==c)return 1;
    if(m[0][2]==c&&m[1][1]==c&&m[2][0]==c)return 1;
    return 0;
}

int main()
{
    int n, s=0;
    cin>>n;

    while(n--)
    {
        string m[4];
        cin>>m[0];
        cin>>m[1];
        cin>>m[2];
        
        int xc=0,oc=0;
        for(int i=0 ; i<4 ; i++)
            for(int j=0 ; j<4 ; j++)
            {
                if(m[i][j]=='X')
                    xc++;
                else if(m[i][j]=='O')
                    oc++;
            }
        bool xw=check('X',m),ow=check('O',m);
        
        if((xw&&!ow&&xc==oc+1)||(!xw&&ow&&xc==oc)||
            (!xw&&!ow&&((xc==oc)||(xc==oc+1))))
                cout<<"yes"; 
        else cout<<"no";
        cout<<"\n";
    }
    return 0;
}
