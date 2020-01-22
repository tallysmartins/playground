#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << endl

int  main() {
  int i,j, n, T, count;

  //Number of test cases
  cin >> T;

  while(T--) {
    vector<int> v;
    int i = 0;
    cin >> n;
    int raiz = sqrt(n);

    for(j=2; j<=raiz; j++) {
      if(n%j == 0) {
        v.push_back(j);
        n = n/j;
        i++;
      }
      if(i==2) { v.push_back(n);  break;}

    }

    if(i != 2 || v[2] <= v[1]) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
			cout << v[0] << " " << v[1] << " " << v[2] << endl;
		}

  }

  return 0;
}
