#include <iostream>
typedef long long int lli;
using namespace std;

lli gaussSum(lli n);
lli calculate(int numOfHouses);

int  main() {
  int numOfHouses;

  cout << "Introducir numero de casas: ";
  cin >> numOfHouses;
  cout << calculate(numOfHouses) << endl;
  return 0;
}

lli gaussSum(lli n) {
  return (n * (n + 1)) / 2;
}

lli calculate(int numOfHouses) {
  int i;
  lli totalSum, izq, der;

  totalSum = gaussSum(numOfHouses);

  for (i = 1; i <= numOfHouses; ++i) {
    izq = gaussSum(i - 1);
    der = totalSum - i - izq;

    cout << izq << " - " << der << endl;
    
    if (izq == der) {
      return i;
    }
  }

  return -1;
}
