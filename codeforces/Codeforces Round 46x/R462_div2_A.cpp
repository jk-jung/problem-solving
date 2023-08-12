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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    vector<ll> r;
    for(int x: a){
        ll t = -(1ll << 60);
        for(int y:b){
            t = max(t, (ll)x * y);
        }
        r.pb(t);
    }
    sort(r.begin(), r.end());
    cout << r[r.size() - 2] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
