#include<iostream>
using namespace std;
#define size 750001
#define MOD (long long int)(1e9+7)
int *Set=new int[size];
void precompute2(int *arr,int *Set,int n)
{
      for(int i=0;i<n;i++)
      {
            Set[arr[i]]=1;
      }
}
void precompute1(int *arr,int n)
{
   
    for(int i=0;i<size;i++)
    {
         Set[i]=0;
    }
    precompute2(arr,Set,n);
    for(int i=1;i<size;i++)
    {
        if(Set[i])
        {
           for(int j=2*i;j<size;j+=i)
           {
               if(Set[j]) 
               {
                   Set[j]+=Set[i];
               }
           } 
        }
    }

    //testing purpose printing to debug 
   /* for(int i=1;i<100;i++)
    {
         cout<<Set[i]<<" ";
    } 
    cout<<"\n";
    */
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
        int arr[n]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        precompute1(arr,n); 
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
              ans=(ans+Set[arr[i]])%MOD;  
        }
        cout<<ans<<"\n";
    }
    return 0;
}