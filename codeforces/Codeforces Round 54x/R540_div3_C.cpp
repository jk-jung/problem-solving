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

int r[22][22];

void solve() {
    int n;
    cin >> n;
    map<int, int> ck;
    for (int i = 0, x; i < n * n; i++)cin >> x, ck[x]++;
    if (n % 2 == 0) {
        for (auto [x, y]: ck)
            if (y % 4) {
                cout << "NO\n";
                return;
            }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (ck.begin()->S == 0)ck.erase(ck.begin());
                ck[ck.begin()->F] -= 4;
                r[i][j] = ck.begin()->F;
                r[n - i - 1][j] = ck.begin()->F;
                r[n - i - 1][n - j - 1] = ck.begin()->F;
                r[i][n - j - 1] = ck.begin()->F;
            }
        }
    } else {
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                bool ok = false;
                for (auto [x, y]: ck) {
                    if (y >= 4) {
                        ck[x] -= 4;
                        if (ck[x] == 0)ck.erase(x);
                        r[i][j] = x;
                        r[n - i - 1][j] = x;
                        r[n - i - 1][n - j - 1] = x;
                        r[i][n - j - 1] = x;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        for (int i = 0; i <= n / 2; i++) {
            for (int j = 0; j <= n / 2; j++) {
                if (i == j || (i != n / 2 && j != n / 2)) continue;
                bool ok = false;
                for (auto [x, y]: ck) {
                    if (y >= 2) {
                        ck[x] -= 2;
                        if (ck[x] == 0)ck.erase(x);
                        r[i][j] = x;
                        r[n - i - 1][j] = x;
                        r[n - i - 1][n - j - 1] = x;
                        r[i][n - j - 1] = x;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        r[n / 2][n / 2] = ck.begin()->F;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << r[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
