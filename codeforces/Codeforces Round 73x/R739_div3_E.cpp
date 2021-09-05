#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    int n, ok = 1, m = 0;
    string s, ord, r;
    vi cnt(26), ck(26);
    cin >> s;
    n = (int) s.size();

    for (int i = n - 1; i >= 0; i--) {
        if (ord.find(s[i]) == -1)ord = s[i] + ord;
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < (int) ord.size(); i++) {
        int k = ord[i] - 'a';
        if (cnt[k] % (i + 1) != 0) {
            cout << -1 << '\n';
            return;
        }
        cnt[k] /= (i + 1);
        m += cnt[k];
    }
    for (int i = 0; i < m; i++) {
        cnt[s[i] - 'a']--;
        r += s[i];
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    string s2 = r;
    for (char o: ord) {
        ck[o - 'a'] = 1;
        for (char i: r) {
            if (ck[i - 'a'] == 0)s2 += i;
        }
    }
    if (s != s2) {
        cout << -1 << '\n';
        return;
    }

    cout << r << " " << ord << '\n';
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
