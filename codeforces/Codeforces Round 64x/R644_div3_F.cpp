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

int n, m;

bool can(string &s, vector<string> &v) {
    for (auto &t: v) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += s[i] != t[i];
            if (cnt >= 2) return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<string> v(n);
    for (auto &s: v)cin >> s;

    for (int i = 0; i < m; i++) {
        for (char x = 'a'; x <= 'z'; x++) {
            string t = v[0];
            t[i] = x;

            if (can(t, v)) {
                cout << t << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
