#include<bits/stdc++.h>
 using namespace std; 
 
 //Node for create structure that means set of data 
 struct Node
 {
   char data;float frequency;
   Node *left,*right;
   //Create constructor for assign value
   //here ch means vertex character  
   Node (char ch,float freq)
   {
      left=right=NULL;
      data = ch;
      frequency = freq;
   }
  
 };

 //Node frequency comapare for create compare function

 struct compare 
 {
   //ascending order for use L and R just two node  
   bool operator()(Node*L,Node*R)
   {return L->frequency > R->frequency;}
 };

 void printCodes(Node* root,string code)
 {
   if(!root)return;
   //when vertex find then print code value
   if(root->data != '$')
      cout<<root->data<<" ->: "<<code<<endl;
   //recursive function use for each root for check
   printCodes(root->left,code+'0');
   printCodes(root->right,code+ '1');
 }
 double value=0;
 void Inequility_generate(Node* root,string code)
 {
   
   if(!root)return;
   //When vertex find then take length code
   //take inequility value using formula summ 2^-Nk <=1
   //here N is length of code 
   if(root->data != '$')
      {
        value += (1.0/pow(2,code.size()));
      }
   //recursive function use for each root for check
   Inequility_generate(root->left,code+'0');
   Inequility_generate(root->right,code+ '1'); 
 }

 void HuffmanCodes(char vertex[],float freq[],int size,double inqvalue)
 {

   struct Node *left,*right,*top;

   priority_queue<Node*,vector<Node*>,compare>MinHeap;
   for(int i=0;i<size;i++)
   {
      //constructor called so no object create 
      MinHeap.push(new Node(vertex[i],freq[i]));
   }
   //Continue still exist more than one node
   while(MinHeap.size() != 1)
   {
      //cout<<MinHeap.top()->frequency<<" "<<MinHeap.top()->frequency<<endl;
      //MinHeap.pop();
      //first two vertex store left and right variable
      //also delete two vertex and assign new vertec name
      left = MinHeap.top();MinHeap.pop();
      right = MinHeap.top();MinHeap.pop();
      //$ this indicate internal node or sum node
      top = new Node('$',left->frequency+right->frequency);
      top->left = left;
      top->right = right;
      //Now assign new internal node and frequency
   
      MinHeap.push(top);

   }
   //Now contain main root exist MinHeap queue
   //Print this Heap left side assign 0 and right side assign 0 then get code path
   //First call function heap value and null string
   Inequility_generate(MinHeap.top(),"");
   if(value <= inqvalue)
   {  
      cout<<"Yes, Satisfied kraft_inequility condtion so exist huffman code \n"<<endl;
      cout<<"Huffman code are : "<<endl;
      printCodes(MinHeap.top(),"");
   }
   else cout<<"Doesn't exist Huffman code "<<endl;

}

 int main()
{
   
   //Enter number of node
   int n;double kraft_inequility;
   cin>>n >>kraft_inequility ;
   char arr[n+1];float freq[n+1]; 
   for(int i=0;i<n;i++)cin>>arr[i];
   for(int i=0;i<n;i++)cin>>freq[i];
   HuffmanCodes(arr, freq, n,kraft_inequility);

   return 0;
}