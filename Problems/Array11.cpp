/*
Finding the Duplicates in the array using map can be a good idea
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
void printDuplicates(int arr[], int n) {
    bool flag=false;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second > 1)
        {
            flag=true;
            cout<<it->first<<" ";
        }
    }
    if(!flag)
    {
        cout<<"-1";
    }
    cout<<"\n";
}
using namespace std;
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
        printDuplicates(arr,n);
    }
    return 0;
}