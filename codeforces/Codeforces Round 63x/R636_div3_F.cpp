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
int r[505];


bool check(int k, vector<vi> &v, vector<vi> &id2group) {
    vi used(n + 1, -1), remain(n - 1);
    for (int i = 0; i < n - 1; i++)remain[i] = v[i].size();
    queue<int> q;

    auto use = [&](int val, int idx) {
        r[idx] = val;
        used[val] = idx;
        for (int x: id2group[val]) {
            if (--remain[x] == 1 && x != k) q.push(x);
        }
    };

    use(v[k][0], 0);
    use(v[k][1], 1);

    bool fixed = false;
    for (int i = 2; i < n; i++) {
        if (q.size() != 1) return false;

        int idx = q.front();
        q.pop();

        int val = 0;
        vi cur(n + 1);
        for (int x: v[idx]) {
            if (used[x] == -1) val = x;
            else cur[used[x]] = 1;
        }
        if (!fixed && cur[0] == 1 && cur[1] == 0) {
            swap(r[0], r[1]);
            swap(cur[0], cur[1]);
            swap(used[r[0]], used[r[1]]);
            fixed = true;
        }
        for (int j = i + 1 - v[idx].size(); j < i; j++)
            if (!cur[j]) return false;

        use(val, i);
    }
    return true;
}

void solve() {
    cin >> n;
    vector<vi> v(n - 1);
    vector<vi> id2group(n + 1);
    for (int k = 0, m; k < n - 1; k++) {
        cin >> m;
        v[k].resize(m);
        for (int &x: v[k]) {
            cin >> x;
            id2group[x].pb(k);
        }
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
        if (v[i].size() == 2 && check(i, v, id2group)) {
            ok = true;
            break;
        }
    }
    assert(ok);
    for (int i = 0; i < n; i++)cout << r[i] << " ";
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