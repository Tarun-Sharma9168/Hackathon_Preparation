		/*
		     Problem Name:Another Birthday Present

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
                long long int n;
                cin>>n;
                long long int k;
                cin>>k;

                long long int *arr=new long long int[n];
                for(int i=0;i<n;i++)
                {
                    cin>>arr[i];
                }

                long long int *copy=new long long int[n]; 
                for(int i=0;i<n;i++)
                {
                   copy[i]=arr[i];
                }

                sort(copy,copy+n);
                
                map<long long int,long long int> mp;
                //storing the real index 
                for(int i=0;i<n;i++)
                {
                    mp[copy[i]]=i;
                }
                //storing the differences
                for(int i=0;i<n;i++)
                {
                    copy[i]=abs(mp[arr[i]]-i);
                }
                for(int i=0;i<n;i++)
                {
                    cout<<copy[i]<<" ";
                }
                cout<<"\n";
                bool flag=true;
                for(int i=0;i<n;i++)
                {
                    if((copy[i] % k) !=0 )
                    {
                        flag=false;
                        break;
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