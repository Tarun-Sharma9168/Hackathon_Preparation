/*
       Finding the Inversion count using Binary Indexed Tree 
       It is very efficient  just store the number of smaller elements at each index 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Initialize result 
  
    // Traverse ancestors of BITree[index] 
    while (index > 0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree.  The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
       // Add 'val' to current node of BI Tree 
       BITree[index] += val; 
  
       // Update index to that of parent in update View 
       index += index & (-index); 
    } 
} 
  
// Returns inversion count arr[0..n-1] 
int getInvCount(long long int arr[], int n) 
{ 
    int invcount = 0; // Initialize result 
  
    // Find maximum element in arr[] 
    int maxElement = 0; 
    for (int i=0; i<n; i++) 
        if (maxElement < arr[i]) 
            maxElement = arr[i]; 
  
    // Create a BIT with size equal to maxElement+1 (Extra 
    // one is used so that elements can be directly be 
    // used as index) 
    int BIT[maxElement+1]; 
    for (int i=1; i<=maxElement; i++) 
        BIT[i] = 0; 
  
    // Traverse all elements from right. 
    for (int i=n-1; i>=0; i--) 
    { 
        // Get count of elements smaller than arr[i] 
        invcount += getSum(BIT, arr[i]-1); 
  
        // Add current element to BIT 
        updateBIT(BIT, maxElement, arr[i], 1); 
    } 

    //for(int i=0;i<maxElement;i++)
    //{
    //    cout<<BIT[i]<<" ";
    //}
    return invcount; 
} 
long long int inversionCount(long long arr[],long long n)
{  
    getInvCount(arr,n);
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