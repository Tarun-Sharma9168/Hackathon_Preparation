#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void make_string(string b)
{
    cout<<b<<"\n";
}
long long int helper_mod(long long int a,string b)
{
    //long long int ans=0;
    
     long long int div=0;
     for(int i=0;i<b.length();i++)
     {
         div = ( div*(long long int)10 + (b[i]-'0'))%a;
     }
        return div;
}
long long int advanced_gcd(long long int a, long long int  b)
{
  if(!a){
      return b; 
  }
  return advanced_gcd(b%a,a);
}
long long int gcd_large(long long int a,string b)
{
    long long int bb=helper_mod(a,b);
    return advanced_gcd(a,bb);
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
        long long int a;
        string b;
        
        cin>>a;
        cin>>b;
        if(!a)
        {
            cout<<b<<"\n";
        }
        else{
        long long int ans=gcd_large(a,b);
        cout<<ans<<"\n";
        }
    }
    return 0;
}