#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int segment_len;
    while(cin>>segment_len)
    {
        if(!segment_len)
            break;
        
        string data1,data2;
        cin>>data1>>data2;
        int len1=data1.length(),len2=data2.length();
        int segment[len1+1][len2+1],LCSdp[len1+1][len2+1];
        memset(segment,0,sizeof(segment));
        memset(LCSdp,0,sizeof(LCSdp));
        
        for(int i=1 ; i<=len1 ; i++)
        {
            for(int j=1 ; j<=len2 ; j++)
            {
                LCSdp[i][j]=max(LCSdp[i-1][j],LCSdp[i][j-1]);
                
                if(data1[i-1]==data2[j-1])                              //array-segment used to save the 
                {                                                       //length of continuous segment
                    segment[i][j]=segment[i-1][j-1]+1;
                }
                else 
                {
                    segment[i][j]=0;
                }
                
                if(segment[i][j] >= segment_len)                        //if the length of segment longer than
                {                                                       //the given length then use DP to 
                    for(int k=segment_len ; k<=segment[i][j] ; k++)     //calculate LCS which formed by segment
                    {
                        LCSdp[i][j]=max(LCSdp[i][j],LCSdp[i-k][j-k]+k);
                    }
                }
            }
        }cout<<LCSdp[len1][len2]<<'\n';
    }
    return 0;
}
