#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

map<ll, int> d;

int go(int x, int a1, int a2) {
    if(x == 0) return a1 == 0 && a2 == 0;

    ll t = (ll) x * 100 + a2 * 10 + a1;
    if (d.find(t) != d.end()) return d[t];
    int &r = d[t];

    int k = x % 10;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j + a1) % 10 == k) {
                r += go(x / 10, a2, (i + j + a1) / 10);
            }
        }
    }
    return r;
}

void solve() {
    int n;
    cin >> n;

    d.clear();
    cout << go(n, 0, 0) - 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
