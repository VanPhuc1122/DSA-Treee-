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
void preoder(node *root){
	if(root != NULL){
		cout << root->data << " ";
		preoder(root->left);
		preoder(root->right);
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
	// duyệt theo thứ tự
	preoder(root);
	return 0;
}