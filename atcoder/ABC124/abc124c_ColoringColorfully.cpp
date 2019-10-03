#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int l = s.length();
	
	string s0;
	FOR(i, 0, l) {
		if (i % 2 == 0) s0 += "0";
		else s0 += "1";
	}
	cout << "s0: " << s0 << endl;

	string s1;
	FOR(i, 0, l) {
		if (i % 2 == 0) s1 += "1";
		else s1 += "0";
	}
	cout << "s1: " << s1 << endl;

	int count0 = 0;
	int count1 = 0;
	FOR(i, 0, l) {
		if (s[i] != s0[i]) count0++;
		if (s[i] != s1[i]) count1++;
	}

	cout << count0 << " vs " << count1 << endl;
	cout << min(count0, count1) << endl;

}