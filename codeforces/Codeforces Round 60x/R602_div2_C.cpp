#include <string.h>
#include <stdio.h>
#include <math.h>
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

void solve() {
    int n, m;
    string s, r;
    cin >> n >> m >> s;

    set<int> q[2];
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') q[0].insert(i);
        else q[1].insert(i);
    }
    for (int i = 0; i < m - 1; i++)r += "()";
    int t = (n - r.size()) / 2;
    for (int i = 0; i < t; i++)r += '(';
    for (int i = 0; i < t; i++)r += ')';

    vector<pi> v;
    for (int i = 0; i < n; i++) {
        for (auto &k: q)
            if (*k.begin() == i)k.erase(i);
        if (s[i] != r[i]) {
            int tar = s[i] == '(' ? 1 : 0;
            int x = *q[tar].begin();
            q[tar].erase(x);
            q[tar ^ 1].insert(x);

            v.pb({i + 1, x + 1});
            s[x] = s[x] == '(' ? ')' : '(';
        }
    }

    cout << v.size() << endl;
    for (auto [x, y]: v)cout << x << " " << y << '\n';
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
