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


map<string, int> v;

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> r;
    while (n--) {
        string x, op, y;
        cin >> x >> op;
        int score = 0;
        if (op == "posted") {
            cin >> op >> y >> op;
            score = 15;
        } else if (op == "commented") {
            cin >> op >> y >> op;
            score = 10;
        } else if (op == "likes") {
            cin >> y >> op;
            score = 5;
        }
        y = y.substr(0, y.size() - 2);
        if (x == t || y == t) {
            v[x] += score;
            v[y] += score;
        }
        r.pb(x);
        r.pb(y);
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    sort(r.begin(), r.end(), [&](string &a, string &b) {
        if (v[a] == v[b])return a < b;
        return v[a] > v[b];
    });
    for (string &x: r) {
        if (x == t)continue;
        cout << x << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
