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
    int cnt = 0, r = n;
    for (int i = 0; i < k - 1; i++)cnt += s[i] == 'W';

    for (int i = k - 1; i < n; i++) {
        cnt += s[i] == 'W';
        if (i - k >= 0)cnt -= s[i - k] == 'W';
        r = min(r, cnt);
    }
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
