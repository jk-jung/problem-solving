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
    int n, q, a = 0, b = 0;
    cin >> n >> q;
    vi v(n);
    for (int &x: v) {
        cin >> x;
        if (x < 0)a++;
        else b++;
    }
    while (q--) {
        int s, e;
        cin >> s >> e;
        int m = e - s + 1;
        if (m % 2 == 0 && m / 2 <= min(a, b)) {
            cout << 1 << endl;
        } else cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
