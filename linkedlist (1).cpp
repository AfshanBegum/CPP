//wap to linkedlist operations..in c++ with functions
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node()
		{
			cout<<endl<<"  "<< "obj created";
		}
		~Node()
		{
			cout<<endl<<" "<<"node is removed";
		}
};

Node *start; 
Node  *temp;
Node  *x;
int count=0,num,i;


void addNodelast();
void addNodefirst();
void addNodemiddle();
void deleteNodelast();
void deleteNodefirst();
void deleteNodemiddle();
void searchNode();
void sortasc();
void display();

int main()
{
	int ch,exflag=0;
	while(1){
		cout << endl << "--------------------"	;
		cout << endl << "No. of nodes  : " << count;
		cout << endl << "--------------------"	;
		cout << endl << "1. Add node at last";
		cout << endl << "2. Add node in the begining";
		cout << endl << "3. Add node in middle";
		cout << endl << "4. Delete last node";
		cout << endl << "5. Delete starting node";
		cout << endl << "6. Delete middle node";
		cout << endl << "7. Display";
		cout << endl << "8. Sort Asc";
		cout << endl << "9. Sort Desc";
		cout << endl << "10. Search node";
		cout << endl << "11. Swap nodes";
		cout << endl << "20. Exit";
		cout << endl << endl << "Enter choice : ";
		cin >> ch;
		switch(ch){
			case 1 :
				   addNodelast();
					break;
			case 2:
			 	   addNodefirst();
			    	break;
			case 3:
				 addNodemiddle();
				 break;
			case 4:
				  deleteNodelast();
					break;
		    case 5:
		    	deleteNodefirst();
		    	break;
		    case 6:
		    	deleteNodemiddle();
		    	break;
			case 7 :
					display();
					break;
			case 8 :
				 
				 sortasc();
				 break;
			case 10 :
				  searchNode();
				  break;
		//	case 11: 
		//			swap();
		//			break;		
			case 20:
					exflag=1;
					break;
		}
		if(exflag==1){
			break;
		}		
	} 
	for(x=start;x!=NULL;){
		temp=x;
		x=x->next;
		delete temp;		
	}	
}
void addNodelast()
{
    	cout<<endl<<" enter number";
		cin>>num;
	if(count==0)
	{	 temp=new Node();
		temp->data=num;
		temp->next=NULL;
		start=temp;
		cout<<endl<<"   "<<"@@@@@@ node inserted @@@@@@";
	}
	else
	{ 
	   for(x=start;x->next!=NULL;x=x->next);
	   temp=new Node;
	   temp->data=num;
	   temp->next=NULL;
	   x->next=temp;
		cout<<endl<<" "<<"@@@@@ node inserted @@@@@@";
	}
	count++;
}
void addNodefirst()
{
	cout<<endl<<" enter numnber to insert";
	cin>>num;
	temp=new Node();
	temp->data=num;
	temp->next=start;
	start=temp;
	cout<<endl<<" "<<"@@@@node inserted@@@@@";
	count++;
	
}
void display()
{
	for(x=start;x!=NULL;x=x->next)
	{
		cout<<endl<<" "<<x->data;
	}
}
void addNodemiddle()
{
	Node *m=start;
	int loc;
	cout<<endl<<"enter loction to insert";
	cin>>loc;
	if(count>loc)
	{
		cout<<endl<<"enter number to insert";
		cin>>num;
		for(i=1;i<loc-1;i++)
		{
			m=m->next;
		}
		temp=new Node();
		temp->data=num;
		temp->next=m->next;
		m->next=temp;
    	cout<<endl<<" "<<"@@@@@ node inserted @@@@@@@";
        count++;
	}
	else
	{
		cout<<endl<<" invalid location";
	}
	
}
void deleteNodefirst()
{
	if(count!=0)
	{
	    	x=start;
		  start=x->next;
		  x->next=NULL;
		  cout<<endl<<"  "<<"@@@@@@node deleted @@@@@"<<x->data;
		  count--;
		  delete x;
	}
	else
	{
		cout<<endl<<" no nodes ";
	}
}
void deleteNodelast()
{
	x=start;
	if(count!=0)
	{
		 
		for(i=1;i<count-1;i++);
		{
			x=x->next;
		}
		temp=x->next;
		x->next=NULL;
		cout<<endl<<" "<<"@@@@node deleted @@@@@"<<temp->data;
		delete temp;	
		count--;
		}
}
void deleteNodemiddle()
{
	x=start;
	Node *q;
	if(count!=0)
	{
		int loc;
		cout<<endl<<"enter location to delete";
		cin>>loc;
		for(i=1;i<loc-1;i++)
		{
			x=x->next;
		}
		 q=x->next;
		x->next=q->next;
		q->next=NULL;
		cout<<endl<<" "<<"@@@@ node deleted @@@@";
		delete x;
		count--;
		
	}
}
void searchNode()
{
	if(count!=0)
	{
		int search;
		cout<<endl<<"enter element to search";
		cin>>search;
		x=start;
	while(x!=NULL){
		if(x->data==search)
		{
			cout<<endl<<"element found"<<search;
			break;
		}
		x=x->next;
	} 
	

	}
		else
		{
			cout<<endl<<"no element to search";
		}

}
void sortasc()
{
	Node *t1;
	Node *t2;
	int tmp;
	for(t1=start;t1!=NULL;t1=t1->next)
	{
		for(t2=t1->next;t2!=NULL;t2=t2->next)
		{
			if(t1->data>t2->data)
			{
				tmp=t1->data;
				t1->data=t2->data;
				t2->data=tmp;
			}
		}
	}
}

