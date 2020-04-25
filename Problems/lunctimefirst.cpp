    	/*
		     Problem Name:Chef In Fantasy League

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
               int n,s;
               cin>>n>>s;

               int *arr=new int[n];
               for(int i=0;i<n;i++)
               {
                   cin>>arr[i];
               }
               int *player=new int[n];

               for(int i=0;i<n;i++)
               {
                   cin>>player[i];
               }
               bool flag=false;
               for(int i=0;i<n-1;i++) 
               {
                   for(int j=i+1;j<n;j++)
                   {
                       if((player[i] == 0 && player[j]==1) || (player[i]==1 && player[j]==0))
                       {
                            if(arr[i]+arr[j] <= 100-s)
                            {
                                flag=true;
                                break;
                            }
                       }
                   }
               }
               if(flag)
               {
                   cout<<"yes"<<"\n";
               }
               else{
                   cout<<"no"<<"\n";
               }
		    }
		    return 0;
}