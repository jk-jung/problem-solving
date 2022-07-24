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

string s;

bool sf(int x, int y) { return s[x] > s[y]; }

void solve() {
    int p;
    cin >> s >> p;
    int n = s.size(), tot = 0;
    vector<int> v(n), r(n);
    for (int i = 0; i < n; i++)v[i] = i, tot += s[i] - 'a' + 1;
    sort(v.begin(), v.end(), sf);

    for (int i = 0; i < n && tot > p; i++) {
        r[v[i]] = 1;
        tot -= (s[v[i]] - 'a' + 1);
    }
    for (int i = 0; i < n; i++)if (r[i] == 0)cout << s[i];
    cout << endl;
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
