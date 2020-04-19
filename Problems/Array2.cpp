/* Finding the third largest element */
#include<iostream>
#include<map> 
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
            //All elements are distinct in the array
            int *arr=new int[n];
            for(int i=0;i<n;i++)
            {
               cin>>arr[i];
            }
            //sort(arr,arr+n);
            if(n>=3)
            {
                sort(arr,arr+n);
                cout<<arr[n-3]<<"\n";
            }
            else
            {
                cout<<"-1"<<"\n";
            }
    }
    return 0;
}
