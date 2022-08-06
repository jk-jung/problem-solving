/*
 * Idea
 * make automata for states 00, 01, 10, 11 and find a way how to merge optimally.
 */
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


int n, q;
string s;
int l[200005];
int r[200005];
int ss[200005];
int bal[200005];

void solve() {
    cin >> n >> q;
    cin >> s;

    s = s[0] + s + s[n - 1];
    for (int i = 1; i <= n; i++)l[i] = s[i - 1] == s[i] ? i : l[i - 1];
    for (int i = n; i >= 1; i--)r[i] = s[i + 1] == s[i] ? i : r[i + 1];

    for (int i = 1; i <= n; i++) {
        ss[i] = ss[i - 1];
        bal[i] = bal[i - 1];
        if (s[i] == s[i + 1]) {
            ss[i]++;
            char x = s[l[i]];
            char y = s[r[i]];
            if (x == y) bal[i] += x == '1' ? 1 : -1;
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x = l[x], y = r[y];
        int bl = bal[y] - bal[x - 1];
        int sum = ss[y] - ss[x - 1];

        int ans = (sum + ab(bl)) / 2;

        if ((sum + ab(bl)) % 2 == 1) ans++;
        else if (ab(bl) == 0) ans++;
        else if (bl > 0 ^ s[x] == '1') ans++;

        cout << ans << "\n";

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
