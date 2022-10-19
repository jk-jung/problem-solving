#include <cstring>
#include <cstdio>
#include <cmath>
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(2), cnt(2);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x % 2] += x;
        cnt[x % 2]++;
    }

    while (q--) {
        int op, x;
        cin >> op >> x;
        v[op] += cnt[op] * x;
        if (x % 2) {
            v[op ^ 1] += v[op];
            cnt[op ^ 1] += cnt[op];
            v[op] = cnt[op] = 0;
        }
        cout << v[0] + v[1] << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
