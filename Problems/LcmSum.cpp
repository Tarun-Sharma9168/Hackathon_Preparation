#include<iostream>
using namespace std;
#define size 1000001
long long int *arr=new long long int[size];
void sieve()
{
   for(int i=0;i<size;i++)
   {
       arr[i]=i;
   }
   for(int i=2;i<size;i++)
   {
       if(arr[i] == i)
       {
       for(int j=2*i;j<size;j+=i)
       {
            arr[j] = (arr[j] *(i - 1))/i;
       }
       arr[i]=i-1;
       }
   }
   for(int i=1;i<=10;i++)
   {
       cout<<arr[i]<<" "; 
   }
   cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    sieve();
    int n;
    cin>>n;
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=(arr[i] * i);
        }
    }
    sum=sum+1;
    long long int main_result=((double)n*sum)/2;
    cout<<main_result<<"\n";
    return 0;
}