#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    int num=0;
    int Maxlen=0,len[200];
    char data[200][200];
    while(cin.getline(data[num],200))
    {
        len[num]=strlen(data[num]);
        if(Maxlen<len[num])
            Maxlen=len[num];
        num++;
    }
    for(int i=0;i<Maxlen;i++)
    {
        for(int j=num-1;j>=0;j--)
        {
            if(i<len[j])
                cout<<data[j][i];
            else
                cout<<' ';
        }cout<<"\n";
    }
    
    
    return 0;
}
