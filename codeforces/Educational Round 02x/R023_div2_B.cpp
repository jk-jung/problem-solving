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
    map<int, int> c;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, c[x]++;
    sort(v.begin(), v.end());
    if (v[0] == v[2]) {
        ll t = c[v[0]];
        cout << t * (t - 1) * (t - 2) / 6 << endl;
    } else if (v[0] == v[1]) {
        ll t = c[v[0]];
        cout << t * (t - 1) / 2 * c[v[2]] << endl;
    } else if (v[1] == v[2]) {
        ll t = c[v[2]];
        cout << t * (t - 1) / 2 * c[v[0]] << endl;
    } else {
        cout << c[v[0]] * c[v[1]] * c[v[2]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
