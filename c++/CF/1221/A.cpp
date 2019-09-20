#include <bits/stdc++.h>

using namespace std;

int q, n, s;
bool desc_ordering (int i,int j) { return (i>j); }
int main() {
	cin >> q;
	while(q--) {

		cin >> n;
    vector<int>v;
    
    //leia todos os n números inteiros maiores que 2048
    while(n--) {
      cin >> s;
      if(s <= 2048) {
        v.push_back(s);
      }
    }

    //Ordene em ordem decrescente
    sort(v.begin(), v.end(), desc_ordering);

    // Se a soma for 2048, temos uma resposta
    int sum=0;
    for(auto it: v) {
      sum += it;
      if(sum == 2048) {
        cout << "YES" << endl;
        break;
      }
    }

    if(sum != 2048) {
      cout << "NO" << endl;
    }
	}

	return 0;
}
