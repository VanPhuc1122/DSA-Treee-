#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left , *right;
    Node(int x)
    {
        val = x;
        right = left = NULL;
    }
};
void make(Node *root , int u , int v , char c)
{
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}
void find(Node *root , int u , int v , char c)
{
    if(root == NULL) return;
    if(root->val == u)
    {
        make(root , u , v , c);
    }
    else
    {
        find(root->left , u , v , c);
        find(root->right , u , v , c);
    }
}
bool check1(Node *root, int h, int &maxh){
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL){
		if(maxh == 0){
			maxh = h;
			return true;
		}else{
			return maxh = h;
		}
	}else return check1(root->right, h + 1, maxh) && check1(root->left, h + 1, maxh);
}
bool check2(Node *root){
	if(root == NULL) return true;
	if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) return false;
	else check2(root->left) && check2(root->right);
}
int main(){
	int n ; cin >> n;
    Node *root = NULL;
    while(n--)
    {
        int u , v ; char c ; cin >> u >> v >> c;
        if(root == NULL)
        {
            root = new Node(u);
            make(root , u , v , c);
        }
        else find(root , u , v , c);
    }
    int maxh = 0;
    if(check1(root, 0, maxh) && check2(root)) cout << "YES\n";
    else cout << "NO\n";
	return 0;
}