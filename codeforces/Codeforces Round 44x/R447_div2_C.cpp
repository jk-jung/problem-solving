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
    set<int> s;
    for (int &x: v)cin >> x, s.insert(x);

    vi r;
    for (int i = 0; i < v.size(); i++)r.pb(v[i]), r.pb(v[0]);
    for (int i = 0; i < r.size(); i++) {
        for (int j = i, y = 0; j < r.size(); j++) {
            y = gcd(y, r[j]);
            if(!s.count(y)) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
