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

int n_piece, n_x;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n_piece >> n_x;
	
	vector<int> xs(n_x);
	FOR(i, 0, n_x) {
		cin >> xs[i];
	}
	sort(xs.begin(), xs.end());
	
	cout << "xs:" << endl;
	FOR(i, 0, n_x) cout << xs[i] << endl;
	cout << endl;

	//�L���ȋ�̐���min(��̐�, ���W�̐�)
	//�d��������͍l���Ȃ�
	int size_p = min(n_piece, n_x);
	vector<int> pieces(size_p);
	pieces[0] = 0; //�ŏ��̋�͍��[�ɒu��

	//���u���ʒu�v�Z
	//���W�ԋ������傫���Ƃ�����щz�����Ƃ���ɋ��u��
	FOR(ip, 1, size_p) {
		
		int dxmax = 0;
		FOR(ix, 0, n_x - 1) {
			//�I���ς݂̃C���f�b�N�X�̓X�L�b�v
			auto iter = find(pieces.begin(), pieces.end(), ix+1);
			if (iter != pieces.end()) continue;

			//cout << ip << ", " << ix << endl;
			//cout << abs(xs[ix + 1] - xs[ix]) << endl;
			//���W�ԋ����̍ő�l�v�Z
			//�ő�l�̉E���C���f�b�N�X��pieces�ɋL��
			if (dxmax < abs(xs[ix + 1] - xs[ix])) {
				cout << abs(xs[ix + 1] - xs[ix]) << endl;
				dxmax = abs(xs[ix + 1] - xs[ix]);
				pieces[ip] = ix + 1;
			}

		}
	}
	//�����Ƀ_�~�[�̋������(�ړ��ʌv�Z�p)
	pieces.push_back(n_x);

	cout << "pieces:" << endl;
	FOR(i, 0, size_p) cout << pieces[i] << endl;
	cout << endl;

	//�ړ��ʌv�Z
	//�ړ��� = ���̋��1�O�̍��W - ���݂̋�
	int sum = 0;
	FOR(i, 0, size_p) {
		int distance = xs[ pieces[i + 1] - 1 ] - xs[ pieces[i] ];
		cout << distance << endl;
		sum += distance;
	}
	cout << "sum:" << endl;
	cout << sum << endl;
}