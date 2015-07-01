#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        
        for(int i=0;i<t;i++)
        {
            if(i!=0)
                cout<<'\n';
            int n;
            cin>>n;
            string data[10000],data_2[10000];
            for(int i=0;i<n;i++)
            {
                cin>>data[i];
                data_2[i]=data[i];
                sort(data[i].begin(),data[i].end());
            }
            string ask,ask_2;
            while(cin>>ask)
            {
                
                if(ask=="END")
                    break;
                ask_2=ask;
                sort(ask.begin(),ask.end());
                cout<<"Anagrams for: "<<ask_2<<'\n';
                int t=1;
                bool find=0;
                for(int j=0;j<n;j++)
                {
                    if(data[j]==ask)
                    {
                        cout<<"  "<<t<<") "<<data_2[j]<<'\n';
                        find=1; 
                        t++;
                    }
                   
                }
                if(find==0)
                    cout<<"No anagrams for: "<<ask_2<<'\n';
            }
            
        }
    }
}
