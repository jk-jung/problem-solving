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

vi v[1005];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        v[i].resize(5);
        for (int &x: v[i])cin >> x;
    }
    n = min(n, 50);
    vi r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            for (int k = 0; k < n; k++) {
                if (j == k)continue;

                int s = 0;
                for (int p = 0; p < 5; p++) {
                    s += (v[j][p] - v[i][p]) * (v[k][p] - v[i][p]);
                }
                if (s > 0)goto NO;
            }
        }
        r.pb(i + 1);
        NO:;
    }
    cout << r.size() << endl;
    for (int x: r)cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
