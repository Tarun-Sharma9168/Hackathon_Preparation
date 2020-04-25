		/*
		     Problem Name:Merge K sorted arrays of same size.And this problem can be solved by recursion and solved by the 
             bottom to up approach that is just like Merge of the two arrays that is sorted .We use array as an array element and 
             do merge sort on it.

		*/
#include<bits/stdc++.h>
using namespace std;
void mergeArrays(int *arr1,int *arr2,int n1,int n2,int *arr3)
{
      int i = 0, j = 0, k = 0;  
    
    // Traverse both array  
    while (i<n1 && j <n2)  
    {  
        // Check if current element of first  
        // array is smaller than current element  
        // of second array. If yes, store first  
        // array element and increment first array  
        // index. Otherwise do same with second array  
        if (arr1[i] < arr2[j])  
            arr3[k++] = arr1[i++];  
        else
            arr3[k++] = arr2[j++];  
    }  
    
    // Store remaining elements of first array  
    while (i < n1)  
        arr3[k++] = arr1[i++];  
    
    // Store remaining elements of second array  
    while (j < n2)  
        arr3[k++] = arr2[j++]; 
}
void mergeKArraysNew(int **arr,int i,int j,int *output,int k)
{
    //if one array is in range
    if(i == j)
    {
       for(int p=0;p<k;p++)
       {
          output[p]=arr[i][p];
       }
       return;
    }
    //if only two arrays are left them merge them  
    if(j-i==1) 
    { 
        mergeArrays(arr[i],arr[j],k,k,output);//merge arrays is the functions which merges two arrays of size n1 and n2 
        return; 
    } 

    //output arrays  
    int mid=(i+j)/2;
    int out1[k*(mid-i+1)],out2[k*(j-mid)]; 
    //divide the array into halves 
    //pass the index of arrays
    mergeKArraysNew(arr,i,mid,out1,k); //just like merge sort divide and conquer approach
    mergeKArraysNew(arr,mid+1,j,out2,k);
    mergeArrays(out1,out2,k*(mid-i+1),k*(j-(mid)),output);
}
int *mergeKArrays(int **arr, int k)
{
//code here
int *output=new int[k*k];
for(int i=0;i<k*k;i++)
{
     output[i]=0;
}
mergeKArraysNew(arr,0,k-1,output,k);
return output;
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