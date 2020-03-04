#include<iostream>
using namespace std;
int count=0,index;
struct node                  //creating the structure of the node
{
int data;
node *next;             // next is the address of the node
};
class LinkedList
{
node *head,*tail;      // * is the address of the head and tail
public:                //constructor should be public and class name
LinkedList()           //public methods can be accessed outside the class that is the reason we are using piblic
{
head=NULL;
tail=NULL;
}
 
  void createNewNode(int value)
  {
  node *temp=new node; //creating a dummy node which is temp
  temp->data=value;    //data part of the temp is new value
  temp->next=NULL;    //next part of the temp is NULL
  if(head==NULL)
  {
  head=temp;       //temp value is dumpded in to head
tail=temp;        // temp value is dumped in to tail coz tail cannot be null
temp=NULL;
count++;
}
//cout<<head->data<<" "<<head->next<<"\n";  //just to know if the node is created or not // printing the address part
else
{
tail->next=temp;   //after creating 1st node, to create another node the temp should be dumped in tail node
tail=temp;
count++;
}
//cout<<"tail node :"<<tail->data<<" "<<tail->next<<endl;
//cout<<"head node :"<<head->data<<" "<<head->next<<"\t";
  }
   void addNodeAtFirst(int value)
  {
  node *temp=new node;
  temp->data=value;
  temp->next=NULL;
  temp->next=head;
  head=temp;
  count++;
  }
  void addNodeAtLast(int value)
  {
  node *temp=new node;
  temp->data=value;
  temp->next=NULL;
  tail->next=temp;
  tail=temp;
  count++;
  }
  void addNodeAtMiddle(int index,int value)
  {
  if(index<=count+1)
  {
  int i;
  node *current=new node;               //current node
  node *previous=new node;             //previous node
  current=head;
  for(i=1;i<index;i++)
  {
  previous=current;
  current=current->next;
}
  node *temp=new node;
  temp->data=value;
  temp->next=current;
  previous->next=temp;
  count++;
    }
    else
    {
    cout<<"invalid index"<<"\n";
}
 }
  void deleteFirst()
  {
  node *temp=new node;
  temp=head;
  head=head->next;
  delete temp;
  count--;
  }
  void deleteLast()
  {
  int i;
node *current=new node;
node *previous=new node;
current=head;
//cout<<"count : "<<count<<"\n";
for(i=1;i<count;i++)
{
previous=current;
current=current->next;
}
previous->next=NULL;
previous=tail;
delete current;
count--;
  }
 void deleteIndex(int index)
 {
  int i;
  node *x=new node;               //previous node
  node *y=new node;             //current node
  node *z=new node;              //post node
  y=head;
  for(i=1;i<index;i++)
  {
  x=y;
  y=y->next;
}
  z=y->next;
  x->next=z;
  delete y;
  count--;
 
 }
 void searchNode(int search)
 {
  int i,flag=0;
  node *current=new node;
current=head;
for(i=1;i<=count;i++)
{
if(search==current->data)
{
flag=1;
}
current=current->next;
}
if(flag==1)
{
cout<<"yes\n";
}
else
{
cout<<"no\n";
}
 
 }
 void frequencyNode(int search)
 {
  int i,flag=0;
  node *current=new node;
current=head;
for(i=1;i<=count;i++)
{
if(search==current->data)
{
flag++;
}
current=current->next;
}
    cout<<"frequency of the node is :"<<flag<<endl;
 }
 void updateNode(int search,int value)
 {
  int i;
  node *current=new node;
  current=head;
  for(i=1;i<=count;i++)
  {
  if(search==current->data)
  {
  current->data=value;
}
current=current->next;
}
 }
  void display()
  {
  node *temp=new node;
  temp=head;
  while(temp!=NULL)
  {
  cout<<temp->data<<" "<<temp->next<<endl;
  temp=temp->next;
}
//cout<<"number of nodes :"<<count;
  }
   
};
int main()
{
LinkedList l;          // l is allias of linked list
l.createNewNode(90);  
l.createNewNode(100);
l.createNewNode(110);
l.addNodeAtFirst(50);
l.addNodeAtLast(150);
l.addNodeAtMiddle(4,110);
// l.deleteFirst();
 // l.deleteLast();
    l.deleteIndex(3);
 // l.searchNode(120);
//  l.frequencyNode(50);
    l.updateNode(150,300);
l.display();
return 0;
}

