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


bool sf(pair<string, int> a, pair<string, int> b) {
    return a.F < b.F;
}

void solve() {
    int n, m;
    string K;
    cin >> n >> m >> K;
    int k = (K[2] - '0') * 10 + (K[3] - '0');
    vector<pair<string, int>> v;
    set < string > s;
    for (int i = 0; i < n; i++) {
        string x;
        int y;
        cin >> x >> y;
        y = y * k / 100;
        if (y < 100)continue;
        v.pb(mp(x, y));
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;
        if (!s.count(x)) {
            v.pb(mp(x, 0));
        }
    }

    sort(v.begin(), v.end(), sf);
    cout << v.size() << endl;
    for (auto it: v) {
        cout << it.F << " " << it.S << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
