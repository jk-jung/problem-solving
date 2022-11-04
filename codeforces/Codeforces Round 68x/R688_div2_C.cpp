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

int n;

vi calc(vector<string> &v) {
    vi r(10), L(10, 1 << 30), R(10, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x = v[i][j] - '0';
            L[x] = min(L[x], j);
            R[x] = max(R[x], j);
        }
    for (int i = 0; i < n; i++) {
        vi U(10, 1 << 30), D(10, -1);
        for (int j = 0; j < n; j++) {
            int x = v[j][i] - '0';
            U[x] = min(U[x], j);
            D[x] = max(D[x], j);
        }

        for (int k = 0; k < 10; k++) {
            if (D[k] == -1)continue;
            int x = D[k] - U[k], y = max(i - L[k], R[k] - i);
            r[k] = max(r[k], x * i);
            r[k] = max(r[k], x * (n - 1 - i));
            r[k] = max(r[k], D[k] * y);
            r[k] = max(r[k], (n - 1 - U[k]) * y);
        }
    }
    return r;
}

void solve() {

    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    vi r1 = calc(v);
    auto v2 = v;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)v2[i][j] = v[j][i];
    vi r2 = calc(v2);
    for (int i = 0; i < 10; i++)cout << max(r1[i], r2[i]) << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
