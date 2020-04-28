 /*
Author Name:Tarun Sharma
Problem Name:Kth element in the spiral representation of the Matrix
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define MAX 1000
        int findK(int arr[MAX][MAX], int n, int m, int pp)
        { 
                //Your code here
                vector<int> vv;
                          int row_start=0;
                          int col_start=0;
                          int row_end=n-1;
                          int col_end=m-1;
                          int k;
                          while(row_start <= row_end && col_start <= col_end)
                          {
                          for(k=col_start;k<=col_end;k++)
                          {
                              //cout<<arr[row_start][k]<<" ";
                              vv.push_back(arr[row_start][k]);
                          }
                          row_start++;
                          for(k=row_start;k<=row_end;k++)
                          {
                              //cout<<arr[k][col_end]<<" ";
                              vv.push_back(arr[k][col_end]);
                          }
                          col_end--;
                          if(row_start <= row_end)
                          {
                          for(k=col_end;k>=col_start;k--)
                          {
                              //cout<<arr[row_end][k]<<" ";
                              vv.push_back(arr[row_end][k]);
                          }
                          row_end--;
                          }
                          if(col_start <= col_end)
                          {
                          for(k=row_end;k>=row_start;k--)
                          {
                              //cout<<arr[k][col_start]<<" ";
                              vv.push_back(arr[k][col_start]);
                          }
                          col_start++;
                          }
                          }

                          return vv[pp-1];
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
                        int n,m,k;
                        cin>>n>>m>>k;
                        int arr[MAX][MAX];
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<m;j++)
                            {
                                cin>>arr[i][j];
                            }
                        }
                    cout<<findK(arr,n,m,k)<<"\n";
				    }
				    return 0;
		}