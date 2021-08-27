#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int sum, m, n;
int r[1000][1000];
int y, x;
vector<pi> v;

bool check(int n) {
    int tot = n * n;
    int blank = (n / 2) * (n / 2);
    int max_slot = (n + 1) / 2 * n;
    int max_cnt = v[m - 1].F;
    if (tot < sum + blank) return false;
    if (max_slot < max_cnt) return false;
    return true;
}

void use(int p) {
    for (; y < n; y += 2) {
        for (; x < n; x += 2) {
            if (v[p].F == 0)return;
            r[y][x] = v[p].S;
            v[p].F--;
        }
        x = 0;
    }
}

void solve() {
    cin >> sum >> m;
    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].F;
        v[i].S = i + 1;
    }

    sort(v.begin(), v.end());

    n = sqrt(sum);
    while (!check(n))n++;

    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)r[i][j] = 0;

    int p = m - 1;
    y = 0;
    x = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 1; j < n; j += 2) {
            if (v[p].F == 0)p = max(0, p - 1);
            if (v[p].F > 0) {
                r[i][j] = v[p].S;
                v[p].F--;
            }
        }
    }
    use(p);
    for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            if (v[p].F == 0)p = max(0, p - 1);
            if (v[p].F > 0) {
                r[i][j] = v[p].S;
                v[p].F--;
            }

        }
    }
    for (int i = p; i >= 0; i--) use(i);

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << r[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
