#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define Size 2000001
int arr[Size]={0};
void sieve()
{
       for(int i=1;i<Size;i++)
       {
         arr[i]=i;
       }
       bool bool_arr[Size]={0};
       //making of the lowest prime divisorr using the sieve approach 
       for(int i=2;i<=Size/2;i++)
       {   
          if(!bool_arr[i])
          {
          for(int j=2*i;j<Size;j+=i)
           {
               arr[j]=i;
               bool_arr[j]=1;
           }
          }
       }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("input.txt","r",stdin);
    
    int n;
    cin>>n;
    
    sieve();

    bool marked[n+1]={false};

    for(int i=n;i>=1;i--)
    {
        vector<int> it;
        
        if(marked[i])
        {
            continue;
        }
        int x=i;
        it.push_back(x);
        while(x != 1)
        {
        int lpd=arr[x];
        //cout<<"Lpd"<<lpd<<"\n";
        int j=i-lpd;
        while(j>=1)
        {
           if(!marked[j]) 
               { 
                 marked[j]=true;
                 it.push_back(j);
               }
           j=j-lpd;
        }
        while(x%lpd == 0)
        {
            x=x/lpd;
        }
        }
        sort(it.begin(),it.end(),greater<int>());
        for(int i=0;i<it.size();i++)
        {
            cout<<it[i]<<" ";
        }
        it.clear();
    }
return 0;
}