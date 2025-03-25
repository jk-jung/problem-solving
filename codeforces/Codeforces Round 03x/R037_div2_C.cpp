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

const int MAX_LEN = 30;

void inc(string &s) {
    s.back()++;
    int flag = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        s[i] += flag;
        flag = 0;
        if (s[i] > '1') {
            s[i] = '0';
            flag = 1;
        }
    }
    if (flag) {
        cout << "NO";
        exit(0);
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n), t(n);
    vector<string> r(n);
    for (int &x: v)cin >> x;
    t = v;
    for (int &x: t)x = min(x, MAX_LEN);

    set < string > used;
    for (int len = MAX_LEN; len >= 1; len--) {
        string now = string(len, '0');
        for (int i = 0; i < n; i++) {
            if (t[i] != len)continue;

            while (used.count(now)) {
                inc(now);
            }
            used.insert(now);
            r[i] = now + string(v[i] - len, '0');
        }
        set<string> nxt;
        for (const string& x: used) nxt.insert(x.substr(0, len - 1));
        used = nxt;

    }
    cout << "YES\n";
    for (string &x: r)cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
