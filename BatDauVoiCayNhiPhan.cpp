#include <bits/stdc++.h>
using namespace std;
struct node{
	int data; // địa chỉ node cha
	// 2 con trỏ
	node *left; // địa chỉ con bên trái
	node *right; // địa chỉ con bên phải
    // tạo construct node này
	node(int x){
		// cấp phát động
	  data = x;
	  left = right = NULL;
	}	
};
struct sinhvien{
	string ten, lop;
	double gpa;
};
struct node{
    sinhvien data;
	node *left;
	node *right;	
};
 // cách khác viết hàm cấp phát động
node* makeNode(int x){
	node *tmp = new node(x);
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}
// hàm duyệt giữa
void inor(node *root){
	if(root != NULL){
		inor(root->left);
		cout << root->data << " ";
		inor(root->right) << endl;
	}
}
//
int main(){
	node *root = makeNode(1);
	root->left = makeNode(2);
	root->right = makeNode(3);
	root->left->left = makeNode(4);
	root->left->right = makeNode(5);
	root->right->left = makeNode(7);
	root->right->right = makeNode(6);
	root->right->right->left = makeNode(8);
	while(root != NULL){
		cout << root->data << " ";
		root = root->right;
	}
	return 0;
}