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
    string a, b;
    cin >> n >> m >> a >> b;
    vi r(n + 1);
    for (int i = 0; i <= m - n; i++) {
        vi t;
        for (int k = 0; k < n; k++)if (a[k] != b[i + k])t.pb(k + 1);
        if (r.size() > t.size()) r = t;
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
