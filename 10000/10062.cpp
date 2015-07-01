#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct ascii
{
    int letter;
    int num;
};

bool cmp(const ascii i,const ascii j)
{
    return i.num<j.num || ((i.num==j.num)&&(i.letter>j.letter));
};

int main()
{
    ascii save[128];
    char data[1001];
    bool judge=0;
    while(cin.getline(data,1001))
    {
        if(judge!=0)
            cout<<'\n';
        for(int i=0;i<128;i++)
        {
            save[i].letter=i;
            save[i].num=0;
        }
        int len=strlen(data);
        for(int i=0;i<len;i++)
        {
            int a=(int)data[i];
            save[a].num++;
        }
        sort(save,save+127,cmp);
        for(int i=0;i<128;i++)
        {
            if(save[i].num!=0)
            {
                cout<<save[i].letter<<" "<<save[i].num;
                cout<<'\n';
            }
        }
        judge=1;
    }
    
}
