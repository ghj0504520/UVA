#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t_ime ;
    while(cin>>t_ime)
    {
        for(int i = 1;i <= t_ime;i ++)
        {
            cout<<"Test #"<<i<<": ";
            char a,b;
            cin>>a>>b;
            int matrixSize;
            cin>>matrixSize;
            bool judge = 1;
            long long int matrix[matrixSize][matrixSize];
            for(int j=0;j<matrixSize;j++)
            {
                for(int k=0;k<matrixSize;k++)
                {
                    cin>>matrix[j][k];
                    if(matrix[j][k] < 0)
                    {
                        judge = 0;
                    }
                }
            }        
            for(int k=0;k<=matrixSize/2;k++)
            {
                for(int j=0;j<matrixSize;j++)
                {
                    if(matrix[k][j]!=matrix[matrixSize-1-k][matrixSize-1-j])   //careful
                    {
                        judge = 0;
                        break;
                    }
                }
            }
            if(judge ==0)
            {
                cout<<"Non-symmetric.\n";
            }
            else
            {
                cout<<"Symmetric.\n";
            }
        }
    }
    return 0;
}


