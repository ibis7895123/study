#include "pch.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;

/*int n;

//a��b�̍ő���񐔂�Ԃ�
int gcd(ll a, ll b) {
	//a�̕����傫���Ȃ�悤����ւ�
	if (a < b) swap(a, b);
	
	//b == 0�Ȃ�a��Ԃ�
	if (b == 0) return a;

	//�I������
	if (a % b == 0) return b;

	return gcd(b, a%b);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<ll> a(n);
	FOR(i, 0, n) cin >> a[i];

	//cout << gcd(a[2], a[1]) << endl;

	//�ݐϘa�v�Z
	//���ݐϘaL
	vector<ll> L(n+1,0);
	FOR(i, 0, n) {
		L[i + 1] = gcd(L[i], a[i]);
	}

	cout << "L:" << endl;
	FOR(i, 0, n+1) cout << L[i] << endl;
	cout << endl;

	//�E�ݐϘaR
	vector<ll> R(n + 1, 0);
	REF(i, n-1, -1) {
		R[i] = gcd(R[i + 1], a[i]);
	}

	cout << "R:" << endl;
	FOR(i, 0, n + 1) cout << R[i] << endl;
	cout << endl;

	//a����a[i]�𔲂���gcd���v�Z�A�ő�l���X�V
	//ans = gcd(L[i], R[i+1])
	ll max1 = 0;
	FOR(i, 0, n) {
		ll ans = gcd(L[i], R[i + 1]);
		cout << "ans:" << ans << endl;
		max1 = max(max1, ans);
	}
	cout << max1 << endl;
}*/