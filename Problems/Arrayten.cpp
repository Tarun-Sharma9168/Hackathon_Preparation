/*
  can SubArray in the shape of mountain or not
  It needs the O(n) preprocessing and then the O(1) order query retrieval
  Making your own understanding for the right[L] >= left[R]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int preprocess(int *arr,int n,int left[],int right[])
{
    left[0]=0;
    int lastincr=0;

    for(int i=1;i<n;i++)
    {
          if(arr[i] > arr[i-1])
          {
              lastincr=i;
          }
          left[i]=lastincr;
    }
    right[n - 1] = n - 1; 
    int firstDecr = n - 1;
    for(int i=n-2;i>=0;i--)
    {
         if (arr[i] > arr[i + 1]) 
            firstDecr = i; 
        right[i] = firstDecr; 
    } 
}
bool subarrayMountain(int *arr,int *left,int *right,int L,int R)
{
      return (right[L] >= left[R]);
}
vector<bool> processQueries(int a[],int n,vector<pair<int,int>> &queries,int q)
{
    int *left=new int[n];
    int *right=new int[n];
    
    preprocess(a,n,left,right);
    vector<bool> ans;
    for(auto it=queries.begin();it!=queries.end();it++)
    {
        int L=it->first;
        int R=it->second;
        ans.push_back(subarrayMountain(a,left,right,L,R));  
    } 
    return ans; 
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

      int q;
      cin>>q;
      vector<pair<int,int>> vp;
      for(int i=0;i<q;i++)
      {
          int a,b;
          cin>>a>>b;
          vp.push_back(make_pair(a,b));
      }
      vector<bool> ans=processQueries(arr,n,vp,q);
      for(int i=0;i<ans.size();i++)
      {
          if(ans[i])
          {
              cout<<"Yes"<<"\n";
          }
          else
          {
              cout<<"No"<<"\n";
          }
      }
    }
    return 0; 
}