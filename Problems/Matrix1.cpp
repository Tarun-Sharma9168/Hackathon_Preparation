 /*
Author Name:Tarun Sharma
Problem Name:Inplace rotate square matrix by 90 degrees in anticlockwise direction.The Most important part is to maintain the no extra space 
              requirement which is completed by rotating it one by one element using only one temporary variable.


              Algorithm:Very important

              There is N/2 squares or cycles in a matrix of side N. Process a square one at a time. Run a loop to traverse the matrix 
              a cycle at a time, i.e loop from 0 to N/2 – 1, loop counter is i
              Consider elements in group of 4 in current square, rotate the 4 elements at a time. So the number of such groups in a cycle is
               N – 2*i.
              So run a loop in each cycle from x to N – x – 1, loop counter is y
              The elements in the current group is (x, y), (y, N-1-x), (N-1-x, N-1-y), (N-1-y, x), now rotate the these 4 elements, i.e 
              (x, y) <- (y, N-1-x), (y, N-1-x)<- (N-1-x, N-1-y), (N-1-x, N-1-y)<- (N-1-y, x), (N-1-y, x)<- (x, y)
              Print the matrix.
              This (n-1-x) && (n-1-y) is very important try to keep in mind.....
*/
		#include<bits/stdc++.h>
		using namespace std;
        void rotate(int **arr,int n)
        {
             //first of all the outer loop that is number of cycles that is n/2

             for(int x=0;x<n/2;x++)
             {   
                 //second loop is number of groups of 4 in each cycle that is n-2*i
                 for(int y=0;y<n-1-x;y++)
                 {  
                    int temp_mem=arr[x][y]; 

                    arr[x][y]=arr[y][n-1-x];

                    arr[y][n-1-x]=arr[n-1-x][n-1-y];

                    arr[n-1-x][n-1-y]=arr[n-1-y][x];

                    arr[n-1-y][x]=temp_mem;   
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
                        int n;
                        cin>>n;

                        int **arr=new int*[n];

                        for(int i=0;i<n;i++)
                        {
                            arr[i]=new int[n];
                        }

                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                cin>>arr[i][j];
                            }
                        }
                        rotate(arr,n);

                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                cout<<arr[i][j]<<" ";
                            }
                            cout<<"\n";
                        }
                    //freeing up the memory;
                    for(int i=0;i<n;i++)
                    {
                        delete[] arr[i];
                    }
				    }
				    return 0;
		}