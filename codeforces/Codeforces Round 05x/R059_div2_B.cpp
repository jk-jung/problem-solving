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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    int r = 0;
    while (true) {
        int diff = 0;
        vi t;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i] < k) {
                diff = 1;
                if (i == 0 || v[i] != v[i - 1]) {
                    t.pb(v[i] + 1);
                } else {
                    t.pb(v[i]);
                }
            } else {
                t.pb(v[i]);
            }
        }
        v = t;
        if (!diff)break;
        r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
