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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    int t;
    cin >> t;
    for (int i = 0, x; i < t; i++)cin >> x, a[x] = 1;
    cin >> t;
    for (int i = 0, x; i < t; i++)cin >> x, b[x] = 1;
    for (int i = 0; i < n * m * 2; i++) {
        if(a[i % n] || b[i % m]) {
            a[i % n] = 1;
            b[i % m] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if(a[i] == 0) {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if(b[i] == 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
