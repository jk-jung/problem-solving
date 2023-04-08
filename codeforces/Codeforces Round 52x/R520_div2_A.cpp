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
    vi v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    v.pb(1001);
    int r = 2, cur = 1;
    for (int i = 1; i <= n + 1; i++) {
        if (v[i - 1] + 1 == v[i])cur++;
        else {
            r = max(r, cur);
            cur = 1;
        }
    }
    r = max(r, cur);
    cout << r - 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
