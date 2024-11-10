#include<bits/stdc++.h>
using namespace std;

int main()
{
   int path_length,msg_length;
   cout<<"Enter the path length and msg_length : "<<endl;
   cin>>path_length>>msg_length;
   int top_path[path_length],bottom_path[path_length],message_bit[msg_length];
   for(int i=1;i<=path_length;i++)cin>>top_path[i];
   for(int i=1;i<=path_length;i++)cin>>bottom_path[i];
   for(int i=1;i<=msg_length;i++)cin>>message_bit[i]; 
   //for(int i=1;i<=path_length;i++)cout<<top_path[i]<<endl;  
   int total_iteration = (msg_length+path_length)-1;
   int x1[total_iteration],x2[total_iteration],convolution[2*total_iteration];
   int ln = 1;

   while(ln <= total_iteration)
   {   
      //for first g1 and msg k point korar jonno
      int ml = ln,pl=1;
      //for second g2 and msg k point korar jonno
      int sml = ln,spl =1;
      int ans=0,result=0;
      while(pl <= path_length and ml>=1)
      {
         if(ml <= msg_length){
            //cout<<top_path[pl]<<" "<<message_bit[ml]<<" ";
            ans^=((top_path[pl]*message_bit[ml]));
            result^=((bottom_path[spl]*message_bit[sml]));}

            pl++;ml--;
            spl++;sml--;

      }
      x1[ln]=ans;
      x2[ln]=result;
      ln++;
   }

/*   for(int i=1;i<=total_iteration;i++)cout<<x1[i]<<" ";cout<<endl;
   for(int i=1;i<=total_iteration;i++)cout<<x2[i]<<" ";cout<<endl;*/ 
   for(int i=1,loc = 1;i<=total_iteration;i++,loc+=2)
   {
      convolution[loc] = x1[i];
      convolution[loc+1] = x2[i];
      
   }
   for(int i=1;i<=2*total_iteration;i++)cout<<convolution[i]<<" ";cout<<endl;


   return 0;
}
