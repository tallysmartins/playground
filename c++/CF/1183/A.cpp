#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, i, res;
	string n_str;
	cin >> n;

	while(true) {
		
		
		res = 0;
		//convert n to string
		n_str = to_string(n);

		// iterate over each number and sum
		for(auto it: n_str) {
			res += (int)it;
		}

		// if res % 4 == 0 return the number, else increase n by one and try again
		if(!(res%4)) {
			cout << n << endl;
			break;
		}else {
			n++;
		}
	}

	return 0;
}
