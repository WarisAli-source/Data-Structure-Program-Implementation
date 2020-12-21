#include<iostream>
using namespace std;

class Node{
	public:
		int key; //Key
		int data;  // Data of one node
		Node* next;  // pointer to next
		
		Node(){
			key = 0;
			data = 0;
			next = NULL;
			
		}
		Node(int k, int d){
			key = k;
			data = d;
			
			
		}
};

class SinglyLinkedList{
	public:
		Node* head;
		
	SinglyLinkedList(){
		head = NULL;	
	}
	SinglyLinkedList(Node *n){
		head = n;	
	}
	
	// 1. Check if node exist using key value
	Node* nodeExists(int k){
		Node* temp = NULL;
		Node* ptr = head;
		while(ptr !=NULL){
			if(ptr->key==k){
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
		
	}
	
	//2. Append a node to the linked list
	void appendNode(Node *n){
		if(nodeExists(n->key)!= NULL){
			cout<<"Node already Exist with the key value"<<n->key<<". Append any other noe with different key value"<<endl;
			
		}
		else{
			if(head== NULL){
				head = n;
				cout<<"Node Appended"<<endl;
				
			}
			else{
				Node* ptr = head;
				while(ptr->next!=NULL){
					ptr = ptr->next;
				}
				ptr->next = n;
				cout<<"Node Appended"<<endl;
			}
			
		}
	}
	// 3. Prepend node - Append a node at start
	void prependNode(Node* n ){
		if(nodeExists(n->key)!= NULL){
			cout<<"Node already Exist with the key value"<<n->key<<". Append any other noe with different key value"<<endl;
			
		}
		else{
			n->next = head;
			head = n;
			cout<<"Node prepended"<<endl;
		}
	}
	//4 . iNSERT A node after a particular node
	void insertNodeAfter(int k , Node *n)  // k is the key after which we want to insert a node And  is the node which is going to inser
	{
		 Node* ptr = nodeExists(k);	
		 if(ptr == NULL)
		 {
		 	cout<<"No Node exist with key value";
		 }
		 else
		 {
		 	if(nodeExists(n->key)!= NULL){
			cout<<"Node already Exist with the key value"<<n->key<<". Append any other noe with different key value"<<endl;
			}
			else
			{
				n->next = ptr->next;
				ptr->next = n;
				cout<<"Node Inserted"<<endl;
			}
		 }
	}
	
	// 5 Deleting a Node by key
	void deleteNodeByKey(int k){
		if(head==NULL){
			cout<<"Singly linked list already empty"<<endl;
				
		}
		else if(head!=NULL){
			if(head->key==k){
				head = head->next;
				cout<<"Node Unlinked with keys value"<<k<<endl;
				
			}
			else
			{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while(currentptr!=NULL)
				{
					if (currentptr->key==k)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				if(temp!=NULL)
				{
					prevptr->next=temp->next;
					cout<<"Node UNLINKED with keys value : "<<k<<endl;
				}
				else
				{
					cout<<"Node doesn't exist with key value :"<<k<<endl;
				}
			}
			
		}
		
	}
		//	6Th  Update Node
	void updateNodeByKey(int k,int d){
			Node* ptr = nodeExists(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"Node Data Updated Succesfully"<<endl;
			}
			else
			{
				cout<<"Node Doestn't exist with key value :"<<k<<endl;
			}
		}
		// 7th Printing
	void printList(){
			if(head==NULL)
			{
				cout<<"No nodes in singly linked list";
			}
			else{
				cout<<endl<<"Singly Linked List Values :";
				Node* temp = head;
				while(temp!=NULL)
				{
					cout<<"("<<temp->key<<","<<temp->data<<") -->";
					temp = temp->next;
				}
			}
			
		}
		
	};
	


int main(){
	SinglyLinkedList s;
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
