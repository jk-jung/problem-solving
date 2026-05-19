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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<char> v;
    for (char x: a)v.pb(x);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll r = 0;
    int m = v.size();
    k = min(k, m);
    for (int t = 0; t < (1 << m); t++) {
        if (__builtin_popcount(t) != k)continue;
        set<char> ck;
        for (int i = 0; i < m; i++)if (t >> i & 1)ck.insert(v[i]);
        ll tmp = 0;
        for (int i = 0, c = 0; i < n; i++) {
            if (a[i] == b[i] || ck.count(a[i]))c++;
            else c = 0;
            tmp += c;
        }
        r = max(r, tmp);
    }
    cout << r << endl;
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
