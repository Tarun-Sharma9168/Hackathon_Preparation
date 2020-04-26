		/*
		     Problem Name:The Problem of A Grundy Number A Recursive Problem
                          we can find Mex using the data structure unordered_set by a simple function.
                          Remember this it is very important. 

		*/
#include<bits/stdc++.h>
using namespace std;
int calculate_mex(unordered_set<int> ss)
{
   int mex=0;
   while(ss.find(mex) != ss.end())
   {
       mex++;
   }

   return mex;
}
int Grundy_Number(int n)
{
    unordered_set<int> ss;
    if(n==0)
    {
        return 0;
    }
    ss.insert(Grundy_Number(n/2));
    ss.insert(Grundy_Number(n/3));
    ss.insert(Grundy_Number(n/6));

    return (calculate_mex(ss));
}
int main()
{
		    ios_base::sync_with_stdio(false);
		    cin.tie(nullptr);
		    cout.tie(nullptr);

		    freopen("input.txt","r",stdin);
		    //freopen("output.txt","w",stdout);

		    int t;
		    cin>>t;

		    while(t--)
		    {
                 int n;
                 cin>>n;

                 int ans=Grundy_Number(n);
                 cout<<ans<<"\n";
		    }
		    return 0;
}