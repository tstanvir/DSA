#include<bits/stdc++.h>
using namespace std;

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
		this->next=NULL;
	}
};


class Stack{
	Node* head;
public:
	Stack(){
		head=NULL;
	}

	void push(int data);
	void pop();
	int top();
	bool isEmpty();
};

void Stack::push(int data){
	Node* newNode=new Node(data);
	if(head==NULL){
		head=newNode;
		return;
	}
	newNode->next=head;
	head=newNode;
}

bool Stack::isEmpty(){
	return (head==NULL);
}
int Stack::top(){
	return head->data;
}
void Stack::pop(){
	Node* temp=head;
	head=head->next;
	delete temp;
}
void ReverseUsingStack(vector<int>& v){
	Stack st;
	for(int i:v)
	{
		st.push(i);
	}
	v.clear();
	while(!st.isEmpty()){
		v.push_back(st.top());
		st.pop();
	}
}
int main(){
	Stack st;
	st.push(5);
	st.push(4);
	st.push(11);
	while(!st.isEmpty()){
		int u=st.top();
		st.pop();
		cout<<u<<" ";
	}
	cout<<endl;

	vector<int>v({4,5,2});
	ReverseUsingStack(v);
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}