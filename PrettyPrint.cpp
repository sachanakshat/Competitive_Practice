#include <iostream>
using namespace std;

int main() {
	
	int n = 3, i,j;
	int b = 2*n-1;
	cout<<b<<"\n";
	int v[b][b];
	
// 	for(i=n; i>=1; i--)
//     {
//         for(j=n; j>=1; j--)
//         {
//             v[n-i][n-j] = i>j?i:j;
//         }
//         for(j=n; j<=b; j++)
//         {
//             v[n-i][2+j] = i>j?i:j;
//         }
//     }
    
//     for(i=2; i<=n; i++)
//     {
//         for(j=n; j>=1; j--)
//         {
//             v[2+i][n-j] = i>j?i:j;
//         }
//         for(j=2; j<=n; j++)
//         {
//             v[2+i][2+j] = i>j?i:j;
//         }
//     }

    for(i=0; i<b; i++)
    {
        for(j=0; j<b; j++)
        {
            v[i][j] = 0;
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            // cout<<"j,i = "<<j<<","<<i<<"\n";
            v[j][i] = n-i;
            // cout<<"b-i-1,j = "<<b-i-1<<","<<j<<"\n";
            v[b-i-1][j] = n-i;
            // cout<<"b-j-1,b-i-1 = "<<b-j-1<<","<<b-i-1<<"\n";
            v[b-j-1][b-i-1] = n-i;
            // cout<<"i,b-j-1 = "<<i<<","<<b-j-1<<"\n";
            v[i][b-j-1] = n-i;
            
            // cout<<"j,i = "<<j<<","<<i<<"\n";
            v[i][j] = n-i;
            // cout<<"b-i-1,j = "<<b-i-1<<","<<j<<"\n";
            v[j][b-i-1] = n-i;
            // cout<<"b-j-1,b-i-1 = "<<b-j-1<<","<<b-i-1<<"\n";
            v[b-i-1][b-j-1] = n-i;
            // cout<<"i,b-j-1 = "<<i<<","<<b-j-1<<"\n";
            v[b-j-1][i] = n-i;
        }
    }
    
    for(i=0; i<b; i++)
    {
        for(j=0; j<b; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
