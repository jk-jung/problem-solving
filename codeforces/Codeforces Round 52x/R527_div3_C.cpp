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


string calc(vector<string> &v, string &a, string &b) {
    string t;
    map<int, char> ck;
    for (auto &x: v) {
        int m = x.size();
        if (ck.count(m))t += (ck[m] == 'P' ? 'S' : 'P');
        else {
            char r = 'S';
            if (a.substr(0, m) == x)r = 'P';
            ck[m] = r;
            t += r;
        }
    }
    for (int i = 0; i < t.size(); i++) {
        int m = v[i].size();
        if (t[i] == 'P' && a.substr(0, m) != v[i]) return "";
        if (t[i] == 'S' && b.substr(b.size() - m, m) != v[i]) return "";
    }
    return t;
}

void solve() {
    int n;
    cin >> n;
    vector<string> v(n * 2 - 2);
    for (string &x: v)cin >> x;
    string a, b;
    for (auto &x: v) {
        if (x.size() == n - 1) {
            if (a.empty())a = x;
            else b = x;
        }
    }
    string r1 = calc(v, a, b);
    string r2 = calc(v, b, a);
    cout << (r1.empty() ? r2 : r1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
