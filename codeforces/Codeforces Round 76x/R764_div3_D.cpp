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
    int n, k, c = 0;
    vi v(26);

    cin >> n >> k >> s;
    for (char x: s) v[x - 'a']++;
    for (int x: v) c += x / 2;

    int r = (c / k) * 2;
    int t = n - c * 2;

    while (t < k) c--, t += 2;
    r = max(r, 1 + (c / k) * 2);

    cout << r << '\n';
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
