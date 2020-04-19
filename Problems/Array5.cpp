/*
Count possible triangles O(n^2)
Sorting can done our work and make our algorithm from n^3 to n^2
*/
#include<iostream>
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
        sort(arr,arr+n);
        int sum=0;
        
        for(int i=0;i<n-2;i++)
        {
            int k=i+2;
            for(int j=i+1;j<n-1;j++)
            {
                while(k<n && arr[i]+arr[j]>arr[k])
                {
                    ++k;
                }
                if(k>j)
                {
                    sum+=(k-j-1);
                }
            }
        }
    cout<<sum<<"\n";
    }
    return 0;
}
