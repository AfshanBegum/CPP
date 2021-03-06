#include<iostream>
using namespace std;
void nodeOperations();
void createNewNode(int value);
void insertFirst(int value);
void insertLast(int value);
void insertIndex(int value,int index);
void deleteFirst();
void deleteLast();
void deleteIndex(int index);
void deleteFoccur(int search);
void deleteLoccur(int search);
void deleteAlloccur(int search);
void search(int search);
void display();
struct node
{
	int data;
	node *next;
	node *pre;
};
class dlinkedlist
{
	node *head,*tail;
	public:
	dlinkedlist()
	{
		head=NULL;
		tail=NULL;
	}
	void createnode(int value)
	{
		node *temp=new node;
		temp->data=value;
		temp->next=NULL;
		temp->pre=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{
			tail->next=temp;
			temp->pre=tail;
			temp->next=NULL;
			tail=temp;
			
		}
	}
	    void insertfirst(int value)
	    {
	    	node *temp=new node;
	    	temp->data=value;
	    	head->pre=temp;
			temp->next=head;
	    	temp->pre=NULL;				    	
	    	head=temp;
		}
		insertindex(int value,int index)
		{
			int i;
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			temp->pre=NULL;
			node *y=new node;
			node *x=new node;
			y=head;
			for(i=1;i<index;i++)
			{
				x=y;
				y=y->next;
			}
			x->next=temp;
			y->pre=temp;
			temp->pre=x;
			temp->next=y;
		}
		void deletefirst()
		{
			node *temp=new node;
			temp=head;
			head=temp->next;
			head->pre=NULL;
			delete temp;
		}
		void deletelast()
		{
			node *x=new node;
			node *y=new node;
			y=head;
		    while(y!=tail && tail!=NULL)
		    {
		   	  x=y;
		   	  y=y->next;
		    }
		   tail=x;
		   tail->next=NULL;
		   delete y;
		}
		void deleteindex(int index)
		{
			int i;
			node *x=new node;
			node *y=new node;
			node *z=new node;
			y=head;
			for(i=1;i<index;i++)
			{
				x=y;
				y=y->next;
			}
			z=y->next;
			x->next=z;
			z->pre=x;
			delete y;
		}
		search(int search)
		{
			int flag=0;
			node *x=new node;
			x=head;
			while(x!=NULL)
			{
				if(search==x->data)
				{
					flag++;
				}
				x=x->next;
			}
			if(flag>=1)
			{
				cout<<"yes";
			}
			else
			{
				cout<<"no";
			}
		}
		void deleteFoccur(int search)
		{
			if(search==head->data)
			{
				deletefirst();
			}
			else
			{
				node *x=new node;
				node *y=new node;
				node *z=new node;
				y=head;
				while(y->next!=NULL)
				{
					x=y;
					y=y->next;
					if(search==y->data)
					{
					   z=y->next;
					   x->next=z;
					   z->pre=x;
					   delete y;
					   break;	
					}
				}
			}
			if(search==tail->data)
			{
				deletelast();
			}
		}
		void deleteLoccur(int search)
		{
			if(search==head->data)
			{
				deletefirst();
			}
			else
			{
				node *x=new node;
				node *y=new node;
				node *z=new node;
				y=tail;
				while(y->pre!=head)
				{
					x=y;
					y=y->pre;
					if(search==y->data)
					{
						x=y->pre;
						z=y->next;
						x->next=z;
						z->pre=x;
						delete y;
						break;
					}
				}
			}
			if(search==tail->data)
			{
				deletelast();
			}
		}
		void deleteAlloccur(int search)
		{
			if(search==head->data)
			{
				deletefirst();
			}
			else
			{
				node *x=new node;
				node *y=new node;
				node *z=new node;
				y=tail;
				while(y->pre!=head)
				{
					x=y;
					y=y->pre;
					if(search==y->data)
					{
						x=y->pre;
						z=y->next;
						x->next=z;
						z->pre=x;
						delete y;
					}
				}
			}
			if(search==tail->data)
			{
				deletelast();
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
			  cout<<temp->data<<"\t";
			  temp=temp->next;	
			}
		}
		void nodeoperations()
		{
			int opt,value,index;
			cout<<"==================Node Operations================"<<endl;
			cout<<"1. Create New Node"<<endl;
			cout<<"2. Insert Last"<<endl;
			cout<<"3. Insert First"<<endl;
			cout<<"4. Insert Index"<<endl;
			cout<<"5. Delete first"<<endl;
			cout<<"6. Delete Last"<<endl;
			cout<<"7. Delete Index"<<endl;
			cout<<"8. Search"<<endl;
			cout<<"9. Delete first occurance"<<endl;
			cout<<"10. Delete last occurance"<<endl;
			cout<<"11. Delete All occurance"<<endl;
			cout<<"0. EXIT"<<endl;
			do
			{
			cout<<"\nEnter any number between 1-7 :   ";
	        cin>>opt;
	        if(opt==1)
	        {
	        	cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
	        	createnode(value);
	        	display();
			}
			else if(opt==2)
			{
				cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
	        	createnode(value);
	        	display();
			}
			else if(opt==3)
			{
				cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
				insertfirst(value);
				display();
			}
			else if(opt==4)
			{
				cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
	        	cout<<"enter index";
	        	cin>>index;
	        	insertindex(value,index);
	        	display();
			}
			else if(opt==5)
			{
				deletefirst();
				display();
			}
			else if(opt==6)
			{
				deletelast();
				display();
			}
			else if(opt==7)
			{	
				cout<<"Enter index to delete node";
				cin>>index;
				deleteindex(index);
				display();
			}
			else if(opt==8)
			{
				int value;
				cout<<"Enter search element";
				cin>>value;
				search(value);
			}
			else if(opt==9)
			{
				int search;
				cout<<"enter search element";
				cin>>search;
				deleteFoccur(search);
				display();
			}
			else if(opt==10)
			{
				int search;
				cout<<"enter search element";
				cin>>search;
				deleteLoccur(search);
				display();
			}
			else if(opt==11)
			{
				int search;
				cout<<"enter search element";
				cin>>search;
				deleteAlloccur(search);
				display();
			}
			}
			while(opt!=0);
		}
};
int main()
{
	dlinkedlist l;
    l.nodeoperations();
}
