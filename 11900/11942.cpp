#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        printf("Lumberjacks:\n");
        for(int i=0;i<n;i++)
        {
            int data[10];
            for(int j=0;j<10;j++)
            {
                scanf("%d", &data[j]);
            }
            bool judge=1;
            if(data[0]>data[1])
            {
                for(int j=1;j<9;j++)
                {
                    if(data[j]<data[j+1])
                    {
                        judge =0;
                        break;
                    }
                }
            }
            else if(data[0]<data[1])
            {
                for(int j=1;j<9;j++)
                {
                    if(data[j]>data[j+1])
                    {
                        judge =0;
                        break;
                    }
                }
            }
            
            judge ==1? printf("Ordered\n"):printf("Unordered\n");
        }
    }
}
