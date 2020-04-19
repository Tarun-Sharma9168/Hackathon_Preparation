#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef tuple<int,int,int> t3i;
bool base_area_comp(t3i &a,t3i &b)
{
   return get<0>(a) * get<1>(a) > get<0>(b) * get<1>(b);
}
int max_height(int h[],int w[],int l[],int n)
{
    vector<tuple<int,int,int>> v;
    //Generate all rotation of the boxes

     //Generate all rotation of boxes
    for(int i=0;i<n;i++){
        if(l[i] > w[i])
            v.push_back(make_tuple(l[i],w[i],h[i]));
        else
            v.push_back(make_tuple(w[i],l[i],h[i]));
        if(w[i] > h[i])
            v.push_back(make_tuple(w[i],h[i],l[i]));
        else
            v.push_back(make_tuple(h[i],w[i],l[i]));
        if(h[i] > l[i])
            v.push_back(make_tuple(h[i],l[i],w[i]));
        else
            v.push_back(make_tuple(l[i],h[i],w[i]));
    }
            //sort according to the base area

            sort(v.begin(),v.end(),base_area_comp);
            
            vector<int> ht;
                for(int i=0;i<3*n;i++)
        ht.push_back(get<2>(v[i]));
    int H=0;
    for(int i=1;i<3*n;i++){
        for(int j=0;j<i;j++){
            //CAN i go on top of j?? IF  YES execute below
            if(get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j])
                             &&  ht[j] + get<2>(v[i]) > ht[i])
            {
                ht[i] = ht[j] + get<2>(v[i]);
                
                //finding max height
                    H = max(H,ht[i]);
            }
        }
    }
return H;
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
    int n;
    cin>>n;

    int *height=new int[n];
    int *width=new int[n];
    int *length=new int[n];

    for(int i=0;i<n;i++)
    { 
       cin>>height[i];
       cin>>width[i];
       cin>>length[i];
    }
    cout<<max_height(height,width,length,n)<<"\n";
    }
    return 0;
}