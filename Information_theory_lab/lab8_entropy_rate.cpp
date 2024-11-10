#include<bits/stdc++.h>
using namespace std;

int main()
{  
   
   // for graph matrix
   int graph[5][5];
   vector<int>each_node_weight;
   for(int i=1;i<5;i++)
   {  int sum=0;
      for(int j=1;j<5;j++)
      {
         cin>>graph[i][j];
         sum+=graph[i][j];
      }
      each_node_weight.push_back(sum);
   }
   //for total cost finding
   int total_cost = 0;
   set<pair<int,int> >s; 
   for(int i=1;i<5;i++)
   {
      for(int j=1;j<5;j++)
      {
         if(s.find({i,j})==s.end() and s.find({j,i})==s.end())
            {
               total_cost+=graph[i][j];
               s.insert({i,j});
               s.insert({j,i});
            }  

      }
   }
   cout<<"Total cost is : "<<total_cost<<endl;
   cout<<"Each node weight is : ";
   for(auto it:each_node_weight)cout<<it<<" ";cout<<endl;
   //Calculate stationary distribution mue using formula mue = Wi/2W
   // W is the total cost and Wi is the each node cost 
   vector<double>mue;
   for(auto it:each_node_weight)
   {
      double ans = it/(2.0*total_cost);
      mue.push_back(ans);
   }
   cout<<"The stationary distribution mue is : \n";
   for(auto it:mue)cout<<it<<" ";cout<<endl;
   //The entropy rate for formula rate = H(Wij/2*W)-H(Wi/2W);
   //Here H(x) is entropy.Formula = - summation(Pij log Pij);
   // Wi/2W = mue[i] so replaced just;
   double Entropy_all_position=0,Entropy_each_node =0; 
   for(int i=1;i<5;i++)
   {
      for(int j=1;j<5;j++)
      {    //calculation H(Wij/2*W)
          double ele = graph[i][j]/((2.0*total_cost));
          if(ele >0)
          {
          double result = (ele*log2(ele));
          Entropy_all_position+=result;
          
          }
      }
       //Calculation H(Wi/2W)
      double H_mue =(mue[i-1]*log2(mue[i-1]));
      Entropy_each_node+=H_mue;     

   }
   cout<<"Two Entropy is : "<<endl; 
   cout<<(-1)*Entropy_all_position<<" "<<(-1)*Entropy_each_node<<endl;
   double Entropy_rate =(-1)*Entropy_all_position-(-1)*Entropy_each_node;
   cout<<"The Entropy rate is : "<<Entropy_rate<<endl; 

   return 0;
}
