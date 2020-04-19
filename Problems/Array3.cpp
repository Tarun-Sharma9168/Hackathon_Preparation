/*
Finding the maximum and then second maximum element
*/

#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
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

         if(n>1)
         {
         sort(arr,arr+n);
         int first_max=arr[n-1];
         int second_max;
         bool flag=false;
         for(int i=n-2;i>=0;i--)
         {
            if(arr[i]!=first_max)
            {
              second_max=arr[i];
              flag=true; 
              break;
            }
         }
         if(flag)
         cout<<first_max<<" "<<second_max<<"\n";
         else
         {
             cout<<first_max<<" "<<"-1"<<"\n";
         }  
         }
         else
         {
             cout<<"-1"<<"\n";
         }
    }
    return 0;
}