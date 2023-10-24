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

bool sf(string &a, string &b) { return a.size() > b.size(); }


string f(string s, int c = 0, int b = 0) {
    int t = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (b && (s[i] - '0') % 3 == c) {
            b--;
            s[i] = ' ';
        } else {
            t += s[i] - '0';
        }
    }
    string r;
    if (t % 3) return r;
    bool flag = false;
    bool temp = false;
    for (char x: s) {
        if (x == ' ')continue;
        temp = true;
        if (x != '0')flag = true;
        if (flag) r += x;
    }
    if(r.empty() && temp)r = "0";
    return r;
}

void solve() {
    string s;
    cin >> s;
    vector<string> v;
    v.pb(f(s));
    v.pb(f(s, 1, 1));
    v.pb(f(s, 1, 2));
    v.pb(f(s, 2, 1));
    v.pb(f(s, 2, 2));

    sort(v.begin(), v.end(), sf);
    for (auto &x: v) {
        if (x.size() == 0) continue;
        cout << x << endl;
        return;
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
