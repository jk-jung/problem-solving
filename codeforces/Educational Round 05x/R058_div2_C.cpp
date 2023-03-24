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

struct Data {
    int s, e, i;
};

bool sf(Data a, Data b) { return a.s < b.s; }

vi process(vector<Data> &v) {
    sort(v.begin(), v.end(), sf);
    int e = v[0].e;
    vi r(v.size(), 2);
    r[v[0].i] = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].s <= e)e = max(e, v[i].e), r[v[i].i] = 1;
        else {
            return r;
        }
    }
    r[0] = -1;
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<Data> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].s >> v[i].e, v[i].i = i;
    vi r1 = process(v);
    for (int i = 0; i < n; i++)v[i].s *= -1, v[i].e *= -1, swap(v[i].s, v[i].e);
    vi r2 = process(v);
    if (r1[0] != -1) {
        for (int x: r1)cout << x << " ";
        cout << endl;
    } else if (r2[0] != -1) {
        for (int x: r2)cout << x << " ";
        cout << endl;
    } else cout << "-1\n";
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
