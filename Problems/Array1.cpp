#include<bits/stdc++.h>
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
         vector<int> digit;
         while(n)
         {
            int p=n%10;
            if(p==0)
            {
                digit.push_back(5);
            }
            else
            {
                digit.push_back(p);
            }
            n=n/10;
         }
         int sum=0;
         int mul=1;
         for(int i=0;i<digit.size();i++)
         {
              sum=sum+mul*digit[i];
              mul*=10;
         }
         cout<<sum<<"\n";
    }
    return 0;
}