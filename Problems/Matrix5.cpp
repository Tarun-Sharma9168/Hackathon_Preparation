 /*
Author Name:Tarun Sharma
Problem Name:Search of the element in the sorted row-column matrix....
             Very important problem intuition is starting from the top right corner and at every step removing the column
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define SIZE 1000
        int search( int n,int m, int x, int arr[SIZE][SIZE])
        {
                    // Your code here
                    int i=0;//starting row
                    int j=m-1;//starting column

                    //talking about some base cases
                    int smallest=arr[0][0];
                    int largest=arr[n-1][m-1]; 
                    if(x < smallest || x > largest)
                    {
                        return 0;
                    }
                    else
                    {
                           while( i<n && j>=0)
                           {
                               if(x == arr[i][j])
                               {
                                   return 1;
                               }

                               //Now start eliminating rows and columns ony by one
                               else if(x > arr[i][j])
                               {
                                   i++;
                               }
                               else
                               {
                                   j--;
                               }
                           }
                    }
                    return 0;
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
                        int n,m;
                        cin>>n>>m;
                        int arr[SIZE][SIZE];
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<m;j++)
                            {
                                cin>>arr[i][j];
                            }
                        }
                        int x;
                        cin>>x;
                        cout<<(search(n,m,x,arr))<<"\n";
				    }
				    return 0;
		}