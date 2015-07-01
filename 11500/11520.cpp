#include <stdio.h>
#include <ctype.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("Case %d:\n",i+1);
		int num;
		scanf("%d",&num);
		getchar();
		char mp[num][num];
		for(int r=0;r<num;r++)
		{	for(int c=0;c<num;c++)
			{
					scanf("%c",&mp[r][c]);
			}getchar();
		}
		for(int r=0;r<num;r++)
		{	for(int c=0;c<num;c++)
			{
				if(isalpha(mp[r][c]))
					continue;
				else
				{
					char ch='A';
					int check=0;
					while(ch<='Z')
					{
						check=0;
						if(r-1<0)
							check=1;
						else
						{
							if(mp[r-1][c]!=ch)
								check=1;
							else
							{
								ch=ch+1;
								continue;
							}
						}
						if(c-1<0)
							check=1;
						else
						{
							if(mp[r][c-1]!=ch)
								check=1;
							else
							{
								ch=ch+1;
								continue;
							}
						}
						if(r+1>=num)
							check=1;
						else
						{
							if(mp[r+1][c]!=ch)
								check=1;
							else
							{
								ch=ch+1;
								continue;
							}
						}
						if(c+1>=num)
							check=1;
						else
						{
							if(mp[r][c+1]!=ch)
								check=1;
							else
							{
								ch=ch+1;
								continue;
							}
						}
						if(check)
							break;
					}	
					mp[r][c]=ch;
				}
			}
		}
		for(int r=0;r<num;r++)
		{	
			for(int c=0;c<num;c++)
			{
				printf("%c",mp[r][c]);
			}printf("\n");
		}
	}
	return 0;
}
