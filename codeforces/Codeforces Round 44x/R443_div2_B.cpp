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
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    int cur = max(v[0], v[1]), c = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] <= cur) {
            c++;
        } else {
            cur = v[i];
            c = 1;
        }
        if (c == k) {
            cout << cur << endl;
            return;
        }
    }
    sort(v.begin(), v.end());
    cout << v.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
