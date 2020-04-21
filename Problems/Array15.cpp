/*
Maximum sum in a path using two arrays where path can be switched whenever there is a commom element as two sorted
array is given we are thinking of using merge funtion that is used in merge sort where two sorted array merged
Here we use the intuition that is if we there is a commom element it should process simultaneously...
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
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
        int n,m;
        cin>>n>>m;

        int *arr1=new int[n];
        int *arr2=new int[m];

        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }

        for(int i=0;i<m;i++)
        {
            cin>>arr2[i];
        }
        
        int sum1=0;
        int sum2=0;

        int result=0;
       
        int i=0;
        int j=0;

        while(i<n && j<m)
        {
              if(arr1[i] < arr2[j])
              {
                  sum1+=arr1[i++];
              } 

              else if(arr1[i] > arr2[j])
              {
                  sum2+=arr2[j++];
              }
              //the case where the commom point arises  
              else 
              {
                  //first take the max of sum1 and sum2
                  result+=max(sum1,sum2);

                  //then again make the sum1 and sum2 0
                  //because there can be a another common point 
                  //a head

                  sum1=0;
                  sum2=0;

                  while(i<n && j<m && arr1[i] == arr2[j])
                  {
                       result+=arr1[i++];
                       j++; 
                  }
              }
        }
              while(i<n)
              {
                  sum1+=arr1[i++];
              }
              while(j<m)
              {
                  sum2+=arr2[j++];
              } 
              result+=max(sum1,sum2);
              cout<<result<<"\n";       
    }
    return 0;
}