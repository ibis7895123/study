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

	int r;
	//���[�N���b�h�̌ݏ��@
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}

	return b;
}

//O(n^2)�̂���TLE�ɂȂ�
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<ll> a(n);
	FOR(i, 0, n) cin >> a[i];

	//cout << gcd(a[2], a[1]) << endl;

	//a����1�����čő���񐔋��߂�
	int max1 = 0;
	FOR(tgt, 0, n) {
		int ans;
		if (tgt == 0) ans = a[1];
		else ans = a[0];

		//a�̍ő�A�ŏ��l���߂�
		//�����������ő�or�ŏ��l�Ȃ�����čČv�Z
		int amax = *max_element(a.begin(), a.end());
		if (amax == a[tgt]) {
			vector<ll> tmp1 = a;
			tmp1.erase(tmp1.begin() + tgt);
			amax = *max_element(tmp1.begin(), tmp1.end());
		}
		else amax = *max_element(a.begin(), a.end());

		int amin = *min_element(a.begin(), a.end());
		if (amin == a[tgt]) {
			vector<ll> tmp2 = a;
			tmp2.erase(tmp2.begin() + tgt);
			amin = *min_element(tmp2.begin(), tmp2.end());
		}

		ans = gcd(amax, amin);
		
		FOR(i, 1, n) {
			if (i == tgt) continue;
			ans = gcd(ans, a[i]);
		}
		cout << ans << endl;
		max1 = max(max1, ans);
	}
	cout << "max:" << max1 << endl;
}*/