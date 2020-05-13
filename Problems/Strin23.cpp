 /*
Author Name:Tarun Sharma
Problem Name:Rearrange the letters such that no two letters are the same.....
*/
		#include<bits/stdc++.h>
		using namespace std;
        string rearrangeString(string str)
        {
	      //Your code here
          
          map<char,int> mp;
          for (auto x:str)
          {
              mp[x]++;
          }
          int max=0;
          for(auto it=mp.begin();it!=mp.end();it++)
          {
               if(it->second > max)
               {
                   max=it->second;
               }
          }
          if( max > (str.length()-max))
          {
              return "0";
          }
          else
          {
              return "1";
          }
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
                         string s;
                         cin>>s;
                         cout<<rearrangeString(s)<<"\n";
				    }
				    return 0;
		}