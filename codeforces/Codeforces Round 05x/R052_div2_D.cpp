#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


int d[1005][1005];

struct Operation {
    string op;
    int pos;
    char c;

    Operation(const string &op, int pos, char c) : op(op), pos(pos), c(c) {}
};

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    memset(d, 63, sizeof(d));
    d[0][0] = 0;
    for (int i = 0; i <= n; i++) d[i][0] = i;
    for (int i = 0; i <= m; i++) d[0][i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j])
                d[i + 1][j + 1] = d[i][j];
            else
                d[i + 1][j + 1] = min(
                        min(
                                d[i][j + 1], // Insert
                                d[i + 1][j]  // Delete
                        ),
                        d[i][j] // Replace
                ) + 1;
        }
    }
    cout << d[n][m] << endl;

    vector<Operation> ops;
    while (n || m) {
        if (n > 0 && m > 0 && a[n - 1] == b[m - 1]) {
            n--;
            m--;
        } else if (n > 0 && d[n][m] == d[n - 1][m] + 1) {
            ops.emplace_back("DELETE", m + 1, a[n - 1]);
            n--;
        } else if (m > 0 && d[n][m] == d[n][m - 1] + 1) {
            ops.emplace_back("INSERT", m, b[m - 1]);
            m--;
        } else {
            ops.emplace_back("REPLACE", m, b[m - 1]);
            n--;
            m--;
        }
    }
    reverse(ops.begin(), ops.end());
    for (auto &op: ops) {
        if (op.op == "DELETE") cout << "DELETE " << op.pos << endl;
        else cout << op.op << " " << op.pos << " " << op.c << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
