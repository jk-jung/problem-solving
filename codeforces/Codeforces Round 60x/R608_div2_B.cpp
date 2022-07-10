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

int n;

pair<bool, vi> check(string s, char x) {
    vi v;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != x) {
            s[i + 1] = s[i + 1] == 'W' ? 'B' : 'W';
            v.pb(i + 1);
        }
    }
    if (s[n - 1] != x) return {false, {}};
    return {true, v};
}

void solve() {
    string s;
    cin >> n >> s;
    auto [r1, v1] = check(s, 'W');
    auto [r2, v2] = check(s, 'B');
    vi v = r1 ? v1 : v2;

    if (!r1 && !r2) {
        cout << -1 << endl;
    } else {
        cout << v.size() << endl;
        for (int x: v)cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
