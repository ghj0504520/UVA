#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void s_ort(int *x,int *y)
{
    if(*y < *x)
    {
        int swap = *x;
        *x = *y;
        *y = swap; 
    }
}

int main()
{
    int inWidth,inHeight,inNum;
    while(cin>>inWidth>>inHeight>>inNum)
    {
        if(inWidth == inHeight && inHeight == inNum&& inWidth == 0)
            break;
        int sumArea = inWidth * inHeight;
        int inX_1,inY_1,inX_2,inY_2;
        
        bool area[inWidth][inHeight];
        memset(area,0,sizeof(area));
        for(int n = 0;n < inNum;n ++)
        {
            cin>>inX_1>>inY_1>>inX_2>>inY_2;
            s_ort(&inX_1,&inX_2);
            s_ort(&inY_1,&inY_2);
            for(int x = inX_1;x <= inX_2;x ++)
            {
                for(int y = inY_1;y <= inY_2;y ++)
                {
                    area[x-1][y-1] = 1; 
                }
            }
        }
        for(int x = 0;x < inWidth;x ++)
        {
            for(int y = 0;y < inHeight;y ++)
            {
                sumArea -= area[x][y]; 
            }
        }
        if(sumArea == 0)
        {
            cout<<"There is no empty spots.\n";
        }
        else if(sumArea == 1)
        {
            cout<<"There is one empty spot.\n";
        }
        else
        {
            cout<<"There are "<<sumArea<<" empty spots.\n";
        }
    }
    return 0;
}
