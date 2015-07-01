#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        for(int k=0;k<t;k++)
        {
            if(k!=0)
                cout<<'\n';
            int x,y;
            cin>>x>>y;
            getchar();
            char mp[x][y],line[100000];
            for(int i=0;i<x;i++)
            {
                cin.getline(line,100000,'\n');      //careful of input because of space
                for(int j=0;j<y;j++)
                {
                    mp[i][j]=line[j];
                }
            }
            int s_x,s_y,dir=0;     //personally data and 0=N,1=E,2=S,3=W
            cin>>s_x>>s_y;
            s_x--;
            s_y--;
            char in ;
            cin>>in;
            
            while(in !='Q')
            {
                
                switch (in)
                {
                    case 'R': 
                        dir==3? dir=0:dir++;
                        break;
                    case 'L':
                        dir==0? dir=3:dir--;
                        break;
                    case 'F':
                        if(dir==0)
                        {
                            if(mp[s_x-1][s_y]!='*')
                                s_x--;
                        }
                        else if(dir==1)
                        {
                            if(mp[s_x][s_y+1]!='*')
                                s_y++;
                        }
                        else if(dir==2)
                        {
                            if(mp[s_x+1][s_y]!='*')
                                s_x++;
                        }
                        else if(dir==3)
                        {
                            if(mp[s_x][s_y-1]!='*')
                                s_y--;
                        }
                        break;
                    default:;
                        
                }
                cin>>in;
                
            }
            
            cout<<s_x+1<<' '<<s_y+1<<' ';
            switch (dir)
            {
                case 0:
                    cout<<'N';
                    break;
                case 1:
                    cout<<'E';
                    break;
                case 2:
                    cout<<'S';
                    break;
                case 3:
                    cout<<'W';
                    break;
            }cout<<'\n';
            
                
        }
    }
}
