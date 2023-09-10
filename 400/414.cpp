#include <iostream>

using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
        getchar();
        if(!num)break;
        string line[50];
        int sum=0, minSpace=100;
        for(int i=0 ; i<num ; i++)
        {
            getline(cin,line[i]);

            int cur=0, len = line[i].length();
            for(int l=0 ; l<len ; l++)
            {
                if(line[i][l]==' '||line[i][l]=='B')
                    cur++;
            }

            minSpace=min(cur,minSpace);
            sum+=cur;
        }

        cout<<sum -minSpace*num<<"\n";

        
    }
    return 0;
}