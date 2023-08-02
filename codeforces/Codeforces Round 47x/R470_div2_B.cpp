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

int ck[1000005];
vi p[1000005];
int u[1000005];

vi f(int n) {
    if (ck[n]) return vi();
    ck[n] = 1;
    vi r;
    for (int x: p[n]) {
        for (int i = 0; i < x; i++)if (n - i >= max(x, 3))r.pb(n - i);
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    return r;
}

void solve() {

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if(u[i] == 0) {
            for (int j = i; j <= n; j += i) {
                u[j] = 1;
                p[j].pb(i);
            }
        }
    }

    vi v1 = f(n);
    int r = v1[0];
    for (int x: v1) {
        r = min(r, max(3, max(p[x].back(), x - p[x].back() + 1)));
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
