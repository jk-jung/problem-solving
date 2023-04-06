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

const int mod = 1000000007;

void add(int &x, int &y) {
    x = (x + y) % mod;
}

void solve() {
    int n;
    cin >> n;
    vi v(n), r(1000005);
    for (int &x: v)cin >> x;

    r[0] = 1;
    for (int x: v) {
        vi q;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                int j = x / i;
                q.pb(i);
                if (j != i)q.pb(j);
            }
        }
        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());
        for (int i: q)add(r[i], r[i - 1]);
    }
    int t = 0;
    for (int i = 1; i <= 1000000; i++)add(t, r[i]);

    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
