 /*
Author Name:Tarun Sharma
Problem Name:Typical hashing problem that is given a number x .
Determine whether or not there exist two elements in A whose sum is exactly X.
*/
		#include<bits/stdc++.h>
		using namespace std;
        bool keypair(vector<int> array, int x) 
        {
            // Your code goes here
            unordered_map<int,int> mp;
            for(auto t:array)
            { 
                  mp[t]++;
            }
            for(auto b:array)
            {
                if(mp[b])
                {
                    mp[b]--;
                    if(mp[x-b])
                    {
                        return true;
                    }
                }
            }
          return false; 
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
                          int n,x;
                          int p;
                          cin>>n>>x;
                          vector<int> vv;
                          for(int i=0;i<n;i++)
                          {
                              cin>>p;
                              vv.push_back(p);
                          }
                        if(keypair(vv,x))
                        cout<<"Yes"<<"\n";
                        else
                        {
                            cout<<"No"<<"\n";
                        }
                        
				    }
				    return 0;
		}