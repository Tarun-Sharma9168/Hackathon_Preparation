 /*
Author Name:Tarun Sharma
Problem Name:Needle in the HayStack find can be a good idea but in real question becomes a little differen also..
So be ready..
*/
		#include<bits/stdc++.h>
		using namespace std;
        int NeedleinHaystack(string haystack, string needle) 
        {
             // Your code goes here 
             int result=haystack.find(needle);
             return result;
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
                      string h;
                      string n;
                      cin>>h>>n;
                      int ans=h.find(n);
                      cout<<ans<<"\n";
				    }
				    return 0;
		}