#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    int n, m;
    string s;
    cin >> n >> m >> s;

    m = min(m, n);
    while (m--) {
        string nxt;
        for (int i = 0; i < n; i++) {
            int c = 0;
            if (i == 0 || s[i - 1] == '0') c++;
            if (i == n - 1 || s[i + 1] == '0') c++;
            if(s[i] == '1' || c == 1)nxt += '1';
            else nxt += '0';
        }

        s = nxt;
    }
    cout << s << '\n';
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