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

string make_min(int b) {
    string r;
    while (b >= 9) {
        b -= 9;
        r += '9';
    }
    if (b) r += '0' + b;
    sort(r.begin(), r.end());
    return r;
}

bool can(string r, int c, string a) {
    while (c) {
        int t = min(c, 9);
        c -= t;
        r += '0' + t;
    }
    if (r.size() > a.size()) return false;
    while (r.size() < a.size())r += '0';
    return r > a;
}

string f(string a, int c) {
    string r = make_min(c);
    if (r.size() > a.size()) return r;
    while(r.size() < a.size()) r += '0';
    sort(r.rbegin(), r.rend());
    if(r <= a) {
        r[0] --;
        sort(r.begin(), r.end());
        return "1" + r;
    }
    r = "";
    for (char x: a) {
        r += x;
        c -= x - '0';
        if (can(r, c, a))continue;
        while (!can(r, c, a)) {
            r.back()++;
            c--;
        }

        string t = make_min(c);
        while (r.size() + t.size() < a.size())r += '0';
        return r + t;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    string t = "0";
    for (int x: v) {
        t = f(t, x);
        cout << t << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
