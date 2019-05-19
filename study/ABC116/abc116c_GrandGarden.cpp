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
const ll INF = 1LL << 40;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

/*int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> h(n);
	FOR(i, 0, n) cin >> h[i];

	int section = 0;
	while (*max_element(h.begin(), h.end()) != 0) {
		
		//‹æŠÔ•ªŠ„
		int i = 0;
		while (i < n) {
			
			//h[i] == 0‚È‚çŽŸ‚Ö
			if (h[i] == 0) i++;
			else {
				cout << "i:" << i;
				int i_s = i;
				
				//‹æŠÔ‚ÌI‚í‚è‚Ü‚Å
				int min1 = 1000;
				while (i < n && h[i] > 0) { min1 = min(min1, h[i]); i++; }
				cout << " - " << i-1;
				int i_e = i - 1;
				
				//‹æŠÔÅ¬’l‚ðh‚©‚çˆø‚­
				FOR(i, i_s, i_e + 1) h[i] -= min1;

				//‹æŠÔ‚É’Ç‰Á
				section += min1;
				cout << " hmin:" << min1 << endl;
			}

		}
		cout << "h:" << endl;
		FOR(i, 0, n) cout << h[i] << endl;
		cout << endl;
	}

	cout << section << endl;

}*/