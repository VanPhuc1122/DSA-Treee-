#include <bits/stdc++.h>
using namespace std;
struct node{
   int data;
   node *left;
   node *right;
   // mảng cấp phát động
   node(int x){
   	 data = x;
   	 left = right = NULL;
   }	
};
// Các thứ tự duyệt của cây nhị phân
// duyệt giữa (left, root, right)
void inorder(node *root){ // sử dụng con trỏ đến root và root quản lí thông tin node
	if(root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
// duyệt trước(root-left-right)
void preoder(node *root){
	if(root != NULL){
		cout << root->data << " ";
		preoder(root->left);
		preoder(root->right);
	}
}
// duyệt sau(left-right-root)
void postorder(node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
// duyệt theo mức level (sử dụng thuật toán BFS)
void level(node *root){
	queue<node*> q;
	q.push(root);
	cout << root->data << " ";
	while(!q.empty()){
		node *tmp = q.front(); q.pop();
		q.push(tmp->left);
		cout << tmp->left->data << " ";
	}
	if(tmp->right != NULL){
		q.push(tmp->right);
		cout << tmp->right->data << " ";
	}
}
// Duyệt theo xoắn ốc
void xoanoc(node *root){
	stack<node*> s1, s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
		    root *top = s1.top(); s1.pop();
		    cout << top->data << " ";
		    if(top->right != NULL){
		    	s2.push(top->right);
			}
			if(top->left != NULL){
				s2.push(top->left);
			}
		}
		while(!s2.empty()){
			root *top = s2.top(); s2.pop();
			cout << top->data << " ";
			if(top->left != NULL){
				s1.push(top->left);
			}
			if(top->right != NULL){
				s1.push(top->right);
			}
		}
	}
}
// Cây nhị phân tìm kiếm
bool search(node *root, int key){
	if(root == NULL) return false;
	if(root->data == key) return true;
	else if(root->data < key){
		return search(root->right, key);
	}else{
		return search(root->left, key);
	}
}
// Thao tác chèn cây nhị phân
node *insert(node *root, int key){
	if(root == NULL){
		return new node(key);
	}
	if(key < root->data){
		root->left = insert(root->left, key);
	}else if(ket > root->data){
		root->right = insert(root->right, key);
	}
	return root;
}
// Thao tác xoá node trong cây nhị phân
node* minNode(node *root){
	node *tmp = root;
	while(tmp != NULL && tmp->left != NULL){
		tmp = tmp->left;
	}
	return tmp;
}
node* deleteNode(node *root, int key){
	if(root == NULL) return root;
	if(key < root->data){
		root->left = deleteNode(root->left, key);
	}else if(key > root->data){
		root->right = deleteNode(root->right, key);
	}else{
		if(root->left == NULL){
			node *tmp = root->right;
			delete root;
			return tmp;
		}else if(root->right == NULL){
			node *tmp = root->left;
			delete root;
			return tmp;
		}else{
			node *tmp = minNode(root);
			root->data = tmp->data;
			root->right = deleteNode(root->right, root->data);
		}
	}
	return root;
}
// đếm node lá
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
// Cây nhị phân đầy đủ
bool check(node *root){
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL){
		return true;
	}
	if(root->left != NULL && root->right != NULL){
		return check(root->left) && check(root->right);
	}else{
		return false;
	}
}
// kiểm tra node lá cùng mức
set<int> se;
void preo(node *root, int cnt){
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL) se.insert(cnt);
	preo(root->left, cnt + 1);
	preo(root->right, cnt + 1);
}
// cây nhị phân hoàn hảo
int check = 1;
set<int> se;
void ino(node *root, int cnt){
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL || root->left != NULL && root->right != NULL){
	check = 0;	
}
if(root->left == NULL && root->right == NULL) se.insert(cnt);
ino(root->left, cnt + 1);
ino(root->right, cnt + 1);
int main(){
	
	return 0;
}