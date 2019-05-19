#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
static const long long INF = 9999999999999999;

long long distance(vector<long long> a, vector<long long> b, long long x, int flag_LR1, int flag_LR2) {
	//�񕪒T��(��ɖK��)
	auto it1 = lower_bound(a.begin(), a.end(), x);
	int index1 = it1 - a.begin() - 1 + flag_LR1; //flag_LR1��0�F�����A1�F�E��
	//cout << "index1: " << index1 << endl;
	//cout << "a[index1]: " << a[index1] << endl;

	//�񕪒T��(��ɖK��)
	auto it2 = lower_bound(b.begin(), b.end(), a[index1]);
	int index2 = it2 - b.begin() - 1 + flag_LR2; //flag_LR2��0�F�����A1�F�E��
	if (index2 < 0) index2 = 0;
	//cout << "index2: " << index2 << endl;
	//cout << "b[index2]: " << b[index2] << endl;

	return abs(x - a[index1]) + abs(b[index2] - a[index1]);
}

long long distance_simple(long long ax, long long bx, long long x) {
	return abs(x -  ax) + abs(bx - ax);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, q;
	
	cin >> a >> b >> q;
	
	long long input;
	vector<long long> shrines, temples;
	
	shrines.push_back(-INF);
	FOR(i, 0, a) {
		cin >> input;
		shrines.push_back(input);
	}
	shrines.push_back(INF);

	temples.push_back(-INF);
	FOR(i, 0, b) {
		cin >> input;
		temples.push_back(input);
	}
	temples.push_back(INF);

	//cout << a << ", " << b << ", " << q << endl;
	//cout << "shrines" << endl;
	//FOR(i, 0, a+2) cout << shrines[i] << endl;
	//cout << "temples" << endl;
	//FOR(i, 0, b+2) cout << temples[i] << endl;

	long long min1 = INF;
	long long x;

	FOR(i, 0, q) {
		min1 = INF;
		cin >> x;

		//�񕪒T��
		auto it1 = lower_bound(shrines.begin(), shrines.end(), x);
		int index_s = it1 - shrines.begin() -1; //�����C���f�b�N�X
		auto it2 = lower_bound(temples.begin(), temples.end(), x);
		int index_t = it2 - temples.begin() - 1; //�����C���f�b�N�X

		//����1�F�_�ВT���͍����E��
		FOR(s_lr, 0, 2) {
			//����2�F���T���͍����E��
			FOR(t_lr, 0, 2) {
				//�_�Ђ���
				long long d_s = distance_simple(shrines[index_s + s_lr], temples[index_t + t_lr], x);
				
				//������
				long long d_t = distance_simple(temples[index_t + t_lr], shrines[index_s + s_lr], x);

				min1 = min({ min1, d_s, d_t });
				//cout << "d_s: " << d_s << endl;
				//cout << "d_t: " << d_t << endl;
				//cout << "min: " << min1 << endl;
			}
		}
		cout << min1 << endl;*/

		/*LTE�ɂȂ�
		//����1�F�K��1�͐_�Ђ�����
		FOR(i1_st, 0, 2) {
			vector<long long> a, b;
			if (i1_st == 0) { a = shrines; b = temples; }
			else { a = temples; b = shrines; }

			//����2�F�K��1�͍����E��
			FOR(flag_LR1, 0, 2) {

				//����3�F�K��2�͍����E��
				FOR(flag_LR2, 0, 2) {
					//cout << "---" << i1_st << ", " << flag_LR1 << ", " << flag_LR2 << "---" << endl;
					long long d = distance(a, b, x, flag_LR1, flag_LR2);
					min1 = min(min1, d);
					//cout << "d: " << d << endl;
					//cout << "min: " << min1 << endl;
				}
			}
		}*/
	
		//cout << "min: " << min1 << endl;
		//cout << min1 << endl;
		
	}

}