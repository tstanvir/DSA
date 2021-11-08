#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class List{
    public:
        class Node{
            
            public:
            int data;
            Node* next;
                Node(){}
                Node(int data){
                    this->data=data;
                    next=NULL;
                }
        };
        Node* head=NULL;
        void Insert(int data){
            Node* newNode=new Node(data);
            if(head==NULL){
                head=newNode;
                return;
            }
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        int Size(Node* cur){
            int cnt=0;
            while(cur!=NULL){
                cnt++;
                cur=cur->next;
            }
            return cnt;
        }
        int findMergePoint(Node* headA,Node* headB){
            int n=Size(headA);
            int m=Size(headB);
            int d=m-n;
            if(m>n){
                Node* temp=headB;
                headB=headA;
                headA=temp;
                d=n-m;
            }
            for(int i=0;i<d;i++){
                headB=headB->next;
            }
            while(headB!=headA){
                headB=headB->next;
                headA=headA->next;
            }
            return headB->data;
        }
        int findMiddleElement(){
            if(head==NULL) {
                cout<<"list is empty"<<endl;
                return -1;
            }
            Node* slow=head;
            Node* fast=head->next;
            while(fast!=NULL and fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow->data;
        }
        void print(Node* cur){
            while(cur!=NULL){
                cout<<cur->data<<" ";
                cur=cur->next;
            }
            cout<<endl;
        }
};

int main() {
    int t;
    t=1;
    while(t--){
        int l;
        cin>>l;
        List A;
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            A.Insert(x);
        }
        A.print(A.head);
        cout<<A.findMiddleElement()<<endl;
    }
    return 0;
}
