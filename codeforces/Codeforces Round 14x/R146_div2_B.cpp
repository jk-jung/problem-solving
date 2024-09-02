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


void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    ll rr = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                int x = i;
                int y = j;
                int z = k;
                int r = 1;
                for (int p = 2; p <= 10; p++) {
                    int t = 0;
                    while (x % p == 0)x /= p, t++;
                    while (y % p == 0)y /= p, t++;
                    while (z % p == 0)z /= p, t++;
                    r *= (t + 1);
                }
                map<int, int> cc;
                cc[x]++;
                cc[y]++;
                cc[z]++;
                for (auto [kk, vv]: cc)if (kk > 1)r *= (vv + 1);
                rr = (r + rr) % (1 << 30);
            }
        }
    }
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
