#include <stdio.h>

int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("Case %d: ",i+1);
		int len;
		scanf("%d",&len);
		char data[len];
		scanf("%s",data);
		
		int sum=0;
		for(int f=0;f<len;f++)
		{
			if(data[f]=='.')
			{
				sum++;
				f+=2;
			}
		}printf("%d\n",sum);
	}
	return 0;
}
