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
    vi v(n);
    vector<vi> r(n);
    for (int &x: v)cin >> x;
    for (int i = 1; i < m; i++) {
        int a = *min_element(v.begin(), v.end());
        int b = *max_element(v.begin(), v.end());
        if (b - a <= 1)break;
        for (int j = 0; j < n; j++) {
            if (v[j] > a) {
                v[j]--;
                r[j].pb(i);
            }
        }
    }
    int a = *min_element(v.begin(), v.end());
    int b = *max_element(v.begin(), v.end());
    if (a + 1 < b)cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            vi &t = r[i];
            for (int x: t)cout << x << " ";
            while (v[i]--) cout << m << " ";
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
