#include <iostream>

using namespace std;
int L[105][105],R[105][105],U[105][105];
char M[105][105];
int main()
{
    int r,c;
    while(cin>>r>>c)
    {
        if(!r&&!c)break;
        for(int i=1 ; i<=r ; i++)
            for(int j=0 ; j<c ; j++)
                cin>>M[i][j];

        int ans=0;
        for(int j=0 ; j<c ; j++)
        {
            U[0][j]=0;
            L[0][j]=0;
            R[0][j]=c-1;
        }

        for(int i=1; i<=r ; i++)
        {
            int l=-1,r=c;
            for (int j = 0; j < c; j++) {
				if (M[i][j] == '0') {
					U[i][j] = U[i - 1][j] + 1;  
					L[i][j] = max(l+1, L[i - 1][j]);
				}
				else {  
					l = j;
					U[i][j] = 0;
					L[i][j] = 0;
					R[i][j] = 0;
				}
			}
			for (int j = c-1; j >=0; j--) {
				if (M[i][j] == '0') {
					if (M[i - 1][j] == '1') { // prevent select 0 value when using min()
						R[i][j] = r - 1; 
					}
					else {
						R[i][j] = min(r - 1, R[i - 1][j]);
					}	

                    ans=max(ans,U[i][j]*(R[i][j]-L[i][j]+1));
				}
				else    r = j;
			}
        }

        cout<<ans<<"\n";
    }
    return 0;
}