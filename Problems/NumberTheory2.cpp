#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
 
    int n;
    cin>>n;
    bool arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i])
        {
             int j=i*i;
             while(j<=n)
             {
                 arr[j]=false;
                 j=j+i;
             }
        }
    }
    int count=0;
    for(int i=2;i<=n;i++)
    {
        if(arr[i])
        { 
             count++;
        } 
    }
    cout<<count<<"\n";
    return 0;
}