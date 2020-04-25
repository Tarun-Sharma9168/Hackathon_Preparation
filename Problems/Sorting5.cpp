
		/*
		     Problem Name:Merging of the k sorted arrays where k is the number of sorted arrays that we have to merge as well as 
             Size of each array is also k.
             Naive Sol :O(n^2)
             Very Very naive approach is just put all elements in one single array and at the end sort and print the array

		*/
#include<bits/stdc++.h>
using namespace std;
#define N 105
int *mergeKArrays(int **arr, int k)
{
//code here
int *result=new int[k*k];
int pp=0;
for(int i=0;i<k;i++)
{
    for(int j=0;j<k;j++)
    {
        result[pp]=arr[i][j];
        pp++;
    }
}
sort(result,result+pp);
return result;
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

                int **arr=new int*[n];

                for(int i=0;i<n;i++)
                {
                    arr[i]=new int[n];
                }

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        cin>>arr[i][j];
                    }
                }
                int *output=mergeKArrays(arr,n);

                for(int i=0;i<n*n;i++)
                {
                    cout<<output[i]<<" ";
                }
               cout<<"\n";
		    }
		    return 0;
}