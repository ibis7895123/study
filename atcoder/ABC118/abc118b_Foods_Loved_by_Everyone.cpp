#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n_person, n_food;
	cin >> n_person >> n_food;

	vector<int> foods(n_food,0);
	
	FOR(i, 0, n_person) {
		int num_foods;
		cin >> num_foods;

		FOR(j, 0, num_foods) {
			int i_food;
			cin >> i_food;
			foods[i_food - 1]++;
		}
	}

	cout << "foods:" << endl;
	FOR(i, 0, n_food) cout << foods[i] << endl;

	int count = 0;
	FOR(i, 0, n_food) {
		if (foods[i] == n_person) count++;
	}

	cout << "count:" << endl;
	cout << count;

}