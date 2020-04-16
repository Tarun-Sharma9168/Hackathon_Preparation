#include<iostream>
using namespace std;
#define size 1000001
int *arr=new int[size];
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
            arr[j] = arr[j] * (double)((i - 1)/(double)i);
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
    int t;
    cin>>t;
    sieve();    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<arr[n]<<"\n";

    }
    return 0;
}
