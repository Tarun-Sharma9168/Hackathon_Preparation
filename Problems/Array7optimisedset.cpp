/*
This problem can be solved by using multiset and upperbound function in c++StL 
It is an very easy approach
But Again it took O(n^2) time
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
long long int inversionCount(long long arr[],long long n)
{  
    multiset<int> mp;
    mp.insert(arr[0]);
    

    int inv_count=0;

    for(int i=1;i<n;i++)
    {
        mp.insert(arr[i]);
        auto it=mp.upper_bound(arr[i]);
        inv_count+=distance(it,mp.end());
    }
return inv_count;
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
    long long int n;
    cin>>n;

    long long int *arr=new long long int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long inversion=inversionCount(arr,n);
    cout<<inversion<<"\n";
    }
    return 0;
}