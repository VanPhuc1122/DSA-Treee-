#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 200005;
int a[maxn], n;
int t[4 * maxn];
// t[v] = tổng cac phần tử chỉ số l tới r
void build(int v, int l, int r){
	if(l == r){
		t[v] = a[l]; // các node lá (leaf)		
	}else{
		int m = (l + r) / 2;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
}
// query: O(logN), a[l, r]
int sum(int v, int tl, int tr, int l, int r){
	if(l == tl && r == tr){
		return t[v];
	}else{
		int tm = (tl + tr) / 2;
		return sum(2 * v, tl,)
	}
}
int main(){
    cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	for(int i = 1; i <= 20; i++){
		cout << t[i] << " ";
	}
	return 0;
}