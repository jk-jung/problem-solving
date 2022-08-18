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
    for (int &x: v)cin >> x;
    map<ll, int> ck;

    ll r = 0;
    ll cur = 0;
    int last = 0;
    ck[0] = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        cur += x;
        if (x == 0)last = i + 1;
        else if (ck.count(cur)) {
            last = max(last, ck[cur] + 1);
        }
        r += i - last + 1;
        ck[cur] = i + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
