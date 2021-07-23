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
    int p = 0;
    for (int i = x; i < s.size(); i++) {
        if (p < e.size() && s[i] == e[p]) {
            p++;
        } else {
            i++;
            if (i == s.size())return false;
        }
    }

    return p == e.size();
}

void solve() {
    string s, e;
    cin >> s >> e;
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == e[0]) {
            if (can(s, e, i)) {
                cout << "YES" << endl;
                return;
            }
            break;
        }
    }

    for (int i = 1; i < s.size(); i += 2) {
        if (s[i] == e[0]) {
            if (can(s, e, i)) {
                cout << "YES" << endl;
                return;
            }
            break;
        }
    }
    cout << "NO" << endl;
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
