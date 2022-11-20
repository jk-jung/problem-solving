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

int n, m;

bool ck(vector<vi> &v, int a, int b) {
    bool ok = true;
    if (b > m)return false;
    for (int i = 0; i < n; i++) {
        swap(v[i][a], v[i][b]);
        for (int j = 1; j < m; j++) {
            if (v[i][j] > v[i][j + 1]) {
                ok = false;
                break;
            }
        }
        swap(v[i][a], v[i][b]);
        if (!ok)return false;
    }
    return true;
}


void solve() {
    cin >> n >> m;
    vector<vi> v(n, vi(m + 2));
    for (auto &y: v) {
        for (int j = 1; j <= m; j++)cin >> y[j];
        y[m + 1] = 1 << 30;
    }

    set<int> ss;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (v[i][j] > v[i][j + 1])
                ss.insert(j);
        }
    }
    if (ss.empty()) {
        cout << "1 1\n";
    } else if (ss.size() == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (v[i][j] > v[i][j + 1]) {
                    int idx = -1;
                    for (int k = 1; k <= m; k++) {
                        swap(v[i][j], v[i][k]);
                        bool a = false;
                        bool b = false;
                        if (v[i][j - 1] <= v[i][j] && v[i][j] <= v[i][j + 1]) a = true;
                        if (v[i][k - 1] <= v[i][k] && v[i][k] <= v[i][k + 1]) b = true;
                        swap(v[i][j], v[i][k]);
                        if (a && b) {
                            idx = k;
                            break;
                        }
                    }
                    if (idx != -1 && ck(v, j, idx)) {
                        cout << j << " " << idx << endl;
                        return;
                    }

                    idx = -1;
                    j++;
                    for (int k = 1; k <= m; k++) {
                        swap(v[i][j], v[i][k]);
                        bool a = false;
                        bool b = false;
                        if (v[i][j - 1] <= v[i][j] && v[i][j] <= v[i][j + 1]) a = true;
                        if (v[i][k - 1] <= v[i][k] && v[i][k] <= v[i][k + 1]) b = true;
                        swap(v[i][j], v[i][k]);
                        if (a && b) {
                            idx = k;
                            break;
                        }
                    }
                    if (idx != -1 && ck(v, j, idx)) {
                        cout << j << " " << idx << endl;
                        return;
                    }
                    cout << "-1\n";
                    return;
                }
            }
        }
    } else if (ss.size() == 2) {
        int a = *ss.begin();
        int b = *ss.rbegin();
        if (ck(v, a, b)) cout << a << " " << b << endl;
        else if (ck(v, a, b + 1)) cout << a << " " << b + 1 << endl;
        else if (ck(v, a + 1, b)) cout << a + 1 << " " << b << endl;
        else if (ck(v, a + 1, b + 1)) cout << a + 1 << " " << b + 1 << endl;
        else {
            cout << "-1\n";
        }
    } else {
        cout << "-1\n";
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
