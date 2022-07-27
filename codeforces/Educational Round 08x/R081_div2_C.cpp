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

int nxt[100005][26];

void solve() {
    string a, b;
    cin >> a >> b;
    set<char> s(a.begin(), a.end());
    for (char x: b) {
        if (!s.count(x)) {
            cout << -1 << endl;
            return;
        }
    }

    vi pos(26, a.size() + 1);
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = pos[j];
        }
        pos[a[i] - 'a'] = i;
    }

    int idx = 0, r = 0;
    while (idx < b.size()) {
        r++;
        for (int i = pos[b[idx] - 'a']; i < a.size();) {
            idx ++;
            if(idx == b.size())break;
            i = nxt[i][b[idx] - 'a'];
        }
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
