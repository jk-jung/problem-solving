#include <cstring>
#include <cstdio>
#include <cmath>
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
string t = "abacaba";

int count(string &s) {
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, t.size()) == t)r++;
    }
    return r;
}

void solve() {
    int n;
    string s, r;
    cin >> n >> s;

    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        string a = s.substr(i, t.size());
        if (a.size() != t.size())continue;

        int ok = true;
        for (int k = 0; k < t.size(); k++) {
            if (a[k] != '?' && a[k] != t[k]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            r = s;
            for (int k = 0; k < t.size(); k++) r[i + k] = t[k];
            replace(r.begin(), r.end(), '?', 'z');

            if(count(r) == 1) {
                cout << "YES\n" << r << endl;
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
