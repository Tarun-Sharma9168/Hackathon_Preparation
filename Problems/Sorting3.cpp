		/*
		     Problem Name:Triplet of sum x we have to search 
              two pointer approach with sorting
		*/
#include<bits/stdc++.h>
using namespace std;
bool find3Numbers(int arr[], int n,int x)
{ 
    //Your code here
    sort(arr,arr+n);  
    for(int i=0;i<n-2;i++)
    {
        int j=i+1;
        int k=n-1;

        while(j<k)
        {
            if(arr[i]+arr[j]+arr[k]==x)
            {
                return true;
            }
            else if(arr[i]+arr[j]+arr[k] < x)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return false;
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
                 cin>>n;
                 int x;
                 cin>>x;
                 int *arr=new int[n];

                 for(int i=0;i<n;i++)
                 {
                     cin>>arr[i];
                 }
               if(find3Numbers(arr,n,x))
               {
                   cout<<"1"<<"\n";
               }
               else{
                   cout<<"0"<<"\n";
               }
		    }
		    return 0;
}