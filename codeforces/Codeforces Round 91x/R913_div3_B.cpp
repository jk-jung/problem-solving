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
    vector<char> r;
    vi A, a, c(s.size());
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (isupper(x)) {
            if (x == 'B') {
                c[i] = 1;
                if (!A.empty()) {
                    c[A.back()] = 1;
                    A.pop_back();
                }
            } else A.pb(i);
        } else {
            if (x == 'b') {
                c[i] = 1;
                if (!a.empty()) {
                    c[a.back()] = 1;
                    a.pop_back();
                }
            } else a.pb(i);
        }
    }
    for (int i = 0; i < s.size(); i++)if (c[i] == 0)cout << s[i];
    cout << endl;
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
