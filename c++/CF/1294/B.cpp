#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << endl

bool my_sort(pair<int, int> a, pair<int,int> b) {
  if(a.second < b.second) {
    return true;
  }else if(a.second == b.second) {
    return a.first < b.first;
  }else {
		return false;
	}
}

int  main() {
  int i,j, n, T, count;

  //Number of test cases
  cin >> T;

  while(T--) {
    //current position of the robot
    int x, y;
    x = 0;
    y = 0; 

    //Coordinates of all packages
    vector<pair<int,int> > v;

    //Read input
    cin >> n;
    count = n;
    while(n--) {
      cin >> i >> j;
      v.push_back(make_pair(i,j));
    }

    //Sort packages in lexicographical order in X axes, going first to Right them Up
    sort(v.begin(), v.end(), my_sort);

    //Lets walk through the packages and see if we can catch em all
    // Use Manhattan distance
    int distance_x, distance_y;
		string all_path;
    for(auto it: v) {
      //cout << it.first << " " << it.second << endl;
      //I can get the package if its to the Right
      if(it.first >= x) {
        distance_x = it.first - x;
        distance_y = it.second - y;
        count--;
        x = it.first;
        y = it.second;
				all_path.append(distance_x, 'R');
				all_path.append(distance_y, 'U');
      } //ignore package, there's no going back
    }

    if(count != 0 ) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
			cout << all_path << endl;
		}

  }

  return 0;
}
