#include<bits/stdc++.h>
 using namespace std; 
 int main ()
  {
    int row,col;
    cout<<"Enter rows and columns:"; cin>>row>>col;

   ///Take the values of matrix
   cout<<"Enter the values of joint distribution:"<<endl;
   double arr[row][col];

   for (int i=0; i<row;i++)
   {
      for (int j=0; j<col; j++)
      {
         cin>>arr[i][j];
      }
   }
   double x[row],y[col];
   cout<<"Enter the marginal distribution of X:";
   for (int i=0;i<row;i++) cin>>x[i];
   cout<<"Enter the marginal distribution of Y:";
   for (int i=0; i<col;i++) cin>>y[i];

   ///Calculation H(X) 
   double H_of_X=0; 
    for (int i=0; i<row;i++)
   {
       H_of_X+=(-x[i]*log2(x[i]));
   }
   cout<<"H(X) = "<<H_of_X<<" bits"<<endl;
   ///CalculationH(Y) 
   double H_of_Y=0; 
   for (int i=0; i<col;i++)
   {
      H_of_Y+=(-y[i]*log2(y[i]));
   }
   cout<<"H(Y) = "<<H_of_Y<<" bits"<<endl;

   ///Calculation of H(X|Y)

   double H_of_X_given_Y=0, H_of_Y_given_X=0;
   double Hx[row];
   for (int i=0; i<row;i++)
   {
      double val2=0;
      for (int j=0; j<col; j++)
      {
         double val1=(arr[i][j] *(1/y[i]));
         if(val1==0)
         val2+=0;
         else
         val2+=(-val1*log2(val1));
      }
      Hx[i]=val2;

   }

   for (int i=0; i<row;i++)
   {
      H_of_X_given_Y+=(y[i]*(Hx[i]));
   }
   cout<<"H(X|Y) = "<<H_of_X_given_Y<<" bits"<<endl;

   ///Calculation of H(Y|X)

   double Hy[row];
   for (int i=0; i<row;i++){
      double val2=0;
      for (int j=0; j<col; j++)
      {
         double val1=(arr[j][i] *(1/x[i]));
         if(val1==0)
         val2+=0;
         else
         val2+=(-val1*log2(val1));
      }
      Hy[i]=val2;
   }
   for (int i=0; i<row;i++)
   {
      H_of_Y_given_X+=(x[i]*(Hy[i]));
   }
   cout<<"H(Y|X) = "<<H_of_Y_given_X<<" bits"<<endl;
   return 0;
   }

