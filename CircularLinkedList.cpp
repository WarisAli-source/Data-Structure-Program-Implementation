#include<iostream>
using namespace std;

class Node{
	public:
		int key;
		int data;
		Node* next;
		
		Node()
		{
			key=0;
			data=0;
			next=NULL;
		}
		Node(int k,int d)
		{
			key=k;
			data=d;
		}
	
	
	
};
class CircularLinkedList{
	public:
		Node* head;
	CircularLinkedList()
	{
		head=NULL;
	}		
	//1.Check if node exists using key value
	Node* nodeExists(int k)
	{
		Node* temp=NULL;
		Node* ptr = head;
		if(ptr==NULL)
	{
		return temp;
	}
	else
	{
		do
		{
			if(ptr->key ==k)
			{
				temp=ptr;
				
			}
			ptr=ptr->next;
		}while(ptr!=head);
		return temp;
	}	
	}
	
	//2. Append a Node to List
	void appendNode(Node *new_node)
	{
		if(nodeExists(new_node->key)!=NULL)
		{
			cout<<"Node Already exists with key value: "<<new_node->key<<"- Append another node with different key Value"<<endl;
			
			
			
		}
		else
		{
			if(head==NULL)
			{
				head=new_node;
				new_node->next=head;
				cout<<"Node Appended at first Head position"<<endl;
			}
			else
			{
				Node* ptr=head;
				while(ptr->next!=head){
					ptr=ptr->next;
				}
				ptr->next=new_node;
				new_node->next=head;
				cout<<"Node Appended"<<endl;
				}			
		}
		
	}		
	//3. Prepend Node - Insert a Node at the start
	void prependNode(Node* new_node)
	{
		if(nodeExists(new_node->key)!=NULL)
		{
			cout<<"Node already Exists with the key value :"<<new_node->key<<"Append Another node with different key value"<<endl;
		}
		else
		{
			if(head==NULL)
			{
				head=new_node;
				new_node->next=head;
				cout<<"Node Appended at first Head position"<<endl;
			}
			else
			{
				Node* ptr= head;
				while(ptr->next!=head)
					{
						ptr=ptr->next;
				
					}		
					ptr->next=new_node;
					new_node->next=head;
					head = new_node;
					cout<<"Node Appended"<<endl;
			}		
		}
	}
	//4. Insert Node after a particular node in the list
	void insertNodeAfter(int k,Node *new_node)
	{
		Node* ptr = nodeExists(k);
		if(ptr==NULL)
		{
			cout<<"No Node exists with key value of :"<<k<<endl;
		}
		else
		{
			if(nodeExists(new_node->key)!=NULL)
			{
				cout<<"Node already Exists with the key value :"<<new_node->key<<"Append Another node with different key value"<<endl;
			}
			else
			{
				if(ptr->next=head)
				{
					new_node->next=head;
					ptr->next=new_node;
					cout<<"Node Inserted at the End"<<endl;
				}	
				else
				{
					new_node->next=ptr->next;
					ptr->next=new_node;
					cout<<"Node Inserted in between"<<endl;
				}	
			}
			
		}		
	}
	//5.Delete Node by Key
	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if(ptr==NULL)
		{
			cout<<"No Node Exists with key value of:"<<k<<endl;	
		}
		else
		{
			if(ptr==head)
			{
				if(head->next==NULL)
				{
					head=NULL;
					cout<<"Head node Unlinked... List Empty";
				}
				else
				{
					Node* ptr1=head;
					while(ptr->next!=head)
					{
						ptr=ptr1->next;
					}
					ptr1->next=head->next;
					head=head->next;
					cout<<"Node UNLINKED with key value :"<<k<<endl;
					
				}
				
				
			}
			else
			{
				Node* temp =NULL;
				Node* prevptr=head;
				Node* currentptr=head->next;
				while(currentptr!=NULL)
				{
					if(currentptr->key==k)
					{
						temp=prevptr->next;
						currentptr=NULL;
					}
					else
					{
						prevptr=prevptr->next;
						currentptr=currentptr->next;
					}
				}
				prevptr->next=temp->next;
				cout<<"Node UNLINKED with keys value :"<<k<<endl;
			}
			
			
		}
			
		
	}
	//6. Update Node
	void updateNodeByKey(int k,int new_data)
	{
		Node* ptr =nodeExists(k);
		if(ptr!=NULL)
		{
			ptr->data=new_data;
			cout<<"Node Data Updated Successfully"<<endl;
			
		}
		else
		{
			cout<<"Node Doesn't Exist with key value: "<<k<<endl;
		}
		
	}
	//7. Printing
	void printList()
	{
		if(head==NULL)
		{
			cout<<"No Node in Singly Linked List";
		}
		else
		{
			cout<<endl<<"Head address: "<<head<<endl;
			cout<<"Singly Linked List Values :"<<endl;
			Node* temp=head;
			do
			{
				cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<") -->";
				temp=temp->next;
			}while(temp!=head);
		}
		
	}
	
};


int main()
{
	CircularLinkedList s;
	int option;
	int key1,k1,data1;	
	do
	{
		cout<<"\n What operation do you want to perform? Select Option number ,Enter 0 to exit "<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNode()"<<endl;
		cout<<"4. deleteNode()"<<endl;
		cout<<"5. updateNode()"<<endl;
		cout<<"6. print()"<<endl;
		cout<<"7. Clear Screen"<<endl;
		cin>>option;
		Node* n1 =new Node();
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				cout<<"Append Node Operation \nEnter key and data of the node to be append"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				//cout<<n1.key<<" "<<n1.data<<endl;
				break;
			case 2:
				cout<<"Preppend Node Operation \nEnter key and data of the node to be prepend"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"Insert Node after operation\nEnter key of existing Node after which you want to insert this node"<<endl;
				cin>>k1;
				
				cout<<"Enter key & data of the data New Node first "<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.insertNodeAfter(k1,n1);
				
				break;
			case 4:
				cout<<"Delete Node By key Operation -\nEnter key of the Node to be deleted: "<<endl;
				cin>>k1;
				s.deleteNodeByKey(k1);
				
			case 5:
				cout<<"Update Node by key Operation - \nEnter key and New Data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNodeByKey(key1,data1);
				break;
			
			case 6:
				s.printList();
				break;
			case 7:
				system("cls");
                break;			
			default:
				cout<<"Enter Proper Option number"<<endl;		
				
		}
	}while(option!=0);
	
	return 0;
}
