#include<iostream>
using namespace std;
#define size 1000001
#define qsize 11
int **nfactor=new int*[qsize];
void precompute2(int *arr)
{
  for(int i=0;i<qsize;i++)
  {
    nfactor[i]=new int[size];  
  }
  for(int i=0;i<qsize;i++)
   {
       for(int j=0;j<size;j++)
       {
           nfactor[i][j]=0;
       }
   }
   for(int i=0;i<11;i++)
   {
      for(int j=1;j<size;j++)
      {
          if(arr[j] == i)
          {
              nfactor[i][j]=nfactor[i][j-1]+1;
          }
          else
          {
              nfactor[i][j]=nfactor[i][j-1];
          }
      }
   }
  /*for(int i=0;i<11;i++)
   {
       for(int j=0;j<11;j++)
       {
           cerr<<nfactor[i][j]<<" ";
       }
       cerr<<"\n";
   }
   */
   
}
void precompute1()
{
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }
   for(int i=2;i<size/2;i++)
   {
       if(!arr[i])
       {
         for(int j=i;j<size;j+=i)
         {
              arr[j]++;
         }
       }
   }
   /*for(int i=10000;i<=11000;i++)
   {
       cerr<<arr[i]<<" ";
   }
cout<<"\n";
*/

//here comes the precomputation number 2
precompute2(arr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    precompute1();
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
       // cout<<"First"<<"\n";
        //cout<<nfactor[n][a-1]<<"\n";
        //cout<<nfactor[n][b]<<"\n";
        long long int ans=nfactor[n][b]-nfactor[n][a-1];
        cout<<ans<<"\n";
        //cout<<"\n";
    }
    return 0;
}