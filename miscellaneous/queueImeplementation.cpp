#include<bits/stdc++.h>
using namespace std; 

class Q{
	class Node{
	public:
		int data;
		Node* next;
		Node(){
			data=0;
			next=NULL;
		}
		Node(int data){
			this->data=data;
			next=NULL;
		}
	};
	Node* head,*tail;
public:
	Q(){
		head=NULL;
		tail=NULL;
	}
	void enQ(int data);
	int dQ();
	int front();
	bool isEmpty();
	void clear();
	void print();
	void pop();

};
void Q::enQ(int data){
	Node* new_node=new Node(data);
	if(head==NULL){
		head=new_node;
		tail=new_node;
		return;
	}
	tail->next=new_node;
	tail=new_node;
}
bool Q::isEmpty(){
	return head==NULL;
}
int Q::front(){
	return head->data;
}
void Q::pop(){
	Node* temp=head;
	if(head==tail){
		head=NULL;
		tail=NULL;
		delete temp;
		return;
	}
	head=head->next;
	delete temp;
}
void Q::print(){
	Node* cur=head;
	while(cur!=NULL){
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
int Q::dQ(){
	Node* temp=head;
	int val=temp->data;
	if(head==tail){
		head=NULL;
		tail=NULL;
		delete temp;
		return val;
	}
	head=head->next;
	delete temp;
	return val;
}
void Q::clear(){
	Node* cur=head;
	while(cur!=NULL){
		Node* temp=cur;
		cur=cur->next;
		delete temp;
	}
}
int main(){
	Q q;
	q.enQ(4);
	q.enQ(6);
	q.enQ(3);
	q.print();
	if(!q.isEmpty()) q.pop();
	q.print();
	return 0;
}