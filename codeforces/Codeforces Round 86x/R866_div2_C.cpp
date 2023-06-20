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


int f(vi &v) {
    map<int, int> ck;
    for (int x: v)ck[x]++;
    int idx = 0;
    for (auto [x, _]: ck) {
        if (idx != x)break;
        idx++;
    }
    return idx;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);

    for (int &x: v)cin >> x;
    int m = f(v) + 1;
    int s = 1 << 30, e = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == m) {
            s = min(s, i);
            e = i;
        }
    }
    vi t = v;
    for (int i = s; i <= e; i++)t[i] = m - 1;
    if (f(t) == m) {
        cout << "YES\n";
        return;
    }
    if(s < (1<<30)) {
        cout << "NO\n";
        return;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        if(v[i] != i) {
            cout <<"YES\n";
            return;
        }
    }
    cout << "NO\n";
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
