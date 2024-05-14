#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	// cấp phát mảng động
	node(int x){
	   data = x;
	   left = right = NULL;	
	}
};
void makeRoot(node *root, int u, int v, char c){
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
// cho v là node con của u
void insertNode(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data == u){
		makeRoot(root, u, v, c);
	}else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}
void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int main(){
	node *root = NULL;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if(root == NULL){
			// cấp phát mảng động mới cho node
			root = new node(u);
			makeRoot(root, u, v, c);
		}else{
			insertNode(root, u, v, c);
		}
	}
	// duyệt giữa
	inorder(root);
	return 0;
}