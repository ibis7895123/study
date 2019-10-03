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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> sushi(n); //d,t���i�[����pair
	
	FOR(i, 0, n) {
		int t, d;
		cin >> t >> d;
		t--;
		sushi[i] = { d, t }; //�\�[�g���₷���̂��߂�t,d����ւ�
	}

	//���������ő傫�����Ƀ\�[�g
	sort(sushi.begin(), sushi.end(), greater<pair<int, int>>());

	cout << "sushi:" << endl;
	FOR(i, 0, n) cout << sushi[i].first << ", " << sushi[i].second << endl;
	cout << endl;

	
	ll score = 0; //�����x
	vector<int> neta(n, 0); //�I�񂾎��i���l�^���ƂɏW�v
	int kind = 0; //�I�񂾎��i�̃l�^��

	//������������k�Ƃ�(�����l)
	FOR(i, 0, k) {
		score += sushi[i].first;
		neta[ sushi[i].second ]++;

		if (neta[sushi[i].second] == 1) kind++; //�V�����l�^�Ȃ�l�^��ރv���X
	}
	score += kind * kind;

	cout << "score:" << score << endl;
	cout << "neta:" << endl;
	FOR(i, 0, n) cout << neta[i] << endl;
	cout << "kind:" << kind << endl;
	cout << endl;

	int in = 0;
	ll max1 = score;
	REF(out, k - 1, -1) {
		//�_�u���̒�������������ŏ��̂��̑I��
		if (neta[ sushi[out].second ] > 1) {
			in = -1;

			//�I��łȂ����̂̒�����
			//�@�l�^�������邩�A���������ő�̂��̂�I��
			FOR(i, k, n) if (neta[ sushi[i].second ] == 0) { in = i; break; }
			//�Ȃ����break
			if (in == -1) break;


			//�H�ׂ�̂���߂���i�̕���score�Aneta�������
			score -= sushi[out].first;
			neta[ sushi[out].second ]--;
			cout << "out:" << sushi[out].first << "," << sushi[out].second << endl;


			//�ǉ�������i�̕���score�Aneta�Akind(�l�^������)�ɑ���
			score += sushi[in].first;
			neta[sushi[in].second]++;
			kind++;
			cout << "in:" << sushi[in].first << "," << sushi[in].second << endl;
			cout << "kind:" << kind << endl;

			//��ރ{�[�i�X�ǉ�
			score += kind * kind - (kind - 1)*(kind - 1);
			cout << "score:" << score << endl;

			cout << "neta:" << endl;
			FOR(i, 0, n) cout << neta[i] << endl;
			cout << endl;
		}
		max1 = max(max1, score);
	}

	cout << max1 << endl;
}