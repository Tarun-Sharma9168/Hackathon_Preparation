 /*
     Author Name: Tarun Sharma
     Problem Name: Boundary traversal in the matrix...
*/
		#include<bits/stdc++.h>
		using namespace std;
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
                          int n,m;
                          cin>>n>>m;
                          
                          int **arr=new int*[n];
                          
                          for(int i=0;i<n;i++)
                          {
                              arr[i]=new int[m];
                          }
                          
                          for(int i=0;i<n;i++)
                          {
                                for(int j=0;j<m;j++)
                                {
                                   cin>>arr[i][j];
                                }
                          }
                          int row_start=0;
                          int col_start=0;
                          int row_end=n-1;
                          int col_end=m-1;
                          int k;
                          
                          for(k=col_start;k<=col_end;k++)
                          {
                              cout<<arr[row_start][k]<<" ";
                          }
                          row_start++;
                          for(k=row_start;k<=row_end;k++)
                          {
                              cout<<arr[k][col_end]<<" ";
                          }
                          col_end--;
                          if(row_start <= row_end)
                          {
                          for(k=col_end;k>=col_start;k--)
                          {
                              cout<<arr[row_end][k]<<" ";
                          }
                          row_end--;
                          }
                          if(col_start <= col_end)
                          {
                          for(k=row_end;k>=row_start;k--)
                          {
                              cout<<arr[k][col_start]<<" ";
                          }
                          col_start++;
                          }
                          cout<<"\n";
				    }
				    return 0;
        }