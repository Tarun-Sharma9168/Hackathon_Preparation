/*
    //Number of Inversions in merge sort can be a good idea for this;
    //Total Number Of Inversions=Inversion(Left Subarray)+Inversion(right Subarray)+Inversion(While Merging)
    //Time Complexity is(Onlogn)
    //But still not working
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int merge(long long int arr1[],long long int result[],long long int left,long long int right,long long mid)
{
      long long inversion_count=0;
      int i=left;
      int j=mid;
      int k=left;
      while(i<mid && j<=right)
      {
            if(arr1[i] <= arr1[j])
            {
                result[k]=arr1[i];
                i++;
            } 
            else
            {
                inversion_count+=(mid-i);
                result[k]=arr1[j];
                j++;
            }
            k++;
      }
      while(i<mid)
      { 
            result[k]=arr1[i];
            i++;
            k++;   
      }
      while(j<=right)
      {
            result[k]=arr1[j];
            j++;
            k++;  
      }
      for(int i=0;i<=right;i++)
      {
          arr1[i]=result[i];
      }
      return inversion_count;
}
long long  merge_sort(long long arr[],long long arr1[],long long left,long long right)
{
    long long ans=0;
    long long int mid;
    if(left < right)
    {
    mid=(left+right)/2;
    ans+=merge_sort(arr,arr1,left,mid);
    ans+=merge_sort(arr,arr1,mid+1,right);
    ans+=merge(arr,arr1,left,right,mid+1);
    }
    return ans;
}
long long int inversionCount(long long A[],long long n)
{  
    long long int *arr=new long long int[n];
    long long ans=merge_sort(A,arr,0,n-1);
    return ans;
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
    long long int n;
    cin>>n;

    long long int *arr=new long long int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long inversion=inversionCount(arr,n);
    cout<<inversion<<"\n";
    }
    return 0;
}