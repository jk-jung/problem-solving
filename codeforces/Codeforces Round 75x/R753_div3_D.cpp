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

bool solve() {
    int n;
    cin >> n;
    vi v(n), a, b;
    string s;
    for (int i = 0; i < n; i++)cin >> v[i];
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'R') a.pb(v[i]);
        else b.pb(v[i]);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < i + 1) return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if(a[i] > (int)b.size() + i + 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        cout << (solve() ? "YES" : "NO") << '\n';
}
