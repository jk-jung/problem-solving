/*
 * Idea
 * We claim that a string has at least one irreducible anagram
 * if and only if one of the following conditions holds.
 *   - Its length is equal to 1.
 *   - Its first and last characters are different.
 *   - It contains at least three different characters.
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

int cnt[26][200005];

void solve() {
    int n, q;
    string s;
    cin >> s >> q;
    n = s.size();
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'][i + 1]++;
        for (int k = 0; k < 26; k++)
            cnt[k][i + 1] += cnt[k][i];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        int kind = 0;
        for (int i = 0; i < 26; i++)if (cnt[i][y] - cnt[i][x - 1] > 0)kind++;

        bool ok = false;
        if (kind >= 3) ok = true;
        else if (y == x)ok = true;
        else if (s[y - 1] != s[x - 1])ok = true;
        cout << (ok ? "Yes\n" : "No\n");
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
