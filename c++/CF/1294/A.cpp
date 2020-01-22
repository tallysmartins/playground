#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << endl

int  main() {
  int a,b,c, n, T, highest;

  //Number of test cases
  cin >> T;

  while(T--) {
    vector<int> myvec;

    //Read input
    cin >> a >> b >> c >> n;
    myvec.push_back(a);
    myvec.push_back(b);
    myvec.push_back(c);

    //Sort values to calculate relatively to the max
    sort(myvec.begin(), myvec.end());
    highest = myvec[2];
    int missing = (highest - myvec[1]) + (highest - myvec[0]);

    if(missing > n) {
      cout << "NO" << endl; 
    }else {
      int remaining = n - missing;
      if(remaining%3 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
