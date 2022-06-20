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

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b, t(m);
    for (int &x: a)cin >> x;
    for (int &x: t)cin >> x;

    b = a;
    sort(b.begin(), b.end());
    sort(t.begin(), t.end());

    int s = t[0];
    t.pb(1 << 30);
    for (int i = 1; i < t.size(); i++) {
        if (t[i] != t[i - 1] + 1) {
            sort(a.begin() + s - 1, a.begin() + t[i - 1] + 1);
            s = t[i];
        }
    }
    cout << (a == b ? "YES\n" : "NO\n");
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
