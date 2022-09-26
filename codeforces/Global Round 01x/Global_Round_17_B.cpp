#include <string.h>
#include <stdio.h>
#include <math.h>
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

bool check(vi &v, int x) {
    vi t;
    for (int i = 0; i < v.size(); i++)if (v[i] != x)t.pb(v[i]);
    int n = t.size();
    for (int s = 0, e = n - 1; s < e; s++, e--) {
        if(t[s] != t[e]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    for (int s = 0, e = n - 1; s < e; s++, e--) {
        if (v[s] != v[e]) {
            if (check(v, v[s]) || check(v, v[e])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }
    }
    cout << "YES\n";
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
