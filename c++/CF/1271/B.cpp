#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << ", "

int main() {
  int N;
	int blocks[210];
	char block;
	int nwhite = 0;
	int nblack = 0;
	vector<int> positions;

  cin >> N;

	for(int i=1; i<=N; i++) {
		cin >> block;
		if(block == 'B') {
			blocks[i] = 0;
			nblack = nblack + 1;
		}else {
			blocks[i] = 1;
			nwhite++;
		}
	}

	if(N%2 == 0) {
		if(nwhite%2 != 0 || nblack%2 != 0) {
			cout << "-1" << endl;
			return 0;
		}
	}

	if(nwhite == 0 || nblack == 0) {
		cout << "0" << endl;
		return 0;
	}

	//HORA DE CONTAR
	int nMoves = 0;	
	int maxMoves = 3*N;
	int count[2];
	count[0] = nblack;
	count[1] = nwhite;

	for(int i=1; i<=N; i++) {
		if(blocks[i+1] != blocks[i] && (i+1) < N) {
			count[blocks[i+1]]--;
			count[blocks[i+2]]--;
			blocks[i+1] = 1 - blocks[i+1];
			blocks[i+2] = 1 - blocks[i+2];
			count[blocks[i+1]]++;
			count[blocks[i+2]]++;
			nMoves++;
			positions.push_back(i+1);
		}
	}

	if(count[0] != N && count[1] != N) {
		for(int i=1; i<N-1;i=i+2) {
			positions.push_back(i);
			//blocks[i] = 1 - blocks[i];
			//blocks[i+1] = 1 - blocks[i+1];
			nMoves++;
		}
	}

	cout << nMoves << endl;
	for(auto it: positions) {
		cout << it << " ";
	}
	//cout << endl;
	//for(int i=1; i<=N; i++){
	//	cout << i << "-" << blocks[i] << " ";
	//}
	//cout << endl;

  return 0;
}
