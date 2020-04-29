 /*
Author Name:Tarun Sharma
Problem Name:Subarray with equal 1's and 0's.
             First thing that you have to remember is making 0 to -1
             then you just have to store different sum available and if it repeats while calculating just
             add their previous value to the count.
*/
		#include<bits/stdc++.h>
		using namespace std;
        int countSubarrWithEqualZeroAndOne(int arr[], int n){ 
             map<int,int> mp; 
            int sum=0; 
            int count=0; 
            for (int i = 0; i < n; i++) { 
            //Replacing 0's in array with -1 
            if (arr[i] == 0) 
                arr[i] = -1; 
  
            sum += arr[i]; 
  
            //If sum = 0, it implies number of 0's and 1's are 
            //equal from arr[0]..arr[i] 
            if (sum == 0) 
                count++; 
  
            if (mp[sum]) 
                count += mp[sum]; 
            if(mp[sum]==0) 
                mp[sum]=1; 
            else
                mp[sum]++; 
  
        } 
  return count; 
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

                          int *arr=new int[n];

                          for(int i=0;i<n;i++)
                          {
                              cin>>arr[i];
                          }
                          cout<<countSubarrWithEqualZeroAndOne(arr,n)<<"\n";
				    }
				    return 0;
		}