/*
removing the duplicated where all the elements are the prime number
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
void removeDuplicate(vector<int> &vect)
{
 vector<int> copy;
 bool arr[101]={false};
 for(int i=0;i<vect.size();i++)
 {
      if(!arr[vect[i]])
      {
          copy.push_back(vect[i]);
          arr[vect[i]]=true;
      } 
 }
vect=copy;
for(auto x:vect)
{
    cout<<x<<" ";
}
copy.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int x;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr.push_back(x);
        }
        removeDuplicate(arr);
    }

    return 0;
}