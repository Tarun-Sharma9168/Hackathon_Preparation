 /*
Author Name:Tarun Sharma
Problem Name:Quadratic Probing in Hashing Implementation
*/
		#include<bits/stdc++.h>
		using namespace std;
        bool is_vacant(int *arr,int h)
        {
            for(int i=0;i<h;i++)
            {
                if(arr[i] == -1)
                {
                    return true;
                }
            }
            return false;
        }
        void QuadraticProbing(int hash[],int h,int arr[],int n)
        {
                 //Your code here
                 //Your code here
                    int p;
                    for(int i=0;i<n;i++)
                    {
                            p=0;
                            //cout<<"ram"<<"\n";
                            while(hash[((arr[i] % h) + p*p) % h] != -1 && is_vacant(hash,h))
                            {
                                p++;
                            }
                            if(is_vacant(hash,h))
                            hash[((arr[i] % h) + p*p) % h]=arr[i];
                            else
                            {
                                continue;
                            }
                    }
        for(int i=0;i<h;i++)
        {
            cout<<hash[i]<<" ";
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
                        int n_hash_size;
                        int n_array_size;
                        cin>>n_hash_size>>n_array_size;
                        
                        int *arr=new int[n_array_size];

                        for(int i=0;i<n_array_size;i++)
                        {
                            cin>>arr[i];
                        }  
                        int *hash_table=new int[n_hash_size];

                        memset(hash_table,-1,n_hash_size*sizeof(int));

                      /*  for(int i=0;i<n_hash_size;i++)
                        {
                            cout<<hash_table[i]<<" ";
                        }
                        */
                       QuadraticProbing(hash_table,n_hash_size,arr,n_array_size);
                       cout<<"\n";
				    }
				    return 0;
		}