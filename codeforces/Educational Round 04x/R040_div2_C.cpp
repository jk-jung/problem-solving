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
    for (int &x: v)cin >> x, x--;

    int w = -1;
    for (int i = 1; i < n; i++) {
        int t = ab(v[i] - v[i - 1]);
        if (t != 1)w = t;
    }
    if (w == 0) {
        cout << "NO\n";
    } else if (w == -1) {
        sort(v.begin(), v.end());
        cout << "YES\n1 " << v.back() + 1<< endl;
    } else {
        for (int i = 1; i < n; i++) {
            int y1 = v[i - 1] / w, x1 = v[i - 1] % w;
            int y2 = v[i] / w, x2 = v[i] % w;

            if (ab(y1 - y2) + ab(x1 - x2) != 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n" << 1000000000 << " " << w << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
