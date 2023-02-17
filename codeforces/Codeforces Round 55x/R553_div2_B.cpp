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

int a[555][555];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    for (int k = 0; k < 10; k++) {
        vi v;
        int x = 0, ok = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) if (a[i][j] >> k & 1) cnt++;
            if (cnt == m) {
                v.pb(1);
                x ^= 1;
            } else if (cnt > 0) {
                v.pb(-1);
                ok = 1;
            } else {
                v.pb(1);
            }
        }
        if (x || ok == 1) {
            cout << "TAK\n";
            for (int i = 0; i < n; i++) {
                if (v[i] == -1) {
                    for (int j = 0; j < m; j++) {
                        int tt = a[i][j] >> k & 1;
                        if (x == 0 && tt == 1) {
                            cout << j + 1 << ' ';
                            x ^= 1;
                            break;
                        }
                        if (x == 1 && tt == 0) {
                            cout << j + 1 << ' ';
                            break;
                        }
                    }
                } else cout << 1 << ' ';
            }
            return;
        }
    }
    cout << "NIE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
