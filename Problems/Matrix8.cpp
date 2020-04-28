 /*
Author Name:Tarun Sharma

Problem Name:
             Max Area Rectangle 
             That is one of the problem which uses dp as well as maximum area in histograms.
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define MAX 1000
        int maxhist(int arr[MAX],int n)
        {
              stack<int> result;
              int top_val;
              int max_area=0;
              int area=0;
              int i=0;
              while(i < n)
              {
                 if(result.empty() || arr[result.top()] <= arr[i])
                 {
                     result.push(i++);//index we are pushing and not the actual value
                 }
                 else{
                      top_val = arr[result.top()]; 
                      result.pop(); 
                      area = top_val * i; 
  
                      if (!result.empty()) 
                      area = top_val * (i - result.top() - 1); 
                      
                      max_area = max(area, max_area); 
                 }

              }
              while (!result.empty()) { 
                top_val = arr[result.top()]; 
                result.pop(); 
                area = top_val * i; 
                
                if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
  
                max_area = max(area, max_area); 
              } 
    return max_area; 
        }
    int maxArea(int arr[MAX][MAX], int n, int m) 
        {
           int result=maxhist(arr[0],m);
           for(int i=1;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   if(arr[i][j])
                   {
                       arr[i][j]+=arr[i-1][j];
                   }
               }
               result=max(result,maxhist(arr[i],m));
           }
           return result;
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
                          int arr[MAX][MAX];
                          for(int i=0;i<n;i++)
                          {
                              for(int j=0;j<m;j++)
                              {
                                  cin>>arr[i][j];
                              }
                          }
                          cout<<maxArea(arr,n,m)<<"\n";
				    }
				    return 0;
		}