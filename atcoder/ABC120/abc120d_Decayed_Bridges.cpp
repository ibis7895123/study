#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	//Aがどのグループに属しているか調べる
	int root(int A) {
		//cout << "root in" << endl;
		//cout << "Parent[A]:" << Parent[A] << endl;
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//自分のいるグループの頂点数を調べる
	int size(int A) {
		return -Parent[root(A)];//親をとってきたい
	}

	//AとBをくっ付ける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
			return false;
		}

		//大きい方(A)に小さいほう(B)をくっ付けたい
		//大小が逆だったらひっくり返しちゃう。
		if (size(A) < size(B)) swap(A, B);

		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;

		return true;
	}
};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> A(M), B(M);

	FOR(i,0,M) {
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	cout << "Input" << endl;
	FOR(i, 0, M) cout << A[i] << " " << B[i] << endl;

	vector<long long> ans(M);
	ans[M - 1] = (long long)N * (N - 1) / 2;
	
	UnionFind uni(N);

	REF(i,M-1,0) {
		cout << "A,B: " << A[i] << " " << B[i] << endl;

		cout << "Parent" << endl;
		FOR(i,0,N) cout << uni.Parent[i] << endl;
		cout << "root(A)" << uni.root(A[i]) << endl;
		cout << "root(B)" << uni.root(B[i]) << endl;
		cout << "size(A)" << uni.size(A[i]) << endl;
		cout << "size(B)" << uni.size(B[i]) << endl;

		//つながってなかったのがつながったとき
		if (uni.root(A[i]) != uni.root(B[i])) {
			ans[i - 1] = ans[i]
				- (long long)uni.size(A[i]) * uni.size(B[i]);
			uni.connect(A[i], B[i]);

		}
		else ans[i - 1] = ans[i];
	}

	FOR(i, 0, M) {
		cout << ans[i] << endl;
	}

}

