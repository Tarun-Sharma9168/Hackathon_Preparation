 /*
Author Name:Tarun Sharma
Problem Name:Spirally traversing the matrix.It is one of the important problem.
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define SIZE 30
        void spirallyTraverse(int m, int n, int **arr)
        {
               //Printing the matrix spirally
               //first we define some important indexes that we have to change dynamically
               //int k;//starting of the row index
               //int m;//ending of the row index
               //int l;//starting of the column index
               //int n;//ending of the column index

               int i,k=0,l=0;

               while( k<m && l<n)
               {
                   for(i=l;i<n;i++)
                   {
                       cout<<arr[k][i]<<" ";
                   }k++;

                   for(i=k;i<m;i++)
                   {
                       cout<<arr[i][n-1]<<" ";
                   }n--;
                   
                   if(k<m)
                   {
                      for(i=n-1;i>=l;i--)
                      {
                         cout<<arr[m-1][i]<<" ";
                      }m--;
                   }

                   if(l<n)
                   {
                       for(i=m-1;i>=k;i--)
                       {
                           cout<<arr[i][l]<<" ";
                       }
                       l++;
                   }
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
                         int m,n;
                         cin>>m>>n;
                         int **arr=new int*[m];

                         for(int i=0;i<m;i++)
                         {
                             arr[i]=new int[n];
                         }
                         for(int i=0;i<m;i++)
                         {
                             for(int j=0;j<n;j++)
                             {
                                 cin>>arr[i][j];
                             }
                         }
                         spirallyTraverse(m,n,arr);
                         cout<<"\n";
				    }
				    return 0;
		}