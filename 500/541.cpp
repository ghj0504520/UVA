#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num;
	int matrix[105][105]={0};
	while(cin>>num,num)
	{
		int row[105]={0},col[105]={0};
		int rowCnt=-1,colCnt=-1;
		int mode=-1;
		for(int i=0 ; i<num ; i++)
		{
			for(int j=0 ; j<num ; j++)
			{
				cin>>matrix[i][j];
				row[i]+=matrix[i][j];
				col[j]+=matrix[i][j];
			}
		}
		for(int i=0 ; i<num ; i++)
		{
			if(row[i]%2)
			{
				if(rowCnt != -1 )
				{
					mode=2;
					break;
				}
				else
				{
					rowCnt=i;
				}
			}
		}
		if(mode!=2)
			for(int i=0 ; i<num ; i++)
			{
				if(col[i]%2)
				{
					if(colCnt != -1 )
					{
						mode=2;
						break;
					}
					else
					{
						colCnt=i;
					}
				}
			}
		if(mode!=2)
		{
			if(rowCnt!=-1 &&colCnt!=-1)
			{
				mode=1;
			}
			else if(rowCnt==-1 &&colCnt==-1)
			{
				mode=0;
			}
			else
			{
				mode=2;
			}
		}
		if(!mode)
		{
			cout<<"OK\n";
		}
		else if(mode==1)
		{
			cout<<"Change bit ("<<rowCnt+1<<","<<colCnt+1<<")\n";
		}
		else if(mode==2)
		{
			cout<<"Corrupt\n";
		}
	}
	return 0;
}