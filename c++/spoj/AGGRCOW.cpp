// URL: https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>

using namespace std;

int t, C, tmpC, N, pos, best, resolve;
vector<int> v;

int main() {


	cin >> t;

	while(t--) {
		cin >> N >> C;
		v.clear();
		tmpC = C;

		while(N--) {
			cin >> pos;
			v.push_back(pos);
		}

		//sort array to do the binary search
		sort(v.begin(), v.end());

		// best solution is now 0, anything better than this is my answer
		int best = 0;

		// guess a solution, lets say the range of the field

		int low=0;
		int high= v.back() - v.front() + 1;
		int mid;
		int j=20;

		// binary search
		while(high - low > 1) {

			//find the S in the middle of start and finish positions
			
			mid = (high + low) / 2;
	
			C--; // place a caw in the first stick
			int last=v.front();

			resolve = 0;
			// try to place all caws for the given S
			for(auto i: v) {
				int d  = i - last;
				if(d >= mid)  {
					C--;
					last = i;

					if(C <= 0) {
						 resolve = 1;
						 break;
					}

				}
			}

			C = tmpC;
			if(resolve) {
				best = max(best, mid);
				low = mid;
			}else {
				high = mid;
			}

		}

		cout << best << endl;
	}
	return 0;
}
