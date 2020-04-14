#include<iostream>
#include<math.h>
using namespace std;
int count_factors(int n)
{
    int count=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i == sqrt(n))
            {
              count+=1;
            }
            else
            {
                count+=2;
            }
        }
    }
    return count;
}
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
        //int n=count_factors(n);
        int count=0;
        for(int i=2;i<=n;i++)
        {
            int n=count_factors(i);
            if(n==2)
            {
                count++;
            }
        }
        cout<<count<<"\n"; 
    }
    return 0;
}