#include <bits/stdc++.h>

using namespace std;
#define DBG(x) cout << #x << " = " << x << endl

int  main() {
  int T, a, b, i;
  string word;
  string pass;
  int alphabet[260];
  int tmp_alphabet[260];
  int size_w, size_p;
	int it, it2, match;
  cin >> T;

  while(T--) {
    memset(alphabet, 0, sizeof(alphabet));
    cin >> word >> pass;
    
    size_w = word.length();
		size_p = pass.length();
    for(auto it: word) {
      alphabet[int(it)] = alphabet[int(it)] + 1;
    }

		if(size_p < size_w) {
			cout << "NO" << endl;
		}else {
			for(it=0, it2=size_w-1; it2!=size_p; it++,it2++) {
				match = 1;

				memset(tmp_alphabet, 0, sizeof(tmp_alphabet));
				for(int i=it; i<=it2; i++) {
					char c = pass[i];
					tmp_alphabet[int(c)] = tmp_alphabet[int(c)] + 1;
				}

				for(int i=it; i<=it2; i++) {
					char c = pass[i];
					if(alphabet[int(c)] != tmp_alphabet[int(c)]) {
						match = 0;
						break;
					}
				}
				if(match) break;
			}

			if(match) {
				cout << "YES" << endl;
			}else{ 
				cout << "NO" << endl;
			}
		}
  }
  
	return 0;
}
