#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << endl

int pairwise(int a, int b, int c) {
	return abs(a-b) + abs(a-c) + abs(b-c);
}

int  main() {
	int T, a, b, c, val;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;

		val = pairwise(a+0, b+0, c+0);

		val = min(val, pairwise(a+0, b+0, c+0));
		val = min(val, pairwise(a+0, b+0, c+1));
		val = min(val, pairwise(a+0, b+0, c-1));
		val = min(val, pairwise(a+0, b+1, c+0));
		val = min(val, pairwise(a+0, b+1, c+1));
		val = min(val, pairwise(a+0, b+1, c-1));
		val = min(val, pairwise(a+0, b-1, c+0));
		val = min(val, pairwise(a+0, b-1, c+1));
		val = min(val, pairwise(a+0, b-1, c-1));

		val = min(val, pairwise(a+1, b+0, c+0));
		val = min(val, pairwise(a+1, b+0, c+1));
		val = min(val, pairwise(a+1, b+0, c-1));
		val = min(val, pairwise(a+1, b+1, c+0));
		val = min(val, pairwise(a+1, b+1, c+1));
		val = min(val, pairwise(a+1, b+1, c-1));
		val = min(val, pairwise(a+1, b-1, c+0));
		val = min(val, pairwise(a+1, b-1, c+1));
		val = min(val, pairwise(a+1, b-1, c-1));

		val = min(val, pairwise(a-1, b+0, c+0));
		val = min(val, pairwise(a-1, b+0, c+1));
		val = min(val, pairwise(a-1, b+0, c-1));
		val = min(val, pairwise(a-1, b+1, c+0));
		val = min(val, pairwise(a-1, b+1, c+1));
		val = min(val, pairwise(a-1, b+1, c-1));
		val = min(val, pairwise(a-1, b-1, c+0));
		val = min(val, pairwise(a-1, b-1, c+1));
		val = min(val, pairwise(a-1, b-1, c-1));

		printf("%d\n", val);
	}

	return 0;
}
