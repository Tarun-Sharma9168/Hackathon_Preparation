/*
    Maximum sum we have to generate of the equation i*a[i] that is why we have one another condition that is 
    we only rotate our and not sort....
    //Time limit Exceeded not the efficient one 
    O(n^2)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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
         int *copy=new int[n];
         long long sum=0;
         long long int max=-1e18;
         for(int i=1;i<n-1;i++)
         {
             sum=0;
             for(int j=0;j<n;j++)
             {
                 copy[j]=arr[(j+i)%n];
             }
             for(int k=0;k<n;k++)
             {
                  sum+=(copy[k]*k);
             }
             if(sum > max)
             {
                 max=sum;
             }
         }
         cout<<max<<"\n";
         delete[] arr;
         delete[] copy;
    }
return 0;
}