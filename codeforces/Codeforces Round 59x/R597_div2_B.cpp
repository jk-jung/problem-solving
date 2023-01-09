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
    int n, a, b, c;
    string s, r;
    cin >> n >> a >> b >> c;
    cin >> s;
    int win = n;
    for (char x: s) {
        if (a && x == 'S')a--, r += 'R';
        else if (b && x == 'R')b--, r += 'P';
        else if (c && x == 'P')c--, r += 'S';
        else r += ' ', win--;
    }
    for (int i = 0; i < n; i++) {
        if (r[i] == ' ') {
            if (a)a--, r[i] = 'R';
            else if (b)b--, r[i] = 'P';
            else if (c)c--, r[i] = 'S';
        }
    }
    if (win >= (n + 1) / 2) {
        cout << "YES\n" << r << endl;
    } else cout << "NO\n";
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
