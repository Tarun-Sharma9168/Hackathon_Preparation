 /*
Author Name:Tarun Sharma
Problem Name:Relative Sorting 
*/
		#include<bits/stdc++.h>
		using namespace std;
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
                        int m;
                        cin>>n>>m;
                        int *arr1=new int[n];
                        int *arr2=new int[m];

                        for(int i=0;i<n;i++)
                        {
                            cin>>arr1[i];
                        }

                        for(int i=0;i<m;i++)
                        {
                            cin>>arr2[i];
                        }

                        map<int,int> mp;

                        for(int i=0;i<n;i++)
                        {
                            mp[arr1[i]]++;
                        }
                        vector<int> vv;
                        for(int i=0;i<m;i++)
                        {
                            if(mp[arr2[i]])
                            {
                              while(mp[arr2[i]])
                              {
                                vv.push_back(arr2[i]); 
                                mp[arr2[i]]--;                                 
                              }
                            }
                        }
                       /* for(auto it=mp.begin();it!=mp.end();it++)
                        {
                            cout<<it->first<<" "<<it->second<<"\n";
                        }
                        */
                       for(auto it=mp.begin();it!=mp.end();it++)
                       {
                           if(it->second)
                           {
                               while(it->second)
                               {
                                   vv.push_back(it->first);
                                   it->second--;
                               }
                           }
                       }

                       for(auto x:vv)
                       {
                           cout<<x<<" ";
                       }
                        cout<<"\n";
				    }
				    return 0;
		}