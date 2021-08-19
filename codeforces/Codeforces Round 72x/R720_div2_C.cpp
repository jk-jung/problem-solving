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
#include <random>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int n, i1, i2;
int v[10005];

int q(int op, int i, int j, int x) {
    int r;
    cout << "? " << op << " " << i + 1 << " " << j + 1 << " " << x << endl;
    cin >> r;
    return r;
}

pi get_first() {
    int s = 1, e = n - 1, r = -1, t;

    while (s <= e) {
        int m = (s + e) / 2;
        t = min(q(2, 0, 1, m), q(2, 1, 0, m));
        if (t >= m + 1) {
            r = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    if (r == -1) {
        if (q(1, 0, 1, 1) == 1) return mp(1, 1);
        else return mp(0, 1);
    } else if (r == n - 1) {
        if (q(2, 0, 1, n - 1) == n) return mp(0, n);
        else return mp(1, n);
    } else {
        if (q(2, 0, 1, r + 1) == r + 1) return mp(0, r + 1);
        else return mp(1, r + 1);
    }
}


void upper(int x) {
    if (v[x]) return;
    int k = q(1, i1, x, n - 1);
    if (k > v[i1]) v[x] = k;
}

void lower(int x) {
    if (v[x]) return;
    int k = q(2, x, i2, 1);
    if (k < v[i2]) v[x] = k;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)v[i] = 0;
    get_first();

    auto[idx, val] = get_first();
    i1 = i2 = idx;
    v[i1] = val;

    vi vv(n - 1);
    for (int i = 0; i < n; i++)if (i != i1)vv.pb(i);
    random_shuffle(vv.begin(), vv.end());


    for (int i = 0; i < vv.size(); i++) {
        int x = vv[i] % n;

        if (n - v[i1] + 1 > v[i2])
            upper(x), lower(x);
        else
            lower(x), upper(x);

        if (v[i1] > v[x]) i1 = x;
        if (v[i2] < v[x]) i2 = x;
    }

    cout << "! ";
    for (
            int i = 0;
            i < n;
            i++)
        cout << v[i] << " ";
    cout <<
         endl;
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
