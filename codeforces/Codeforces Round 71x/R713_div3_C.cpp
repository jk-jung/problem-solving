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
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (char k: s) {
        if (k == '0')a--;
        else if(k == '1') b--;
    }

    for (int l = 0, r = (int) s.size() - 1; l <= r; l++, r--) {
        if (s[l] == '?' && s[r] == '0') s[l] = '0', a--;
        if (s[l] == '?' && s[r] == '1') s[l] = '1', b--;
        if (s[r] == '?' && s[l] == '0') s[r] = '0', a--;
        if (s[r] == '?' && s[l] == '1') s[r] = '1', b--;
    }

    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return;
    }

    for (int l = 0, r = (int) s.size() - 1; l <= r; l++, r--) {
        if (l == r) {
            if (s[l] == '?') {
                if (a) s[l] = '0', a--;
                else if (b) s[r] = '1', b--;
                else {
                    cout << -1 << endl;
                    return;
                }
            }
            continue;
        }
        if (s[l] == '?') {
            if (a >= 2) s[l] = s[r] = '0', a -= 2;
            else if (b >= 2) s[l] = s[r] = '1', b -= 2;
            else {
                cout << -1 << endl;
                return;
            }
        }
        if (s[l] != s[r]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << s << endl;
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
