#include<iostream>
using namespace std;
void subarraySum(long long int *arr,int n,int s)
{
     int i=0;
     int j=0;
     long sum=0;
     int flag=0;
     while(i<=n)
     {
          if(sum < s)
          {
              sum+=arr[i++];
          }
          else if(sum > s)
          {
              sum-=arr[j++];
          }
          if(sum == s)
          {
              flag=1;
              break;
          }
     }
     if(flag)
     cout<<j+1<<" "<<i;
     else 
     cout<<"-1";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
          int n;
          cin>>n;
          int sum;
          cin>>sum;
          long long int *arr=new long long int[n];
          for(int i=0;i<n;i++)
          {
              cin>>arr[i];
          }
         subarraySum(arr,n,sum);
         cout<<"\n";
    }
    return 0;
}