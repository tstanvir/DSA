#include <bits/stdc++.h>
using namespace std;

//linkedlist

struct Node{
	int data;
	Node* next;
};
// Node* head;


void pushFront(int x,Node* head){
	Node* temp=new Node();
	temp->data=x;
	temp->next=head;
	head=temp;
}
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

/*
//recursive approach

void print(Node* temp){
	if(temp==NULL) {
		cout<<endl;
		return;
	}
	cout<<temp->data<<" ";
	print(temp->next);
	
}*/
Node* insertInto(int data, int i,int& tot,Node* head){
	if(0<=i-1 and i-1<=tot){
		tot++;
		Node* temp1=new Node();
		temp1->data=data;
		temp1->next=NULL;
		if(i==1){
			temp1->next=head;
			head=temp1;
			return head;
		}
		Node* temp2=head;
		for(int j=0;j<i-2;j++){
			temp2=temp2->next;
		}
		temp1->next=temp2->next;
		temp2->next=temp1;

	}
	else{
		cout<<"inValid query"<<endl;
	}
	return head;
}


Node* deleteAt(int i,int& tot,Node* head){
	if(i>=1 and i<=tot){
		// cout<<i<<" "<<tot<<endl;
		tot--;
		if(i==1){
			Node* temp=head;
			head=head->next;
			delete temp;
			return head;
		}
		Node* temp=head;
		for(int j=0;j<i-2;j++){
			temp=temp->next;
		}

		Node* candidate=temp->next;
		
		temp->next=candidate->next;
		delete candidate;
	}
	else{
		cout<<"inValid query"<<endl;
	}
	return head;
}


/*
//iterative

void reverseList(){
	Node *cur,*next,*prev=NULL;
	cur=head;
	while(cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
}*/
void reverseList(Node* cur,Node** head_ref){
	if(cur==NULL) return;
	if(cur->next==NULL){
		*head_ref=cur;
		return;
	}
	reverseList(cur->next,head_ref);
	Node* nextWas=cur->next;
	cur->next=NULL;
	nextWas->next=cur;
}

void Free(Node** head_ref){
	Node* cur=*head_ref;
	while(cur!=NULL){
		Node* next=cur->next;
		cout<<cur->data<<" ";
		delete cur;
		cout<<cur->data<<" ";
		cur=next;
	}
	cout<<endl;
	*head_ref=cur;
}

int Size(Node* cur){
	int cnt=0;
	while(cur!=NULL) {
		cur=cur->next;
		cnt++;
	}
	return cnt;
}
int main(){ 
	int tot=0;
	Node* head=NULL;
	head=insertInto(3,1,tot,head);
	head=insertInto(18,2,tot,head);
	head=insertInto(98,3,tot,head);
	head=insertInto(4,4,tot,head);
	head=insertInto(12,5,tot,head);
	cout<<Size(head)<<endl;
	print(head);
	reverseList(head,&head);
	print(head);
	return 0;
}