#include <iostream>
#include <vector>
using namespace std;

const int N = 1000005;

vector<int> pri;
bool not_prime[N];

void pre(int n) {
  for (int i = 2; i <= n; i++) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int &pri_j : pri) {
      if (i * pri_j > n)
        break;
      not_prime[i * pri_j] = 1;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}

signed main() {
  int n;
  cin >> n;
  pre(n);
  for (int &pri_i : pri) {
    cout << pri_i << ' ';
  }
  cout << endl;

  return 0;
}
