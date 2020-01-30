#include <bits/stdc++.h>

using namespace std;
#define Z 50005 // Com 10^5 usaremos no max 10^4 displays no pior caso onde n=10^5
int main() {

  int T, n;

  int d[Z];
  int max[8] = {0, 0, 1, 7, 4, 5, 9, 9};

  cin >> T;
  while(T--) {

    cin >> n;
    int i;
    i = n/2;
    i = min(i, Z); // number of displays to be filled with 1

    //Pega o mod de n
    //coloca os 1's até onde der min(i, 10);
    //salva até onde deu

    for(int k=0; k<i; k++) {
      int index = Z-1-k;//index in reverse order, from right to left
      d[index] = 1;
      n -= 2; //subtract two segments used to display the digit 1
    }

    //Volta de trás pra frente de onde deu até o começo
    //colocando no lugar o max[min(7, nx)] onde nx é o numero de palitos restantes
    // mais os 2 que já tem
    for(int k=Z-i; k<Z; k++) {
      int used = min(5, n);
      d[k] = max[used+2];
      n -= used;
      printf("%d", d[k]);
    }
    cout << endl;

  }
  return 0;
}
