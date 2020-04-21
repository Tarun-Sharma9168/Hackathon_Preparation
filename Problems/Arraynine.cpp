#include<iostream>
#include<algorithm>
#include<set>
#include<map>
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
        for(int i=0;i<n;i+=2)
        {
            if(i+1 < n)
            {
                swap(arr[i],arr[i+1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}