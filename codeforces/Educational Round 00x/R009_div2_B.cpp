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
    int n;
    string s;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    cin >> s;

    ll ss = 0;
    ll r = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')ss += v[i];
        else ss -= v[i], tot += v[i];
        r = max(r, ss);
    }
    ss = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A')ss += v[i];
        else ss -= v[i];
        r = max(r, ss);
    }
    cout << r + tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
