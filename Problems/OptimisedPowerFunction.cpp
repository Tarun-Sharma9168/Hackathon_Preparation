/*
                Time Complexity is O(logn + 1)
                Approx :: O(logn) base 2
*/

#include<iostream>
using namespace std;
long long int power(long long x,long long n)
{
    if(x==0)
    {
        return 0;
    }
     if(n==0)
     {
         return 1;
     }
     if(n&1)
     {
         long long  value=x*power(x,n-1);
         return value;
     }
     else
     {
         long long value=power(x,n/2);
         return (value*value);
     }
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
              long long int x;
              long long int n;
              cin>>x>>n;
              cout<<power(x,n)<<"\n";
          }
return 0;
}