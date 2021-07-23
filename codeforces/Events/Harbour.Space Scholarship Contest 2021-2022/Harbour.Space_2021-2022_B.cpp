#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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


bool can(string &s, string &e, int x) {
    for (int i = x, p = 0; i < s.size(); i++, p++) {
        if (s[i] != e[p]) break;
        if (p + 1 == e.size()) return true;
        for (int j = i - 1, p2 = p + 1; j >= 0; j--, p2++) {
            if (s[j] != e[p2])break;
            if (p2 + 1 == e.size()) return true;
        }
    }
    return false;
}

void solve() {
    string s, e;
    cin >> s >> e;

    bool r = false;
    for (int i = 0; i < s.size(); i++) {
        if (can(s, e, i)) {
            r = true;
            break;
        }
    }

    cout << (r ? "YES" : "NO") << endl;
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
