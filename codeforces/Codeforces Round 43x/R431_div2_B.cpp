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

    for (int i = 0; i <= 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = j - i;
            int dy = v[j] - v[i];
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            vi t;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j)continue;
                int dx2 = k - i;
                int dy2 = v[k] - v[i];
                int g2 = gcd(dx2, dy2);
                dx2 /= g2;
                dy2 /= g2;
                if(dx2 < 0)dx2 = -dx2, dy2 = -dy2;
                if (dx == dx2 && dy == dy2) {
                } else {
                    t.pb(k);
                }
            }
            if (t.size() == 1) {
                cout << "Yes\n";
                return;
            } else if (t.size() > 1) {
                int dx2 = dx;
                int dy2 = dy;
                set<pi> ss;
                for (int k = 1; k < t.size(); k++) {
                    dx = t[k] - t[k - 1];
                    dy = v[t[k]] - v[t[k - 1]];
                    g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    ss.insert({dy, dx});
                }
                if (ss.size() == 1 && *ss.begin() == pi(dy2, dx2)) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
