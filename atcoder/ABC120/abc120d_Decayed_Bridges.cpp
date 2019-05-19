#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)

class UnionFind {
public:
	//�e�̔ԍ����i�[����B�e�������ꍇ��-(���̏W���̃T�C�Y)
	vector<int> Parent;

	//���Ƃ���Parent�̒l��S��-1�ɂ���
	//��������ƑS�ăo���o���ɂȂ�
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	//A���ǂ̃O���[�v�ɑ����Ă��邩���ׂ�
	int root(int A) {
		//cout << "root in" << endl;
		//cout << "Parent[A]:" << Parent[A] << endl;
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//�����̂���O���[�v�̒��_���𒲂ׂ�
	int size(int A) {
		return -Parent[root(A)];//�e���Ƃ��Ă�����
	}

	//A��B�������t����
	bool connect(int A, int B) {
		//A��B�𒼐ڂȂ��̂ł͂Ȃ��Aroot(A)��root(B)����������
		A = root(A);
		B = root(B);
		if (A == B) {
			//���łɂ������Ă邩�炭���t���Ȃ�
			return false;
		}

		//�傫����(A)�ɏ������ق�(B)�������t������
		//�召���t��������Ђ�����Ԃ����Ⴄ�B
		if (size(A) < size(B)) swap(A, B);

		//A�̃T�C�Y���X�V����
		Parent[A] += Parent[B];
		//B�̐e��A�ɕύX����
		Parent[B] = A;

		return true;
	}
};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> A(M), B(M);

	FOR(i,0,M) {
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	cout << "Input" << endl;
	FOR(i, 0, M) cout << A[i] << " " << B[i] << endl;

	vector<long long> ans(M);
	ans[M - 1] = (long long)N * (N - 1) / 2;
	
	UnionFind uni(N);

	REF(i,M-1,0) {
		cout << "A,B: " << A[i] << " " << B[i] << endl;

		cout << "Parent" << endl;
		FOR(i,0,N) cout << uni.Parent[i] << endl;
		cout << "root(A)" << uni.root(A[i]) << endl;
		cout << "root(B)" << uni.root(B[i]) << endl;
		cout << "size(A)" << uni.size(A[i]) << endl;
		cout << "size(B)" << uni.size(B[i]) << endl;

		//�Ȃ����ĂȂ������̂��Ȃ������Ƃ�
		if (uni.root(A[i]) != uni.root(B[i])) {
			ans[i - 1] = ans[i]
				- (long long)uni.size(A[i]) * uni.size(B[i]);
			uni.connect(A[i], B[i]);

		}
		else ans[i - 1] = ans[i];
	}

	FOR(i, 0, M) {
		cout << ans[i] << endl;
	}

}

