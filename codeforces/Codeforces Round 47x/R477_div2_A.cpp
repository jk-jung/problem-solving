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
    int n, s;
    cin >> n >> s;
    vi v(n);
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        v[i] = x * 60 + y;
    }
    for (int i = 0;; i++) {
        int m = 1 << 30;
        for (int x: v) m = min(m, ab(x - i));
        if (m > s) {
            cout << i / 60 << " " << i % 60 << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
