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
    vi v(n);
    string s;
    for (int &x: v)cin >> x;
    cin >> s;

    v.pb(0);
    s += 'A';
    vi tmp;
    ll r = 0;
    char t = s[0];
    for (int i = 0; i <= n; i++) {
        if (s[i] != t) {
            sort(tmp.begin(), tmp.end());
            reverse(tmp.begin(), tmp.end());
            for (int j = 0; j < min(int(tmp.size()), k); j++)r += tmp[j];
            tmp.clear();
            t = s[i];
        }
        tmp.pb(v[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
