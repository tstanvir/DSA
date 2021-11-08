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
            if(m<n){
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
    cin>>t;
    while(t--){
        int index;
        cin>>index;
        int l;
        cin>>l;
        List A,B;
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            A.Insert(x);
        }
       A.print(A.head);
        cin>>l;
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            B.Insert(x);
        }
        B.print(B.head);
    }
    return 0;
}
