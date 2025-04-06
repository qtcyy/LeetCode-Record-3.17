#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 100005; // Adjust N based on maximum expected input size

vector<ll> fact(N);
vector<ll> infact(N);

// Function for modular exponentiation (a^k mod p)
ll qmi(ll a, ll k, ll p) {
  ll res = 1;
  while (k) {
    if (k & 1)
      res = res * a % p;
    a = a * a % p;
    k >>= 1;
  }
  return res;
}

// Precompute factorials and inverse factorials
void init() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  // Calculate inverse of fact[N-1] using Fermat's Little Theorem
  infact[N - 1] = qmi(fact[N - 1], mod - 2, mod);
  // Calculate inverse factorials iteratively
  for (int i = N - 2; i >= 1; i--) {
    infact[i] = infact[i + 1] * (i + 1) % mod;
  }
}

// Function to calculate combinations C(a, b) = a! / (b! * (a-b)!)
ll C(int a, int b) {
  if (b < 0 || a < b) {
    return 0; // Invalid input
  }
  return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int main() {
  // Initialize precomputed values
  init();

  // Example usage: Calculate C(10, 3)
  int a = 10, b = 3;
  cout << "C(" << a << ", " << b << ") mod " << mod << " = " << C(a, b) << endl;

  // Example usage: Calculate C(5, 5)
  a = 5, b = 5;
  cout << "C(" << a << ", " << b << ") mod " << mod << " = " << C(a, b) << endl;

  // Example usage: Calculate C(100, 2)
  a = 100, b = 2;
  cout << "C(" << a << ", " << b << ") mod " << mod << " = " << C(a, b) << endl;

  return 0;
}
