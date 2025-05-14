#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


bool is_prime(int n) {
    if (n < 2)return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi p;
    for (int i = 2; i <= n; i++)if (is_prime(i))p.pb(i);
    for (int x: p) {
        for (int i = 1; i < p.size(); i++) {
            if (p[i] + p[i - 1] + 1 == x)k--;
        }
    }
    cout << (k <= 0 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
