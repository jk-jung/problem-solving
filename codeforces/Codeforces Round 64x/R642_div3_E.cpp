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

int calc(string &s) {
    int n = s.size();
    vector<vi> d(n + 1, vi(3, 1 << 30));

    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1] - '0';
        d[i][0] = d[i - 1][0] + x;
        d[i][1] = min(d[i - 1][1], d[i - 1][0]) + 1 - x;
        d[i][2] = min(d[i - 1][2], d[i - 1][1]) + x;
    }
    return min(d[n][0], min(d[n][1], d[n][2]));
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int tot = 0, r = 1 << 30;
    for (char x: s)if (x == '1') tot++;
    for (int i = 0; i < k; i++) {
        string ss;
        int cnt = 0;
        for (int j = i; j < n; j += k) {
            ss += s[j];
            cnt += s[j] == '1';
        }

        r = min(r, tot - cnt + calc(ss));
    }

    cout << r << endl;
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
