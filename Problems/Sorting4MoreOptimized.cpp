		/*
		     Problem Name:Closet problem same but this is even more stabalised that is only constant order extra space 
             That is taking three indices low,mid,and high and we have to segregate the 0,1,and 2.

		*/
#include<bits/stdc++.h>
using namespace std;
void segragate012(int arr[], int n)
{
    //Your code here
    int l=0;
    int m=0;
    int h=n-1;
    int i=0;
    while(m<=h)
    {
        switch(arr[m])
        {
            case 0:
                    swap(arr[l],arr[m]);
                    l++;
                    m++;
                    break;
            
            case 1: m++;
            break;
            
            case 2:swap(arr[m],arr[h]); 
                    h--;
                    break;        
        }
}
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

                
                int *arr=new int[n];
                for(int i=0;i<n;i++)
                {
                    cin>>arr[i];
                }
                segragate012(arr,n); 

                for(int i=0;i<n;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
		    }
		    return 0;
}