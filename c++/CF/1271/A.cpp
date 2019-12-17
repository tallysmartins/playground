#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << ", "

int main() {
  int a, b, c, d, e, f;
  int sut1 = 0;
  int sut2 = 0;

  cin >> a >> b >> c >> d >> e >> f;
  if(e > f) { //suit 1 cost more, take it first and the remaining of suit 2
    int remaining_d = d - min(a,d);
    sut1 = e*min(a,d);
    sut2 = f*min(b, min(c,remaining_d));
  }else { 
    int remaining_d = d - min(b,min(c,d));
    sut1 = e*min(a, remaining_d);
    sut2 = f*min(b, min(c,d));
  }

  cout << sut1+sut2 << endl;

  return 0;
}
