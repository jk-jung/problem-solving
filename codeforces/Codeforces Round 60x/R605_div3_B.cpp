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
    string s;
    cin >> s;
    map<char, int> ck;
    for (char x: s) ck[x]++;

    string r;
    int m = min(ck['L'], ck['R']), n = min(ck['U'], ck['D']);
    if (n == 0)m = min(m, 1);
    if (m == 0)n = min(n, 1);
    for (int i = 0; i < m; i++) r += 'L';
    for (int i = 0; i < n; i++) r += 'U';
    for (int i = 0; i < m; i++) r += 'R';
    for (int i = 0; i < n; i++) r += 'D';

    cout << r.size() << endl;
    cout << r << endl;
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
