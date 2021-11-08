#include <bits/stdc++.h>
using namespace std;


class DLinkedList{
	class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(){
			data=0;
			next=NULL;
			prev=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
	};
	
public:
	Node* head;
	Node* tail;
	DLinkedList(){head=NULL;}
	void insertAtHead(int x);
	void insertAtTail(int x);
	void print();
	void reversePrint();
	void reverseIterative();
	void reverseRecursive(Node* cur);
	int size();
};

void DLinkedList::insertAtHead(int data){
	Node* newNode= new Node(data);
	if(head==NULL){
		head=newNode;
		tail=head;
		return;
	}

	head->prev=newNode;
	newNode->next=head;
	head=newNode;
	tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
}
void DLinkedList::insertAtTail(int data){
	Node* newNode=new Node(data);
	if(head==NULL){
		head=newNode;
		tail=head;
		return;
	}
	newNode->prev=tail;
	tail->next=newNode;
	tail=newNode;
}
void DLinkedList::print(){
	Node* cur=head;
	while(cur!=NULL){
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
void DLinkedList::reversePrint(){
	Node* cur=tail;
	while(cur!=NULL){
		cout<<cur->data<<" ";
		cur=cur->prev;
	}
	cout<<endl;
}
int DLinkedList::size(){
	int cnt=0;
	Node* cur=head;
	while(cur!=NULL){
		cnt++;
		cur=cur->next;
	}
	return cnt;
}
void DLinkedList::reverseIterative(){
	Node* cur=head;
	while(cur!=NULL){
		Node* prev=cur->prev;
		cur->prev=cur->next;
		cur->next=prev;

		head=cur;

		cur=cur->prev;
	}
}
void DLinkedList::reverseRecursive(Node* cur){
	if(cur==NULL) return;
	if(cur->next==NULL){
		head=cur;
		return;
	}
	reverseRecursive(cur->next);
	Node* nextWas=cur->next;
	cur->prev=nextWas;
	cur->next=NULL;
	nextWas->prev=nextWas->next;
	nextWas->next=cur;
}
int main(){
	DLinkedList list;
	list.insertAtTail(2);
	list.insertAtTail(1);
	list.insertAtTail(6);
	list.insertAtTail(14);
	list.insertAtTail(23);
	list.insertAtTail(6134);
	cout<<list.size()<<endl;
	list.print();
	list.reverseRecursive(list.head);
	list.print();
	return 0;
}