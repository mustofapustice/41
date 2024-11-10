#include<bits/stdc++.h>
using namespace std;
// Binary encode for  'A'=0 and 'B'=1 assign
string Encode (int n,char c)
{
   string s=bitset<3>(n).to_string();
                                                  
   if(c=='A')s+='0';
   else s+='1';
   return s;
}

int main()
{
   
   string input,str;
   cin>>input;
   int len = input.size();
   multimap <string,int>mp;
   vector<string>sequence;
   int pos = 1;
   for(int i=0;i<len;i++)
   {     
      str+=input[i];
      if(mp.find(str) == mp.end())
      {
         mp.insert({str,pos});
         sequence.push_back(str);
         str="";
         pos++;
      }
      //for last substring 
      if(mp.find(str) != mp.end() and i==len-1)
      {
          mp.insert({str,pos});
          sequence.push_back(str);
      }       
   }
   int ln = sequence.size();
   cout<<"Position is : ";
   for(int i=1;i<=ln;i++)cout<<i<<" ";cout<<endl;
   cout<<"Sequence is : ";
   for(auto it:sequence)cout<<it<<" ";cout<<endl;
   
   pair<int,char>pr[ln];
   for(int i=0;i<ln;i++)
   {
      string val = sequence[i];
      if(val.size()==1)pr[i]={0,val[0]};
      else 
      { 
      string sbs = val.substr(0,val.size()-1);
      pr[i]={mp.find(sbs)->second,val[val.size()-1]};
      }
   }

   //Numerical representation
   cout<<"Numerical Representation is : ";
   for(auto it:pr)cout<<it.first<<it.second<<" ";cout<<endl;
   
   cout<<"Encode : ";
   for(auto it:pr)
   {
      string ans=Encode(it.first,it.second);
      cout<<ans<<" ";
   }

   return 0;
}
