 /*
Author Name:Tarun Sharma
Problem Name:Multiply two strings
*/
		#include<bits/stdc++.h>
		using namespace std;
        bool notisdigit(char pp)
        {
            if(pp=='-')
            {
                return true;
            }
            return false;
        }
        string multiplyStrings(string s1, string s2)
         {
                
                if(s1=="0" || s2 =="0")
                return "0";
                 int carry=0;
                 int sum=0;
                 int length;
                 length=s1.length() + s2.length();
                 char result[length];
                 for(int i=0;i<length;i++)
                 {
                     result[i]='0';
                 }
                 int rem=0;
                 int p=0;
                 int car=0;
                 int jam=0;
                 for(int i=s1.length()-1;i>=0;i--)
                 {
                     if(notisdigit(s1[i]))
                     break;
                     int k=length-p-1;
                     for (int j=s2.length()-1;j>=0;j--)
                     {
                         if(notisdigit(s2[j]))
                         break;
                         sum=((s1[i]-'0')*(s2[j]-'0'))+carry;
                         carry=(sum/10);
                         rem=sum%10;
                         
                         int ans=(result[k]-'0')+rem+car;
                         
                         jam=ans%10;
                         car=ans/10;
                         
                         result[k]=jam+'0';
                         k--;
                     }
                    // cout<<carry<<" "<<car<<"\n";
                     if(carry)
                     result[k]=(result[k]-'0')+carry+'0';
                     
                     if(car)
                     result[k]=(result[k]-'0')+car+'0';
                     
                     car=0;
                     carry=0;
                     p++;
                 }
               /*  for(int i=0;i<length;i++)
                 {
                     cout<<result[i]<<" ";
                 }
                 */
                 //cout<<"\n";
                 string res="";
                 if(s1[0] == '-' && s2[0] == '-')
                 {
                  res = res +"";
                 }
                 else if(s1[0]=='-' || s2[0]=='-')
                 {
                     res = res +'-';
                 } 
                 bool non_zero=false;
                 for(int i=0;i<length;i++)
                 {
                     if((result[i]-'0') || non_zero)
                     {
                          non_zero=true;
                          res=res+result[i];
                     }
                 } 
                 return res;
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
                        string s1;
                        string s2;

                        cin>>s1>>s2;
                        cout<<multiplyStrings(s1,s2)<<"\n";

				    }
				    return 0;
		}