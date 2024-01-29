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
    int n, t;
    cin >> n >> t;
    string a, b;
    cin >> a >> b;

    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) c0++;
        else c1++;
    }

    // c0으로 전체 컨트롤 가능 (11, 00 )
    // c1으로 하나씩 컨트롤 가능 (01, 10, 11)
    if (t < (c1 + 1) / 2) {
        cout << -1 << endl;
    } else {
        string r = string(n, ' ');

        // x + (c1 - x)  == t
        // x + x + y == c1
        // x + y == t
        // x = c1 - t;
        int x = c1 - t;
        int y = t - x;

        if (x >= 0) {
            int x0 = x, x1 = x;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    if (x0 > 0) {
                        x0--;
                        r[i] = a[i];
                    } else if (x1 > 0) {
                        x1--;
                        r[i] = b[i];
                    } else if (y > 0) {
                        y--;
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != a[i] && c != b[i]) {
                                r[i] = c;
                                break;
                            }
                        }
                    }
                } else {
                    r[i] = a[i];
                }
            }

        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i] && t > 0) {
                    t--;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != a[i] && c != b[i]) {
                            r[i] = c;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i]) {
                    if (t > 0) {
                        t--;
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != a[i] && c != b[i]) {
                                r[i] = c;
                                break;
                            }
                        }
                    } else {
                        r[i] = a[i];
                    }
                }
            }
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
