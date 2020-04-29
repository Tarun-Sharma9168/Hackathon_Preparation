 /*
Author Name:Tarun Sharma
Problem Name:First non repeatting alphabet typical hashing problem... 
*/
		#include<bits/stdc++.h>
		using namespace std;
       int NO_OF_CHARS=256;
string find(string str) {
    pair<int, int> arr[NO_OF_CHARS]; 
  
    for (int i = 0; str[i]; i++) 
    { 
        (arr[str[i]].first)++; 
        arr[str[i]].second = i; 
    } 
  
    int res = INT_MAX; 
    for (int i = 0; i < NO_OF_CHARS; i++) 
  
        if (arr[i].first == 1) 
            res = min(res, arr[i].second); 
  if(res==INT_MAX)
  return "-1";

    return string(1,str[res]); 
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
                         string s;
                         cin>>n;
                         cin>>s;
                         cout<<find(s)<<"\n";
				    }
				    return 0;
		}