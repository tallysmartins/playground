#include <bits/stdc++.h>

using namespace std;
int main() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int lenght = 2*d;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());

	int resp = 0;
	int center = v[1];

	if (center - v[0] <  d) {
		int tmp = center - v[0];
		resp += d - tmp;
	}

	if (v[2] - center <  d) {
		int tmp = v[2] - center;
		resp += d - tmp;
	}

	cout << resp << endl;

	return 0;
}

