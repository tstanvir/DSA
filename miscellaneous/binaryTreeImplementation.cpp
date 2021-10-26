#include<bits/stdc++.h>
using namespace std;


class Bst{
public:
	class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(){
			data=0;
			left=NULL;
			right=NULL;
		}
		Node(int data){
			this->data=data;
			left=NULL;
			right=NULL;
		}
	};
	Node* root;
	Bst(){
		root=NULL;
	}
	Node* insert(Node* root,int data){
		if(root==NULL){
			Node* new_node=new Node(data);
			root=new_node;
		}
		else if(root->data>=data){
			root->left=insert(root->left,data);
		}
		else{
			root->right=insert(root->right,data);
		}
		return root;
	}
	Node* search(Node* root,int data){
		if(root==NULL) return root;
		if(root->data==data) return root;
		if(root->data>=data) 
			return search(root->left,data);
		return search(root->right,data);
	}
	Node* min(Node* root){
		if(root->left==NULL){
			return root;
		}
		return min(root->left);
	}
	Node* max(Node* root){
		if(root->right==NULL){
			return root;
		}
		return max(root->right);
	}
	int Max(int a,int b){
		if(a>=b) return a;
		return b;
	}
	int height(Node* root){
		if(root==NULL){
			return -1;
		}
		int l=height(root->left);
		int r=height(root->right);
		return Max(l,r)+1;
	}
	Node* Delete(Node* root,int data){
		if(root==NULL) return NULL;
		if(root->data==data){
			if(root->left==NULL and root->right==NULL){
				delete root;
				root=NULL;
			}
			else if(root->left==NULL){
				Node* temp=root;
				delete temp;
				root= root->right;
			}
			else if(root->right==NULL){
				Node* temp=root;
				delete temp;
				root= root->left;
			}
			else{
				Node* maxi=max(root->left);
				//cout<<"maximum in left: "<<maxi->data<<endl;
				root->data=maxi->data;
				root->left=Delete(root->left,maxi->data);
			}
		}
		else if(root->data>data){
			root->left=Delete(root->left,data);
		}
		else {
			root->right=Delete(root->right,data);
		}
		return root;
	}

	void preOrder(Node* root){
		if(root==NULL) {
			return;
		}
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
	void inOrder(Node* root, vector<Node*>& v){
		if(root==NULL) return;
		inOrder(root->left,v);
		v.push_back(root);
		inOrder(root->right,v);
	}
	void inOrder(Node* root){//function overloading
		if(root==NULL) return;
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	void postOrder(Node* root){
		if(root==NULL) return;
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}

	Node* bstToBbstUtil(vector<Node*>nodes,int l,int r){
		if(r<l){
			return NULL;
		}
		int mid=(l+r)/2;
		Node* root=nodes[mid]; 
		root->left=bstToBbstUtil(nodes,l,mid-1);
		root->right=bstToBbstUtil(nodes,mid+1,r);
		return root;
	}

	Node* bstToBbst(Node* root){//BST to Balance Bst
		vector<Node*>nodes;
		inOrder(root,nodes);//inorder traversal of bst gives 
							//us a sorted sequence
		int n=nodes.size();
		return bstToBbstUtil(nodes,0,n-1);
	}
	Node* getSuccessor(Node* root,int data){
		Node* node=search(root,data);
		if(node==NULL) return NULL;
		if(node->right!=NULL){
			return min(node->right);
		}
		Node* cur=root;
		Node* successor=NULL;
		while(cur!=node){
			if(data<cur->data){
				successor=cur;
				cur=cur->left;
			}
			else cur=cur->right;
		}
		return successor;
	}
};

bool isBst(Bst::Node* root){
	if(root==NULL) return 1;
	if(root->left!=NULL and root->left->data>root->data){
		return 0;
	}
	if(root->right!=NULL and root->right->data<=root->data){
		return 0;
	}
	return (isBst(root->left)or isBst(root->right));
}
int main(){
	Bst st;
	st.root=st.insert(st.root,9);
	st.root=st.insert(st.root,5);
	st.root=st.insert(st.root,4);
	st.root=st.insert(st.root,2);
	st.root=st.insert(st.root,1);
	st.root=st.insert(st.root,0);
	if(isBst(st.root)){
		cout<<"BST"<<endl;
	}
	else cout<<"NOT BST"<<endl;
	// cout<<"root: "<<st.root->data<<endl;
	// if(st.search(st.root,1)){
	// 	cout<<"found"<<endl;
	// }
	// else cout<<"not found"<<endl;
	// cout<<"maximum: "<<st.max(st.root)->data<<" minimum: "<<st.min(st.root)<<endl;
	// cout<<"height: "<<st.height(st.root)<<endl;
	 st.preOrder(st.root);
	cout<<endl;
	// st.root=st.Delete(st.root,9);
	// st.inOrder(st.root);
	// cout<<endl;
	// cout<<st.root->data<<endl;
	// if(st.search(st.root,9)){
	// 	cout<<"found"<<endl;
	// }
	// else cout<<"not found"<<endl;
	st.root=st.bstToBbst(st.root);
	st.preOrder(st.root);
	cout<<endl;
	st.inOrder(st.root);
	cout<<endl;
	if(st.getSuccessor(st.root,1)!=NULL)
		cout<<st.getSuccessor(st.root,1)->data<<endl;
	else cout<<"Not found"<<endl;
	return 0;
}