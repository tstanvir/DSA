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
	Node* head;
	Node* tail;
public:
	DLinkedList(){head=NULL;}
	void insertAtHead(int x);
	void insertAtTail(int x);
	void print();
	void reversePrint();
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
int main(){
	DLinkedList list;
	list.insertAtHead(2);
	list.insertAtHead(5);
	list.insertAtTail(3);
	list.insertAtTail(6);
	cout<<list.size()<<endl;
	list.print();
	list.reversePrint();
	return 0;
}