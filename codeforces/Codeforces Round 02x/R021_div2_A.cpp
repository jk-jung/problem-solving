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


vector<string> split(string &a, char t) {
    vector<string> r;
    if (a.empty()) {
        r.pb("");
        return r;
    }
    r.pb("");
    for (char x: a) {
        if (x == t)r.pb("");
        else r.back() += x;
    }
    return r;
}

bool check(string &a) {
    if (a.size() > 16 || a.empty())return false;
    for (char x: a) {
        if ('a' <= x && x <= 'z')continue;
        if ('A' <= x && x <= 'Z')continue;
        if ('0' <= x && x <= '9')continue;
        if (x == '_') continue;
        return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;

    vector<string> t1 = split(s, '/');
    if (t1.size() >= 3) {
        cout << "NO";
        return;
    }
    if (t1.size() == 2 && !check(t1[1])) {
        cout << "NO";
        return;
    }
    vector<string> e1 = split(t1[0], '@');
    if (e1.size() != 2 || !check(e1[0])) {
        cout << "NO";
        return;
    }
    vector<string> e2 = split(e1[1], '.');
    for (string &x: e2) {
        if (!check(x)) {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
