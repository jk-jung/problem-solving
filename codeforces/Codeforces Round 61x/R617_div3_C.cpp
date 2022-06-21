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
    int n;
    string s;
    cin >> n >> s;

    map<pi, int> ck;
    pi x, r = mp(-1, 1 << 30);
    ck[x] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') x.F--;
        if (s[i] == 'R') x.F++;
        if (s[i] == 'U') x.S--;
        if (s[i] == 'D') x.S++;


        if (ck.count(x) && r.S - r.F > i - ck[x]) {
            r.F = ck[x] + 1;
            r.S = i + 1;
        }
        ck[x] = i + 1;
    }
    if (r.F == -1)cout << -1 << endl;
    else cout << r.F << " " << r.S << endl;
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
