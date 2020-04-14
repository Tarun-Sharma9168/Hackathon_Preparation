#include<bits/stdc++.h>
using namespace std;
class Triplet
{
public:
       int gcd;
       int x;
       int y;
};
//Simple Recursive Function
Triplet extendedEuclid(int a,int b)
{
    if(b==0)
    {
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    Triplet smallAns = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x   = smallAns.y;
    ans.y   = smallAns.x-(a/b)*smallAns.y;
    return ans;
}
int MMInverse(int a,int m)
{
    Triplet ans=extendedEuclid(a,m);
    return ans.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;  
    while(t--)
    {
         int a;
         cin>>a;
         int b;
         cin>>b;
         Triplet ans=extendedEuclid(a,b);
         cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<"\n";
         int A;
         int M;
         cin>>A>>M;
         int pp=MMInverse(A,M);
         cout<<pp<<"\n";
    }
return 0;
}