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
    vi a, b, c;
    ll s = 0;
    for (int &x: v) {
        cin >> x;
        if (x > 0) {
            if (x % 2)a.pb(x);
            else b.pb(x);
            s += x;
        } else if (x % 2)a.pb(-x);
    }
    if (s % 2) {
        cout << s << endl;
    } else {
        sort(a.begin(), a.end());
        cout << s - a[0] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
