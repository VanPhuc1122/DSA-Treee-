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
int dem_la(node *root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	int dem = 0;
	dem += dem_la(root->left);
	dem += dem_la(root->right);
	return dem;
}
// chiều cao của cây
int count(node *root){
	if(root == NULL) return -1;
	// chiều cao lướn nhất bằng node con bên trái + 1 vì node gốc ban đầu cs cạnh bằng 0
	return max(count(root->left) + 1, count(root->right) + 1);
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
	int nodela = dem_la(root);
	cout << nodela << endl;
	int cao = count(root);
	cout << cao << endl;
	return 0;
}