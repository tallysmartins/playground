#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
	int n;
	string s1;
	string s2;
	
	cin >> n;

	for(int i=0; i<n; ++i) {
    int pode = 1;

		cin >> s1 >> s2;

    int size1=s1.size();
    int size2=s2.size();

    if(size2 < size1) { cout << "NO" << endl; continue; }

    int init1=0;
    int init2=0;


    for(int i=init1; i < size1; i++) {
      if(s1[init1] != s2[init2]) { pode=0; break; }
      char target = s1[init1];
      int chunck1_size=0;
      int chunck2_size=0;

      while(target == s1[init1]){
        chunck1_size++;
        init1++;
      }      

      while(target == s2[init2]){
        chunck2_size++;
        init2++;
      }      

      if(chunck2_size < chunck1_size) { pode=0; break; }

      i=init1-1;
    }

    if(init2 != size2) {pode=0;}

    if(pode) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
	}

	return 0;
}
