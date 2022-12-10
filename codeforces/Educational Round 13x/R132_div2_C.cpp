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

void solve() {
    string s;
    cin >> s;

    vi q;
    int n = s.size();
    int a = n / 2, b = n / 2;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') a--;
        else if (s[i] == ')') b--;
        else q.pb(i);
    }
    for (int i = 0; i < q.size(); i++) {
        if (i < a)s[q[i]] = '(';
        else s[q[i]] = ')';
    }
    if (a && b) {
        swap(s[q[a - 1]], s[q[a]]);
        int st = 0, ok = 0;
        for (char x: s) {
            if (x == '(') st++;
            else st--;
            if (st < 0) {
                ok = 1;
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
