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
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t = s.substr(0, k);

    for (int i = 1; i <= n - k; i++) {
        int x = (i - 1) % k;
        int y = i + k - 1;
        if (t[x] == '?') t[x] = s[y];
        else if (t[x] == '0' && s[y] == '1') {
            cout << "NO\n";
            return;
        } else if (t[x] == '1' && s[y] == '0') {
            cout << "NO\n";
            return;
        }
    }
    vi cnt(2);
    for (char x: t) {
        if (x == '0') cnt[0]++;
        if (x == '1') cnt[1]++;
    }
    if(cnt[0] <= k/2 && cnt[1] <= k/2) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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
