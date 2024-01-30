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
map<int, int> cnt;

void f(int x) {
    if (--cnt[x] == 0)cnt.erase(x);
}

void solve() {
    int n;
    cin >> n;
    vi v(n * n);

    for (int &x: v)cin >> x, cnt[x]++;
    sort(v.rbegin(), v.rend());

    if (n == 1) {
        cout << v[0] << endl;
        return;
    }
    vi r;
    r.pb(v[0]);
    r.pb(v[1]);
    f(v[0]);
    f(v[1]);
    f(gcd(v[0], v[1]));
    f(gcd(v[0], v[1]));

    while (r.size() < n) {
        int x = cnt.rbegin()->F;
        f(x);
        for (int y: r) f(gcd(x, y)), f(gcd(x, y));
        r.pb(x);
    }
    for(int x: r)cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
