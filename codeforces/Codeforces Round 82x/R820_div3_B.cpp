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
    int n;
    string s, r;
    cin >> n >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            int x = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            r += x + 'a' - 1;
            i -= 2;
        } else r += s[i] - '0' + 'a' - 1;
    }
    reverse(r.begin(), r.end());
    cout <<r << endl;
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
