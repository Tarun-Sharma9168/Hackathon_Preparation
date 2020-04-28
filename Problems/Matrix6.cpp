 /*
Author Name:Tarun Sharma
Problem Name:
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define MAX 1000
        void printMat(int arr[MAX][MAX],int row,int col)
        {
            set<string> ss;
              //Your code here
              for(int i=0;i<row;i++)
              {
                  string s="";
                  for(int j=0;j<col;j++)
                  {
                     s=s+to_string(arr[i][j]);
                     s+=" "; 
                  }
                  if(ss.find(s) ==ss.end())
                  {
                      ss.insert(s);
                      cout<<s<<"$";
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
                          int r,c;
                          cin>>r>>c;
                          int arr[MAX][MAX];
                          for(int i=0;i<r;i++)
                          {
                              for(int j=0;j<c;j++)
                              {
                                  cin>>arr[i][j];
                              }
                          }

                          printMat(arr,r,c);
				    }
				    return 0;
		}