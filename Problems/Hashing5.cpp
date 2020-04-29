 /*
Author Name:Tarun Sharma
Problem Name:Positive Negative Pair exists in the given array or not if yes print if not ignore the numbers..
*/
		#include<bits/stdc++.h>
		using namespace std;
        bool comp(pair<int,int> &p1,pair<int,int> &p2)
        {
            return p1.first < p2.first;
        }
        void printPairs(int *arr, int n)
        {
                 // code here
                 map<int,int> mp;
                 bool flag=false;
                 for(int i=0;i<n;i++)
                 {
                     mp[arr[i]]++;
                 }
                 vector<pair<int,int>> vv;
                 for(int i=0;i<n;i++)
                 {
                     if(mp[arr[i]] && mp[-arr[i]])
                     {
                         flag=true;
                         vv.push_back({abs(arr[i]),-abs(-arr[i])});
                         mp[arr[i]]=0;
                         mp[-arr[i]]=0;
                     }
                 }
                 if(vv.size() > 0)
                 {
                 sort(vv.begin(),vv.end(),comp);
                 for(auto it=vv.begin();it!=vv.end();it++)
                 {
                     cout<<it->first<<" "<<it->second<<" ";
                 }
                 }
                 else
                 {
                     cout<<0;
                 }
                 
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

                       int *arr=new int[n];
                       for(int i=0;i<n;i++)
                       {
                           cin>>arr[i];
                       }
                       printPairs(arr,n);
                       cout<<"\n";
                       delete[] arr;
				    }
				    return 0;
		}   