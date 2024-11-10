#include<bits/stdc++.h>
using namespace std;

int main()
{  

   //Enter 2 dimension binary symmetrci matrix which is also called noiseless matrix
   //Matrix element p represent probability
   
   double matrix[3][3];
   for(int i=1;i<3;i++)
   {
      for(int j=1;j<3;j++)
      {
         cin>>matrix[i][j];
      }
   }
   cout<<"Symmetric matrix is : \n"<<endl;
    for(int i=1;i<3;i++)
   {
      for(int j=1;j<3;j++)
      {
         cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
   }
   
   //Calculate H(Y/X) using formula (1-p)log(1/(1-p))+plog(1/p)
   double Hp = matrix[1][1]*log2(1.0/matrix[1][1]) + matrix[2][1]*log2(1.0/matrix[2][1]);
   cout<<"Conditional probability H(Y/X) is = "<<Hp<<" bits/msg symbol"<<endl;
   //Now calculate channel capacity using formula C = 1- H(Y/X)
   double C = 1-Hp;
   cout<<"Channel Capacity is = "<<C<<" bits/msg symbol"<<endl;

   return 0;
}
