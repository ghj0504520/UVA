#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    
    while(cin>>n)
    {
        if(n==0)
            break;
            
        string cmd;
        int up=1 ,down=6 , left=3 ,right=4 ,front=2 ,back=5 ;
        while(n--)
        {
            cin>>cmd;
            int swap ;
            if(cmd=="north")
            {
                swap =front;
                front =up;
                up =back;
                back =down;
                down =swap;
            }
            else if(cmd=="east")
            {
                swap =right;
                right =up;
                up =left;
                left =down;
                down =swap;
            }   
            else if(cmd=="south")
            {
                swap =back;
                back =up;
                up =front;
                front =down;
                down =swap;
            }
            else if(cmd=="west")
            {
                swap =left;
                left =up;
                up =right;
                right =down;
                down =swap;
            }
            
        }cout<<up<<'\n';
        
        
    }
}
