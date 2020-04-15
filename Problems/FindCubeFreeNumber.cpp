//this program is not optimised as we are checking one by one 
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<int,int> mm;
bool isCubeFree(int n)
{
    if(n==1)
    {
        return true;
    }
    for(int i=2;i*i*i<=n;i++)
    {
        if(n%(i*i*i) == 0)
        {
            return false;
        } 
    }
    return true;
}
void make_list_of_cube_free_number()
{
      int k=1;
      for(int i=1;i<=100000;i++)
      {
          if(isCubeFree(i))
          {
                mm[i]=k;
                k++;
          }
      }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    int pp=0;
    while(t--)
    {
       
       int n;
       cin>>n;
       make_list_of_cube_free_number();
       if(mm[n])
       {
           cout<<"Case "<<pp+1<<": "<<mm[n];
           cout<<"\n";
       }
       else
       {
           cout<<"Case "<<pp+1<<": ";
           cout<<"Not Cube Free"<<"\n";
       }
       pp++;
    }
    return 0;
}