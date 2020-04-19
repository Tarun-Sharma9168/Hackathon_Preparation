#include<iostream>
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
         long long int prod=1;
         
         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         int zero_or_not=0;
         //int index_of_zero;
         vector<long long int> vv;
         for(int i=0;i<n;i++)
         {
             if(arr[i]==0)
             {
                 zero_or_not++;
                 //index_of_zero=i;
                 continue;
             }
             prod*=arr[i];
         }
         if(zero_or_not>1)
         {
            for(int i=0;i<n;i++)
            {
                cout<<"0"<<" ";
            }
         }
         else
         {
            long long result;
            for(int i=0;i<n;i++)
            {
                if(arr[i]==0)
                {
                result=prod/1;
                }
                else
                {
                    if(zero_or_not)
                    {
                        result=0;
                    }
                    else
                    result=prod/arr[i];
                }
                //cout<<result<<" ";
                vv.push_back(result);
            }
         }
         cout<<"\n";
    }
return 0;
}