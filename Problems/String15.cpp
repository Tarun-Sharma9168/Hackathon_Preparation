 /*
Author Name:Tarun Sharma
Problem Name:Reversing the string but not actually reversing the words...
*/
		#include<bits/stdc++.h>
		using namespace std;
        void reverseWords(char *s)
        {
                vector<string> vv;
                string str="";
                int i=0;
                while(s[i]!='\0')
                {
                    if(s[i] !='.')
                    str=str+s[i];
                    else
                    {
                        vv.push_back(str);
                        str="";
                    }
                    i++;
                }
                vv.push_back(str);
                str=""; 
                int no_of_dots=vv.size()-1;
                string ans="";
                reverse(vv.begin(),vv.end());
                i=0;
                for(i=0;i<vv.size()-1;i++)
                {
                    ans=ans+vv[i]+'.';
                }
                ans=ans+vv[i];
                cout<<ans<<"\n";
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
                         char *s;
                         cin>>s;
                         reverseWords(s);
				    }
				    return 0;
		}