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
  int a, b, m;
  lli totalSum, izq, der;

  totalSum = gaussSum(numOfHouses);

  a = 1;
  b = numOfHouses;
  while (a < b) {
    m = (a + b) / 2;
    izq = gaussSum(m - 1);
    der = totalSum - m - izq;

    cout << izq << " - " << der << endl;

    if (izq < der) {
      a = m + 1;
    } else {
      b = m;
    }
  }

  m = (a + b) / 2;
  izq = gaussSum(m - 1);
  der = totalSum - m - izq;

  cout << izq << " - " << der << endl;

  if (izq == der) {
    return m;
  }

  return -1;
}
