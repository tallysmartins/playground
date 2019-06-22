#include <bits/stdc++.h>

using namespace std;
int main() {

	int n;
	cin >> n;
  int v[110];
  v[1] = 1;
  for(int i=2; i<=n; i++) {
    v[i] = v[i-1] + 4*(i-1);
  }
  cout << v[n] << endl;

	return 0;
}
