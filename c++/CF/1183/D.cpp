#include <bits/stdc++.h>

using namespace std;
int main() {
int v[200004];
int s[200004];

  int q, n, price, price_count, res;


  cin >> q;

  while(q--) {
    cin >> n;
    for(int x=0; x<=n; x++) {
      s[x] = 0;
      v[x] = 0;
    }
    vector<int> prices;
    res = 0;

    // for each type of candy, count the amount of candies of that type and
    // add it to a list of candies
    while(n--) {
      cin >> price;

      if(v[price] == 0) {
         prices.push_back(price);
      }
      v[price] = v[price] + 1;
    }

    while(!prices.empty()) {
      price = prices.back(); prices.pop_back();
      price_count = v[price];

      if(s[price_count] == 0) {
        res += price_count;
        s[price_count] = 1;
      }else{
        while(price_count--) {
          if(s[price_count] == 0) {
            res += price_count;
            s[price_count] = 1;
            break;
          }
        }
      }
    }

    cout << res << endl;
  }

	return 0;
}
