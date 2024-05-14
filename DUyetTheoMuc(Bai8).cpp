#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}	
};
void makeroot(node *root, int u, int v, char c){
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insert(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data = u){
		makeroot(root, u, v, c);
	}else{
		insert(root->left, u, v, c);
		insert(root->right, u, v, c);
	}
}
// duyệt theo mức
void level(node *root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *tmp = q.front();
		q.pop();
		cout << tmp->data << " ";
		if(tmp->left != NULL){
			q.push(tmp->left);
		}
	    if(tmp->right != NULL){
	    	q.push(tmp->right);
		}
	}
}
// đếm node lá
int dem_la(node *root){
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return 1;
	}
	int dem = 0;
	dem += dem_la(root->left);
	dem += dem_la(root->right);
	return dem;
}
// độ cao của cây
int count(node *root){
	if(root == NULL) return -1;
	return max(count(root->left) + 1, count(root->righ) + 1);
}
int main(){
	node *root = NULL;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if(root == NULL){
			root = new node(u);
			makeroot(root, u, v, c);
		}else{
			insert(root, u, v, c);
		}
	}
	level(root);
	return 0;
}