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

/*vector<int> list753({ 7,5,3 });

//num�Ŏn�܂�n�ȉ���753���v�Z
ll count753(ll num, ll n) {
	if (num > n) return 0;

	//num���g��753���Ȃ�cnt = 1
	ll cnt;
	string num_s = to_string(num);
	if (num_s.find("7") != string::npos && num_s.find("5") != string::npos && num_s.find("3") != string::npos) cnt = 1;
	else cnt = 0;

	//���̌���7,5,3�����Ď��ɓn��
	for (int e : list753) {
		cnt += count753(10 * num + e, n);
	}

	return cnt;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	cout << count753(0, n) << endl;

}*/