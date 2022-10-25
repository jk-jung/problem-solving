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
    map<char, int> ck;
    for (char x: s) {
        while (!r.empty() && r.back() > x) {
            char t = min('9', char(r.back() + 1));
            ck[t]++;
            r.pop_back();
        }
        r.pb(x);
    }
    for (char x: r) {
        for (char i = '0'; i <= x; i++) {
            for (int k = 0; k < ck[i]; k++)cout << i;
            ck[i] = 0;
        }
        cout << x;
    }
    for (char i = '0'; i <= '9'; i++) {
        for (int k = 0; k < ck[i]; k++)cout << i;
        ck[i] = 0;
    }
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
