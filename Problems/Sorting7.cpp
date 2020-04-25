		/*
		     Problem Name:Top K frequent element in an array.And if the frequency of two numbers are same then higher number wil be given 
             higher preference.
             We will solve it by doing little preprocessing 

		*/
#include<bits/stdc++.h>
using namespace std; 
struct Block
{
    int value=0;
    int id;
};
bool comp(Block &b1,Block &b2)
{
    if(b1.value == b2.value)
    {
        return (b1.id > b2.id);
    }
        return b1.value > b2.value;
}
vector<int> TopK(vector<int>& array, int k) 
{         
          int n=array.size();
          Block arr[10001];
          for(int i=0;i<n;i++)
          {
              arr[array[i]].id=array[i];
              arr[array[i]].value++;
          }  
          sort(arr,arr+10001,comp);
          vector<int> ans;
          /*for(int i=0;i<k;i++)
          {
                cout<<arr[i].id<<"   "<<arr[i].value<<"\n";             
          }
          cout<<"\n";
          */
          for(int i=0;i<k;i++)
          {
                ans.push_back(arr[i].id);              
          }
          return ans;
}
int main()
{
		    ios_base::sync_with_stdio(false);
		    cin.tie(nullptr);
		    cout.tie(nullptr);

		    freopen("input.txt","r",stdin);
		    //freopen("output.txt","w",stdout);

		    int t;
		    cin>>t;

		    while(t--)
		    {
                int n;
                cin>>n;
                vector<int> vv;
                    
                int element;
                for(int i=0;i<n;i++)
                {
                     cin>>element;
                     vv.push_back(element);
                }
                int k;
                cin>>k;
                vector<int> ans=TopK(vv,k);
                for(auto x:ans)
                {
                    cout<<x<<" ";
                }
             cout<<"\n";
		    }
		    return 0;
}