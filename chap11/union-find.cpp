#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct UnionFind {
	vector<int> par, siz;

	UnionFind(int n) : par(n, -1), siz(n, 1) {}

	// 経路圧縮を行いながらルートを返す
	int root(int x) {
		if(par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool unite(int x, int y) {
		x = root(x), y = root(y);

		if(x == y) return false;

		if(siz[x] < siz[y]) swap(x, y);

		par[y] = x;
		siz[x] += siz[y];
		return true;
	}

	int size(int x) {
		return siz[root(x)];
	}
};

int
main(int argc, char* argv[]) {
	UnionFind uf(7);	

	uf.unite(1, 2);
	uf.unite(2, 3);
	uf.unite(5, 6);

	cout << uf.issame(1, 3) << endl;
	cout << uf.issame(2, 5) << endl;

	uf.unite(1, 6);
	cout << uf.issame(2, 5) << endl;
	return 0;
}
