#include <stdio.h>

void reverse(long long int num)
{
	long long int re=0;
	while(num>0)
	{
		re=re*10+num%10;
		num/=10;
	}
	printf("%lld\n",re);
}
int main()
{
	long long int num,i,ask;
	scanf("%lld",&num);
	for(i=0;i<num;i++)
	{
		scanf("%lld",&ask);
		if(ask==1)
		{
			printf("1\n");
			continue;
		}
		long long int j,data=0;
		for(j=9;j>=2;)
		{
			if(!(ask%j))
			{
				ask/=j;
				data=10*data+j;
			}
			else 
			{
				j--;
			}
			
		}
		if(ask!=1)
			printf("-1\n");
		else 
			reverse(data);
	}
	return 0;
}
