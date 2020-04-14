#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
class Triplet
{
public:
       long long int gcd;
       long long int x;
       long long int y;
};
//Simple Recursive Function
Triplet extendedEuclid(long long int a,long long int b)
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
long long int MMInverse(long long int a,long long int m)
{
    Triplet ans=extendedEuclid(a,m);
    //cout<<"first"<<ans.x<<"\n";
    return (ans.x%m +m)%m;
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
        long long int a,b;
        long long int d;
        cin>>a>>b>>d;


        long long int g =__gcd(a,b);
        a=a/g;
        b=b/g;

        //handling the special cases

        if(d % g)
        {
            cout<<0<<"\n";
            continue;
        } 
        if(d==0)
        {
        //only one pair exist
            cout<<1<<"\n";
            continue;
        }
        d=d/g;
        //finding the bound for the x and y
        long long int bound_for_x=d/a;
        long long int bound_for_y=d/b;    

        long long int dd=((d%a) * MMInverse(b,a)%a)%a;
        //cout<<bound_for_y<<" "<<dd<<" "<<MMInverse(b,a)<<"\n";
        if( dd < 0 || dd > bound_for_y)
        {
            cout<<"0"<<"\n";
        }
        else
        { 
        long long int n=(d/b - (dd))/a;
        cout<<n+1<<"\n";
        }
    }
    return 0;
}