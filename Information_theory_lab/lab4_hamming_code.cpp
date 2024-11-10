#include<bits/stdc++.h>
using namespace std;
// Function for decimal to binary convert 
string decimalToBinary(int n)
{
    string s = bitset<8> (n).to_string();
    // Least significant bit for reverse use
    reverse(s.begin(),s.end());
    return s;     
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
   
   string s,hamming="";
   cin>>s;
   int len = s.size();
   // find no of parity bit using formula 2^r>= m+r+1
   int bit ;
   for(int i=1;i<=len;i++)
   {
      if(pow(2,i) >= (len+i+1))
      {
         bit = i;break;
      }
   }

   // power of 2 position assign parity bit
   int k=0;
   for(int i=1;i<=len+bit;i++)
   {
      if(isPowerOfTwo(i))
      {
         hamming+="p";
      }
      else {hamming+=s[k];k++;}
   }
   cout<<"Position generate parity bit : ";
   cout<<hamming<<endl;
   int parity =0;
   for(int i=0;i<hamming.size();i++)
   {
    
     if(hamming[i]=='p')
     {
        int one = 0;
        for(int j=i+1;j<hamming.size();j++)
        {
         string st = decimalToBinary(j+1);
         if(st[parity] == '1')
         {
            if(hamming[j]=='1')one++;
         }
        }

      // here use even parity no of ones even is 1 otherwise 0
      if(one %2 == 0 and one)hamming[i] = '0';
      else hamming[i]='1';
      parity++;
     }

     
   }
   cout<<"Generate hamming code is : ";
   cout<<hamming<<endl;
   /*Sender message with parity bit system
   for example send message with even parity*/
   //Error detection for 
   string receivermsg,position="",str="";
   cin>>receivermsg;
   if(receivermsg != hamming){
      int pk = 0;
   for(int i=0;i<receivermsg.size();i++)
   {
    
    if(isPowerOfTwo(i+1))
    { 
      int one =0;
      for(int j=i;j<receivermsg.size();j++)
      {
         string st = decimalToBinary(j+1);
         if(st[pk] == '1')
         {
            if(receivermsg[j]=='1')one++;
         }
      }
      if(one % 2 == 0 and one)str+='0';
      else str+='1';
      pk++;
    }
     
     
   }
   reverse(str.begin(),str.end());
   cout<<str<<endl;
   cout<<"Error find at location : "<<stoi(str, 0, 2)<<endl;
  }
  else 
  {
   cout<<"No error found"<<endl;
  }

   return 0;
}