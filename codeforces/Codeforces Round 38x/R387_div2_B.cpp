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

vector<pi> f(string &s) {
    vector<pi> r;
    r.pb({0, 'A'});
    r.pb({0, 'C'});
    r.pb({0, 'G'});
    r.pb({0, 'T'});
    for (char x: s) {
        if (x == 'A')r[0].F++;
        if (x == 'C')r[1].F++;
        if (x == 'G')r[2].F++;
        if (x == 'T')r[3].F++;
    }
    sort(r.begin(), r.end());
    return r;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<char, int> ck;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = f(s)[0].S;
    }
    cout << (f(s)[0].F == f(s)[3].F ? s : "===");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
