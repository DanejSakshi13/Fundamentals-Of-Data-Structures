/* Department of Computer Engineering has student club named; Pinnacle Club. Students of second, third and final year of department can be granted membership on 
request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. 
Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.*/

#include <iostream>
#include <string.h>
using namespace std;
class node
{
	friend class list;
	int prnno;
	char name[30];
	node *next;//pointer to object
	public:
		node(int d,char s[10])
		{
			prnno=d;
			strcpy(name,s);
			next=NULL;
		}
};
class list
{
	node *start;
	public:
		list()
		{
			start=NULL;
		}
	void display()
	{
		node *ptr;
		ptr=start;
		cout<<"\n info is : \n";
		while(ptr!=NULL)
		{
			cout<<"\n"<<ptr->prnno;
			cout<<"\t"<<ptr->name;
			ptr=ptr->next;
		}
	}
	void insertMember();
	void createMember();
	void insertPresident();
	void insertSecretary();
	void deleteMember();
	void delete1();
	void deleteSecretary();
	void deletePresident();
	void count();
	void reverse(node *);
	void reverse1()
	{
	reverse(start);
	}
	void concatenate(list,list);
};
void list::insertMember()
{
	int prnno;
	char name[30];
	node *ptr,*temp;
	cout<<"\n Enter PRN no. : ";
	cin>>prnno;
	cout<<"\nEnter your name : ";
	cin>>name;
	temp=new node(prnno,name);
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void list::insertPresident()
{
	int prnno;
	char name[30];
	node *temp;
	cout<<"\n Enter PRN no. :";
	cin>>prnno;
	cout<<"\n Enter your name :";
	cin>>name;
	temp=new node(prnno,name);
	temp->next=start;
	start=temp;
}
void list::insertSecretary()
{
	int prnno;
	char name[30];
	node *ptr,*temp;
	cout<<"\n Enter PRN no.: ";
	cin>>prnno;
	cout<<"\n Enter your name :";
	cin>>name;
	temp=new node(prnno,name);
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}
int switchcase(int &ch){
	cout<<"\n Enter your choice ";
	cout<<"\n 1.Member\n 2.Secretary\n 3.President"<<endl;
	cin>>ch;
	return ch;
}
void list::createMember()
{
	int ch;
	char ans;
	do
	{
		switchcase(ch);
		switch(ch)
		{
			case 1: insertMember();
			break;
			case 2: insertSecretary();
			break;
			case 3: insertPresident();
			break;
			default:cout<<"Invalid choice ! ";
			break;
		}
		cout<<"\n Wish to insert more data?";
		cin>>ans;
		}while(ans=='y');
}
void list::delete1()
{
	int ch;
	char ans;
	do
	{
		switchcase(ch);
		switch(ch)
		{
			case 1:deleteMember();
			break;
			case 2:deleteSecretary();
			break;
			case 3:deletePresident();
			break;
			default:cout<<"Invalid choice ! ";
			break;
		}
		cout<<"\n Wish to delete more data?";
		cin>>ans;
	}while(ans=='y');
}
void list::deleteSecretary()
{
	node *ptr,*prev;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next=NULL;
	delete ptr;
	cout<<"\n Deleted!";
}
void list::deletePresident()
{
	node *ptr;
	ptr=start;
	start=start->next;
	delete ptr;
	cout<<"\n Deleted!";
}
void list::deleteMember()
{
	node *ptr,*prev;
	int p;
	cout<<"\n Enter PRN no. to delete : ";
	cin>>p;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
		if(ptr->prnno==p)
		break;
	}
	if(ptr->next==NULL)
	{
		cout<<"\n Data not found! ";
	}
	else if(ptr->prnno==p)
	{
		prev->next=ptr->next;
		ptr->next=NULL;
		delete ptr;
		cout<<"\n Deleted!";
	}
}
void list::count()
{
	node *ptr;
	int cnt=0;
	ptr=start;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->next;
	}
	cout<<"\nTotal no. of members are : "<<cnt;
}
void list::reverse(node *ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		reverse(ptr->next);
	}
	cout<<"\n"<<ptr->prnno;
	cout<<"\t"<<ptr->name;
}
void list::concatenate(list s1,list s2)
{
	node *ptr;
	ptr=s1.start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=s2.start;
	s1.display();
}
int main()
{
	int ch;
	char ans;
	list sll1,sll2,s1,s2;
	do
	{
		cout<<"\n Enter your choice : ";
		cout<<"\n 1.Create member\n 2.Display list\n 3.Delete member\n 4.Check no. of members\n 5.Reverse\n 6.Concatenate\n ";
		cin>>ch;
		switch(ch)
		{
			case 1: sll1.createMember();
				break;
			case 2: sll1.display();
				break;
			case 3: cout<<"\n Enter the node to be deleted from the list : ";
				sll1.delete1();
				break;
			case 4: cout<<"\n No. of nodes is/are:";
				sll1.count();
				break;
			case 5: cout<<"\n Reversed linked list is:";
				sll1.reverse1();
				break;
			case 6: sll2.createMember();
				sll1.concatenate(sll1,sll2);
				break;
			default: cout<<"\n Invalid choice. ";
				break;
		}
		cout<<"\n\n Do you wish to continue ? (y/n) ";
		cin>>ans;
	}while(ans=='y');
return 0;
}
