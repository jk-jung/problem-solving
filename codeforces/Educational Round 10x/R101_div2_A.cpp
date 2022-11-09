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
    if (s.size() % 2) {
        cout << "NO\n";
        return;
    }
    int a = 0, b = 0, c = 0;
    for (char x: s) {
        if (x == '(')a++;
        else if (x == ')')b++;
        else c++;
    }
    int need = (int)s.size() / 2 - a;
    int st = 0;
    for (char x: s) {
        if (x == '(')st++;
        else if (x == ')') st--;
        else {
            if (need > 0)st++, need--;
            else st--;
        }
        if (st < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (need != 0 || st != 0) {
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