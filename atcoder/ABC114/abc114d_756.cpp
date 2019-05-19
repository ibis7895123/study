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

int n;
vector<int> e(110, 0); //Še‘fˆö”‚Ìw”‚ğŠi”[ prime^e

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	

	//n!‚ğ‘fˆö”•ª‰ğ
	//1~n‚Ü‚Å‚ğ‘fˆö”•ª‰ğ‚µ‚Ä‡Z
	FOR(num, 2, n+1) {
		
		int tmp = num; //tmp‚É2~n‚ğŠi”[
		
		FOR(prime, 2, num + 1) {
			//num = prime1^e1 * prime2^e2 * prime3^e3...
			while (tmp % prime == 0) {
				e[prime] += 1;
				tmp /= prime;
			}
		}

	}

	cout << "e:" << endl;
	FOR(i, 0, n+1) cout << e[i] << endl;
	cout << endl;

	//–ñ”75ŒÂ‚ÌAl‚¦‚ç‚ê‚énum‚Í
	//a4b4c2Aa14b4Aa24b2Aa74‚Ì‚İ
	int cnt = 0;

	//a74‚Ì
	FOR(i, 2, n + 1) if (e[i] >= 74) cnt++;

	//a24b2‚Ì
	FOR(i, 2, n + 1) FOR(j, 2, n + 1) {
		if (i != j && e[i] >= 24 && e[j] >= 2) cnt++;
	}
	
	//a14b4‚Ì
	FOR(i, 2, n + 1) FOR(j, 2, n + 1) {
		if (i != j && e[i] >= 14 && e[j] >= 4) cnt++;
	}
	
	//a4b4c2‚Ì
	//b‚Ía‚Æ‚©‚Ô‚ç‚È‚¢‚æ‚¤‚É’ˆÓ
	FOR(i, 2, n + 1) FOR(j, i+1, n + 1) FOR(k, 0, n+1) {
		if (i != j && j != k && k != i && e[i] >= 4 && e[j] >= 4 && e[k] >= 2) cnt++;
	}
	
	cout << cnt << endl;

}