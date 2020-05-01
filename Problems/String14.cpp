 /*
Author Name:Tarun Sharma
Problem Name:print all the permutations of a string .It is done a little by recursion,backtracking and the swap method..
*/
		#include<bits/stdc++.h>
		using namespace std;
        void make_perm(string s,int l,int r,vector<string> &vv)
        {
            //vector<string> vv;
            //base case that is single digit so no need to swap 
            if( l==r)
            {
                     vv.push_back(s);

            }
             for(int i=l;i<=r;i++)
             {
                  swap(s[l],s[i]);
                  make_perm(s,l+1,r,vv);
                  swap(s[l],s[i]);//to make the string as it is backtracking
                  //cout<<s<<"\n";
             }
        }
        void permutation(string S)
        {
               //Your code here
               vector<string> vv;
               int l=0;
               int r=S.length()-1;
               make_perm(S,l,r,vv);
              
               sort(vv.begin(),vv.end());
               for(auto x:vv)
               {
                   cout<<x<<" ";
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
                          permutation(s);
                          cout<<"\n";
				    }
				    return 0;
		}