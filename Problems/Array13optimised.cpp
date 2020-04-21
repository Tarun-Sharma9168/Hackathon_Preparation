#include<iostream>
using namespace std;
int max_sum(int arr[],int n)
{
//Your code here
int sum=0;
int sum1=0;
int max=-1e9;
for(int i=0;i<n;i++)
{
   sum+=arr[i];
   sum1+=(i*arr[i]);
}
int *dif=new int[n];
for(int j=1;j<n;j++)
{
    dif[j]=sum-n*arr[n-j];
}
int *Rsum=new int[n];
Rsum[0]=sum1;

for(int i=1;i<n;i++)
{
    Rsum[i]=Rsum[i-1]+dif[i];
}

for(int i=0;i<n;i++)
{
    if(Rsum[i]> max)
    {
        max=Rsum[i];
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
        int ans=max_sum(arr,n);
        cout<<ans<<"\n";
    }
    return 0;   
}
