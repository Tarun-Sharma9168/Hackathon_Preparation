/*
Finding the equilibrium point in an array which should be in O(n) solution
#Using two pointer approach is the good idea in this scenerio
#Remember this it is a good one
*/
#include<iostream>
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
        int i=-1;
        int j=n;
        long long sum1=0;
        long long sum2=0;
        while(i<j)
        {
            if(sum1==sum2)
            {
                i++;j--;
                sum1+=arr[i];
                sum2+=arr[j];
            }
            else if(sum1<sum2)
            {
                i++;
                sum1+=arr[i];
            }
            else if(sum1>sum2)
            {
                j--;
                sum2+=arr[j];
            }
        }
        if(sum1==sum2 && i==j) 
        {
            cout<<(i+1)<<"\n";
        }
        else
        {
            cout<<"-1"<<"\n";
        }
    }
    return 0;
}
