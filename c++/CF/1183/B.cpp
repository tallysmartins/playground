#include <bits/stdc++.h>

using namespace std;
int main() {

  int q, n, k, gre, low, price, B;

  cin >> q;

  while(q--) {
    low = 0xFFFFFFF;
    gre = 0;
    cin >> n >> k;

    // find the min and max numbers in the input prices
    while(n--) {
      cin >> price;
      low = min(low, price);
      gre = max(gre, price);
    }

    // B will be at most the minimum + k, so you just need to test if it works
    // for the max and the minimum
    B = low + k; 
    if(abs(low - B) <= k and abs(gre - B) <= k) {
      cout << B << endl;
    }else {
      cout << -1 << endl;
    }

  }
	return 0;
}
