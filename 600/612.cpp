#include <stdio.h>
#include <string.h>

int sort_level(char data[]);
void string_sort(int print[],int sort_flag[],int Size);
int main()
{
	int t,r;
	scanf("%d",&t);
	for( r=0;r<t;r++)
	{
		if(r!=0)printf("\n");
		char in[200][60];
		int num,len;
		scanf("%d%d",&len,&num);
		for(int i=0;i<num;i++)
		{
			scanf("%s",in[i]);
		}
		int sort_refer[200]={0};
		for(int i=0;i<num;i++)
		{
			sort_refer[i]=sort_level(in[i]);
		}
		/*
		for(int i=0;i<num;i++)
		{
			printf("%d\n",sort_refer[i]);
		}
		*/
		int print[200];
		string_sort(print,sort_refer,num);
		for(int i=0;i<num;i++)
		{
			printf("%s\n",in[print[i]]);
		}
		
			
	}
	return 0;
}
void string_sort(int print[],int sort_flag[],int Size)
{
	int i,j;
	int check[1000]={0};
	for(i=0;i<Size;i++)
	{
		int minval=10000,mindex;
		for(j=0;j<Size;j++)
		{
			if(sort_flag[j] < minval && !check[j])
			{
				mindex=j;
				minval=sort_flag[j];
			}
		}
		print[i]=mindex;
		check[mindex]=1;
	}
	//for(int i=0;i<Size;i++)
		//printf("%d ",print[i]);
}

int sort_level(char data[])
{
	int num=0;
	for(int i=0;i<strlen(data);i++)
	{
		for(int j=i+1;j<strlen(data);j++)
		{
			if(data[i]>data[j])
				num++;
		}
	}//printf("%d",num);
	
	return num;
}
