#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
unordered_map<int,int> mm;
void printCubeFree()
{
bool cubefree[1000001];
for(int i=0;i<1000001;i++)
{
 cubefree[i]=true;
}
 for(int i=2;i*i*i<1000001;i++)
 {
     if(cubefree[i])
     {
         for(int multiple=1;i*i*i*multiple<1000001;multiple++)
         {
             cubefree[i*i*i*multiple]=false;
         }
     }
 }
int k=1;
mm[1]=k;
k++;
for(int i=2;i<1000001;i++)
{
     if(cubefree[i])
     {
         mm[i]=k;
         k++;
     }
     else{

         continue;
     }
} 
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt","r",stdin);
    printCubeFree();
    int t;
    cin>>t;
    int pp=0;
    while(t--)
    {
        int n;
        cin>>n;
        //printCubeFree();
        if(mm[n])
        {
           cout<<"Case "<<pp+1<<": "<<mm[n];
           cout<<"\n";
        }
        else
        {
           cout<<"Case "<<pp+1<<": ";
           cout<<"Not Cube Free"<<"\n";
        }
       pp++; 
    }
    return 0;
}