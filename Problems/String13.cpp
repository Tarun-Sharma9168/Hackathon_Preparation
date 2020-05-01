 /*
Author Name:Tarun Sharma
Problem Name:Rearrangement of the strinh such that no two character is adjacent to each other....
             Problem is solved using priority_queue() data structure where we follow the greedy approach and try to generate the whole 
             String following certain criteria.
*/
		#include<bits/stdc++.h>
		using namespace std;
        string rearrangeString(string s)
        {
                string op="";
                //Your code here.
                int hash[26];
                memset(hash , 0 , sizeof(int) * 26);                
                
                for(int i=0;i<s.length();i++)
                {
                     hash[(int)s[i]-97]++;
                }

                priority_queue<pair<int,char>> pp;
                
                for(int i=0;i<26;i++)
                {
                    if(hash[i] > 0)
                    {
                        pp.push(make_pair(hash[i],char(i+97)));
                    }
                }
                
                pair<int,char> temp=make_pair(100,'@');
                
                for(int i=0;i<s.length();i++)
                {
                    pair<int,char> p = pp.top();
                    
                    pp.pop();

                    if(i>0 && temp.first>0)
                    {
                        pp.push(temp);
                    }
                    
                    op=op+p.second;
                    temp.second=p.second;
                    temp.first=p.first-1;
                }
                return op;
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

                          int old_length=s.length();
                          
                          int ch[26];
                          
                          memset(ch,0,sizeof(int)*26);
                          
                          for(int i=0;i<s.length();i++)
                          {
                              ch[(int)s[i]-97]++;
                          }

                          s=rearrangeString(s);

                          int flag=1,ff=0;
                          int ch2[26];
                          
                          memset(ch2,0,sizeof(int) * 26);

                          for(int i=0;i<s.length();i++)
                          {
                              ch2[(int)s[i]-97]++;
                          }

                          if(s.length() != old_length)
                          {
                              cout<<"0"<<"\n";
                          }

                          else{
                          
                              for(int i=0;i<s.length();i++)
                              {
                                  if(ch[i]!=ch2[i])
                                  {
                                      ff=1;
                                      break;
                                  }
                              }
                              if(ff==1)
                              {
                                     cout<<"0"<<"\n";
                              }
                              else{
                                  if(s != "")
                                  {
                                      for(int i=0;i<s.length();i++)
                                      {
                                          if(i>0)
                                          {
                                              if(s[i-1] == s[i])
                                              {
                                                  flag=0;
                                              }
                                          }
                                      }
                                      if(flag == 1)
                                      {
                                          cout<<"1"<<"\n";
                                      }
                                      else
                                      {
                                          cout<<"0"<<"\n";
                                      }
                                  }
                                  else
                                  {
                                      cout<<"0\n";
                                  }
                              }
                          }
}
				    return 0;
		}