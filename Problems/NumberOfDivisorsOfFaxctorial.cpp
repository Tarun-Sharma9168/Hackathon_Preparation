#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define Size 50001
#define MOD (long long int)(1e9+7)
vector<int> prime_or_not()
{
    bool arr[Size];
    for(int i=0;i<=Size;i++)
    {
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=Size;i++)
    {
        if(arr[i])
        {
             int j=i*i;
             while(j<=Size)
             {
                 arr[j]=false;
                 j=j+i;
             }
        }
    }
    vector<int> vv;
    for(int i=2;i<=50000;i++)
    {
        if(arr[i])
        {
            vv.push_back(i); 
        }
    }
    return vv;
}
int no_of_divisors(vector<int> primes,int n)
{
    long long int mul=1;
    for(int i=0;(i<primes.size() && primes[i] <= n);i++)
    {
            long long int sum=0;
            int k=1;
            while(pow(primes[i],k) <=n)
            {
                 sum=sum+(n/pow(primes[i],k));
                 k++;
            }
            mul= (mul%MOD * (sum+1)%MOD)%MOD ;
    }
    return mul;
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
       long long int n;
       cin>>n;

       vector<int> vv=prime_or_not();
       
       
       long long int ans=no_of_divisors(vv,n);
       
       cout<<ans<<"\n";
    }
    return 0;
}