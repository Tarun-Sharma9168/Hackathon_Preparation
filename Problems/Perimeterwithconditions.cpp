#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
bool check_triangle(int a,int b,int c)
{
     if(a+b > c && b+c > a && a+c >b)
     {
         return true;
     }
     return false;
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
        sort(arr,arr+n,greater<int>());
        bool flag=false;
        
        int a,b,c;
        for(int i=0;i<=n-3;i++)
        {
            if(check_triangle(arr[i],arr[i+1],arr[i+2]))
            {
                //cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<"\n";
                flag=true;
                a=arr[i];
                b=arr[i+1];
                c=arr[i+2];
                break;
            }  
        }

        if(flag)
        {
            cout<<a<<" "<<b<<" "<<c<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}
