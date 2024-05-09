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
    int n;
    cin >> n;
    map<pi, int> c;
    vector<pair<int, pi>> a(n), b(n), v;
    for (int i = 0; i < n; i++) {
        cin >> a[i].F >> b[i].F;
        a[i].S = mp(0, i);
        b[i].S = mp(1, i);
        v.pb(a[i]);
        v.pb(b[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        c[v[i].S] = 1;
    }

    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < n; k++) {
            if (c[mp(i, k)] == 1 || k < n / 2) {
                cout << 1;
            } else cout << 0;
        }
        cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
