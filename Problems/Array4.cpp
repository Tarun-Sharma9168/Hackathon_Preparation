/*
Min distance between two elements
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long minDist(long long arr[], long long n, long long x, long long y) {
    // add code here.

    long long min=n;
    long long k=INT32_MIN;
    long long l=INT32_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)k=i;
        if(arr[i]==y)l=i;
        if(abs(k-l) < min)
        {
            min=abs(k-l);
        }
    }
        if( min ==n)
        {
            return -1;
        }
        else{
            return min;
        } 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    freopen("input.txt","r",stdin);

      int t;
      cin>>t;

      while(t--)
      {
          long long n;
          cin>>n;

          long long *arr=new long long[n];

          for(int i=0;i<n;i++)
          {
              cin>>arr[i];
          }
          long long x,y;
          cin>>x>>y;
          cout<<minDist(arr,n,x,y)<<"\n";
      }
return 0;
}
