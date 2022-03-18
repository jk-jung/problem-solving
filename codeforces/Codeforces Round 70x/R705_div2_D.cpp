#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

const int MAX = 200000;
map<int, int> fac[MAX + 1];

void fast_factorization_for_many_numbers() {
    vector<int> prime(MAX + 1);
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        int x = i;
        while (prime[x]) fac[i][prime[x]]++, x /= prime[x];
        if (x > 1) fac[i][x]++;
    }
}

vi st[MAX + 1];
map<int, int> pos[MAX + 1];
int n, q;
ll r = 1;
const int mod = 1000000007;

void mul(int i, int x) {
    for (auto[a, b]: fac[x]) {
        int &c = pos[i][a];
        int tot = c + b;
        if (st[a].size() < tot)st[a].resize(tot);

        while (c < tot) {
            if (++st[a][c++] == n) {
                r *= a;
                r %= mod;
            }
        }
    }
}

void solve() {
    cin >> n >> q;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mul(i, x);
    }

    while (q--) {
        int i, x;
        cin >>i>> x;
        mul(i-1, x);
        cout << r << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fast_factorization_for_many_numbers();
    solve();
}
