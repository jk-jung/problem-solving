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
    int n, x;
    cin >> n >> x;
    if (n == 1) cout << "YES\n" << x << endl;
    else if (n == 2) {
        if (x == 0)cout << "NO\n";
        else cout << "YES\n" << x << " " << 0 << endl;
    } else if (n == 3) {
        int a = 1 << 19;
        int b = 1 << 18;
        int c = 1 << 17;
        cout << "YES\n" << x + a + b << " " << a + c << " " << b + c << endl;
    } else {
        cout << "YES\n";
        int a = 1 << 19;
        int b = 1 << 18;
        int c = 1 << 17;
        vi r = {x};
        int st = 0;
        for (int i = 1; r.size() < n - 3; i++) {
            if (i == x)continue;
            st ^= i;
            r.pb(i);
        }
        r.pb(st + a + b);
        r.pb(st + a + c);
        r.pb(st + b + c);

        for (int y: r)cout << y << " ";
        cout << endl;
    }
    vi v = {x};
    n--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
