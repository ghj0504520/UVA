#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> G[30];
vector<char> Res;
bool vis[30]={0},P[30]={0};

void DFS(int num)
{
    //cout<<num+'A'<<" ";
    vis[num]=1;
    int len = G[num].size();
    for(int i=0 ; i<len ; i++)
        if(!vis[G[num][i]])DFS(G[num][i]);
    Res.push_back(num+'A');
}

int main()
{
    string in1,in2;
    set<int> CH;
    cin>>in1;
    while(cin>>in2)
    {
        if(in2=="#")break;

        for(int i=0 ; in1[i]>0 && in2[i]>0 ; i++)
        {
            CH.insert(in1[i]-'A');
            CH.insert(in2[i]-'A');

            if(in1[i] != in2[i])
            {
                G[in1[i]-'A'].push_back(in2[i]-'A');
                P[in2[i]-'A'] =1;
                //cout<<in1[i]-'A'<<"-->"<<in2[i]-'A'<<'\n';
                break;
            }
        }
        in1 = in2;
    }

    set<int>::iterator it;
    for(it=CH.begin();it!=CH.end();it++)
    {   
        //cout<<*it<<" ";
        if(!P[*it])DFS(*it);
    }

    int len = Res.size();
    for(int i=len-1 ; i>=0 ; i--)
        cout<<Res[i];
    cout<<"\n";
    return 0;
}