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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vi r(n);
    if (k % 2) {
        int idx = n - 1;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') {
                idx = i;
                break;
            }
        r[idx]++;
        k--;
        for (int i = 0; i < n; i++) {
            if (i != idx)
                s[i] = s[i] == '0' ? '1' : '0';
        }
    }
    vi t;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' || i == n - 1)t.pb(i);
    }
    for (int i = 1; i < t.size(); i += 2) {
        if (k) {
            s[t[i - 1]] = s[t[i - 1]] == '0' ? '1' : '0';
            s[t[i]] = s[t[i]] == '0' ? '1' : '0';
            k -= 2;
            r[t[i - 1]]++;
            r[t[i]]++;
        }
    }
    r[n - 1] += k;
    cout << s << endl;
    for (int x: r)cout << x << " ";
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
