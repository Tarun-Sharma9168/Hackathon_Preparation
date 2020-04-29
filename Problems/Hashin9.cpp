 /*
Author Name:Tarun Sharma
Problem Name:smallest window of string containing all characters that are their in the pattern.
             Hashing problem and we see whether all the characters are there in the string. 
             Searching the window is the first task then try to minimize by removing extra and the unusable character
             from the starting.
*/
		#include<bits/stdc++.h>
		using namespace std;
        #define no_of_chars 256
        string smallestWindow (string s, string pat)
        {
          // Your code here
          int len1=s.length();//text length
          int len2=pat.length();//pattern length

          // if text length is smaller than the pattern length then it is impossible for a pattern to exist in a text
          if(len1 < len2)
          {
              return "-1";
          }
          //declaring the hash tables for the text and the pattern
          int hash_table_pattern[no_of_chars]={};
          int hash_table_str[no_of_chars]={};

          //marking the characters in a hash table for the pattern
          for(int i=0;i<len2;i++)
          {
              hash_table_pattern[pat[i]]++;
          }

          int start=0;
          int start_index=-1;
          int min_len=INT32_MAX;

          //start traversing the array
          int count=0; 
          for(int j=0;j<len1;j++)
          {
              hash_table_str[s[j]]++;

              if(hash_table_pattern[s[j]]!=0 &&   hash_table_pattern[s[j]] >= hash_table_str[s[j]])
              {
                 count++;
              }
              //If all the characters matches
              if(count == len2)
              {
                  //For one particular window this happens... 
                  //now we have to try minimize the window...
                  while(hash_table_str[s[start]] > hash_table_pattern[s[start]] || hash_table_pattern[s[start]] ==0)
                  {
                      if(hash_table_str[s[start]] > hash_table_pattern[s[start]])
                      hash_table_str[s[start]]--;
                      start++;
                  }
            int len_window = j - start + 1; 
            if (min_len > len_window) 
            { 
                min_len = len_window; 
                start_index = start; 
            } 
              }
          }

          if(start_index == -1)
          {
              return "-1";
          }
          return s.substr(start_index,min_len);
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
                          string text;
                          string pattern;
                          cin>>text>>pattern;

                          string ans=smallestWindow(text,pattern);
                          cout<<ans<<"\n";
				    }
				    return 0;
		}