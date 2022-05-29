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

    map<char, int> cnt;
    for (char x: s)cnt[x]++;

    int r = 1;
    for (int i = 1; i <= n; i++) {
        if (k % i)continue;
        for (int j = 1; j <= n / i; j++) {
            int t = 0;
            for (auto [c, v]: cnt)
                t += v / j;
            if(t >= i)
                r = max(r, i * j);
        }
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
