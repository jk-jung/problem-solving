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
    cin >> n;
    vi v(n);
    map<int, int> c;
    for (int &x: v)cin >> x, c[x]++;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if (c.size() > 3) {
        cout << "NO\n";
    } else if (c.size() == 3) {
        cout << (v[1] - v[0] == v[2] -v[1] ? "YES" : "NO\n");
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
