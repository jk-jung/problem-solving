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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &s: v)cin >> s;

    vi row(n), col(m);
    int A = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'A') {
                A++;
                row[i]++;
                col[j]++;
            }
        }
    }
    if (A == 0) {
        cout << "MORTAL\n";
    } else if (A == n * m) {
        cout << "0\n";
    } else if (row[0] == m || row[n - 1] == m || col[0] == n || col[m - 1] == n) {
        cout << "1\n";
    } else {
        bool ck = false;

        for (int i = 0; i < m; i++)if (col[i] == n)ck = true;
        for (int i = 0; i < n; i++)if (row[i] == m)ck = true;
        if (v[0][0] == 'A' || v[n - 1][0] == 'A' || v[0][m - 1] == 'A' || v[n - 1][m - 1] == 'A') ck = true;
        if (ck) {
            cout << "2\n";
        } else if (row[0] || row[n - 1] || col[0] || col[m - 1]) {
            cout << "3\n";
        } else {
            cout << "4\n";
        }
    }

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
