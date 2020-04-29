 /*
Author Name:Tarun Sharma
Problem Name:four sum equal to k .Same two pointer approach solves your problem
*/
		#include<bits/stdc++.h>
		using namespace std;
        vector<vector<int> > fourSum(vector<int> &a, int k) {
     if (a.size() < 4) return {};
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 3; ++i) {
        
        if (a[i] > 0 && a[i] > k) break;
       
        if (i > 0 && a[i] == a[i - 1]) continue;
        for (int j = i + 1; j < a.size() - 2; ++j) {
          
            if (j > i + 1 && a[j] == a[j - 1]) continue;

            int left = j + 1;
            int right = a.size() - 1;
            while (left < right) {
                int old_l = left;
                int old_r = right;
              
                int sum = a[i] + a[j] + a[left] + a[right];
                if (sum == k) {
                 
                    ans.push_back({a[i], a[j], a[left], a[right]});

                  
                    while (left < right && a[left] == a[old_l]) left++;
                    while (left < right && a[right] == a[old_r]) right--;
                } else if (sum > k) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    return ans;
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
                        int n,k;
                        cin>>n>>k;
                        int pp;
                        vector<int> vv;
                        //int *arr=new int[n];
                        for(int i=0;i<n;i++)
                        {
                            cin>>pp;
                            vv.push_back(pp);
                        }

                    vector<vector<int>> ans=fourSum(vv,k);

                    for(auto &x:ans)
                    {
                        for(auto &v:x)
                        {
                            cout<<v<<" ";
                        }
                        cout<<"$";
                    }
                    if(ans.empty())
                    {
                        cout<<"-1";
                    }
                    cout<<"\n";
				    }
				    return 0;
		}