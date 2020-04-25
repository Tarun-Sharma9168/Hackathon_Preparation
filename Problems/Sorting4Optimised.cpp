		/*
		     Problem Name:Closet problem but doing in O(n)
             Solution count number of 0s,1s and 2s
		*/
#include<bits/stdc++.h>
using namespace std;
void segragate012(int arr[], int n)
{
    //Your code here
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            cnt0++;
        }
        if(arr[i]==1)
        {
            cnt1++;
        }
        if(arr[i]==2)
        {
            cnt2++;   
        }
    }

    for(int i=0;i<n;i++)
    {
        if(i < cnt0)
        {
           arr[i]=0;
        }
        else if(i >= cnt0 && i<cnt1+cnt0)
        {
           arr[i]=1;
        }
        else
        {
            arr[i]=2;
        }
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
                segragate012(arr,n);
                for(int i=0;i<n;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
		    }
		    return 0;
}