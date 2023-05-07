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
    string a, b, c, d;
    cin >> n >> a >> b;
    c = a;
    d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    if (c != d)cout << -1;
    else {
        vi r;
        swap(a, b);
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])continue;

            for (int j = n - 1, f = 0; j >= i; j--) {
                if (f) {
                    r.pb(j + 1);
                    swap(b[j], b[j + 1]);
                } else if (b[j] == a[i])f = 1;
            }
        }
        assert(a == b);
        cout << r.size() << endl;
        for (int x: r)cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
