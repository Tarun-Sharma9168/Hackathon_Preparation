 /*
Author Name:Tarun Sharma
Problem Name:Printing the Matrix in a diagonal form whether it is updiagonal or downward but you have to print
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define MAX 1000
        void printMatrixDiagonal(int arr[MAX][MAX], int n)
        {
                    //Your code here
                    int i=0;
                    int j=0;
                    //updiagonal j++ i-- Try To Remember it is important
                    bool isup=true;
                    int k;
                    
                    for(k=0;k<n*n;)
                    {
                         if(isup)
                          {
                             for(;i>=0 && j<n;i--,j++)
                             {
                                 cout<<arr[i][j]<<" ";
                                 k++;
                             }
                             if( i < 0 && j <= n-1)//top left case
                             {
                                 i=0;
                             }
                             if(j == n)//top right case should handle carefully
                             {
                                 i=i+2;
                                 j--;

                             }
                          }
                          else
                          {     //downward diagonal 
                                for(;i<n && j>=0;i++,j--)
                                {
                                    cout<<arr[i][j]<<" ";
                                    k++;
                                }
                                if(j<0 && i<=n-1)//bottom right case
                                {
                                    j=0;
                                }
                                if(i==n)//bottom left case
                                {
                                    j=j+2;
                                    i--;
                                }
                          }
                          isup=!isup;
                    }
        }
		int main()
		{
				    ios_base::sync_with_stdio(false);
				    cin.tie(nullptr);
				    cout.tie(nullptr);

				    freopen("input.txt","r",stdin);
				    //freopen("output.txt","w",stdout);

				    int t;
				    cin>>t;

				    while(t--)
				    {
                       int arr[MAX][MAX]={0};

                       int n;
                       cin>>n;

                       for(int i=0;i<n;i++)
                       {
                           for(int j=0;j<n;j++)
                           {
                               cin>>arr[i][j];
                           }
                       }
                       printMatrixDiagonal(arr,n);
                       cout<<"\n";
				    }
				    return 0;
		}