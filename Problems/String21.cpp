 /*
Author Name:Tarun Sharma
Problem Name:Interleaved string very nice problem
*/
		#include<bits/stdc++.h>
		using namespace std;
  bool isInterleave(string a, string b, string c) 
{ 
    // Base Case: If all strings are empty 
    if ((a.empty() && b.empty() && c.empty())) 
        return true; 
  
    // If C is empty and any of the two strings is not empty 
    if (c.empty()) 
        return false; 
  
    // If any of the above mentioned two possibilities is true, 
    // then return true, otherwise false 
    return ((c[0] == a[0]) && isInterleave(a.substr(1), b, c.substr(1))) || ((c[0] == b[0]) && isInterleave(a, b.substr(1), c.substr(1))); 
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
                         string x,y,c;
                         cin>>x>>y>>c;

                         if(isInterleave(x,y,c))
                         {
                             cout<<1<<"\n";
                         }
                         else
                         {
                             cout<<0<<"\n";
                         }
				    }
				    return 0;
		}