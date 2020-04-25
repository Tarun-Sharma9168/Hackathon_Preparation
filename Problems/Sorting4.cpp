		/*
		     Problem Name:Segregate 0,1,2
		*/
#include<bits/stdc++.h>
using namespace std;
void merge(int *arr, int low,int high,int mid)
{
        int i=low;
        int j=mid+1;
        int k=0;
        int n=high-low+1;
        int *result=new int[n];
        while(i<=mid && j<=high)
        {
             if(arr[i] <= arr[j])
             {
                       result[k]=arr[i];
                       i++;
                       k++;
             }
             else
             {
                      result[k]=arr[j];
                      j++;
                      k++;
             }
        }
        while(i<=mid)
        {
            result[k]=arr[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            result[k]=arr[j];
            j++;
            k++;
        }
        int nw=0;
        //copying is the very important step
        for(int i=low;i<=high;i++)
        {
            arr[i]=result[nw++];
        }
}
void mergesort(int *arr,int low,int high)
{
        if(low < high)
        {
           int mid=low+(high-low)/2;
           mergesort(arr,low,mid);
           mergesort(arr,mid+1,high);
           merge(arr,low,high,mid);
        }
}
void segragate012(int arr[], int n)
{
    //Your code here
    mergesort(arr,0,n-1);
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