/*
Sorted subsequence of length 3 
It is just having the basic intuition that if you are the smallest or if you are the not the largest it means 
if you have one smaller element on the left and one larger element on the right so you have your answer 
we do this by taking two arrays one is smaller that have knowledge about smaller elements on the left
second is the larger array that is the larger element knowledge on the right
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
bool issubsequence(vector<int> &v1,vector<int> &v2,int n,int m)
{
    if(m==0)return true;
    if(n==0)return false;

    if(v1[n-1] == v2[m-1])
    {
        return issubsequence(v1,v2,n-1,m-1);
    }
    return issubsequence(v1,v2,n-1,m);
}
vector<int> find3Numbers(vector<int> arr, int n) {
    // Your code here

    int min=0;
    int max=n-1;

    int *smaller=new int[n];
    int *larger=new int[n];
    
    smaller[0]=-1;
    larger[n-1]=-1;
    
    for(int i=1;i<n;i++)
    {
         if(arr[i]<=arr[min])
         {
             min=i;
             smaller[i]=-1;
         }
         else
         {
             smaller[i]=min;
         }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=arr[max])
         {
             max=i;
             larger[i]=-1;
         }
         else
         {
             larger[i]=max;
         }
    }
    vector<int> vv;
    for(int i=0;i<n;i++)
    {
        if(smaller[i]!=-1 && larger[i]!=-1)
        {
           vv.push_back(arr[smaller[i]]);
           vv.push_back(arr[i]);
           vv.push_back(arr[larger[i]]);
           return vv;
        }
    }
    return vv;
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

        vector<int> arr;
        
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            arr.push_back(a);
        }
        vector<int> ans=find3Numbers(arr,n);

        if(!ans.empty() && ans.size()!=3)
        {
            cout<<"-1"<<"\n";
        }
        
        if(ans.empty())
        {
            cout<<0<<"\n";
        }
        else if((ans[0]<ans[1]) && (ans[1]<ans[2])  && issubsequence(arr,ans,n,ans.size()))
        {
            cout<<1<<"\n";
        }
        else
        {
            cout<<-1<<"\n";
        }
    }
    return 0;
}