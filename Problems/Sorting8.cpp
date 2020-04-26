		/*
		     Problem Name:Given arrival and departure times of all trains that reach a railway station. 
             Your task is to find the minimum number of platforms required for the railway station so that no train waits.
             Our plan is to use the stack data structure to solve this problem.  
             Prefix sum use in this very interesting code just see once...
		*/
#include<bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
	// Your code here

    int time[2400]={0};
    int max=0;
    for(int i=0;i<n;i++)
    {
        time[arr[i]]++;
        time[dep[i]+1]--;
    }
    for(int i=1;i<2400;i++)
    {
         time[i]+=time[i-1];
    }
    for(int i=1;i<2400;i++)
    {
        if(time[i] > max)
        {
            max=time[i];
        }
    }
    return max;
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
                  int *arrival=new int[n];
                  int *departure=new int[n];
                  for(int i=0;i<n;i++)
                  {
                     cin>>arrival[i];
                  }
                  for(int i=0;i<n;i++)
                  { 
                     cin>>departure[i];
                  }
                  int ans=findPlatform(arrival,departure,n);
                  cout<<ans<<"\n";
		    }
		    return 0;
}