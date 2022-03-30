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
    int n;
    cin >> n;

    map<int, int> ck, c2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ck[x]++;
    }
    int tot = 0;
    for (auto[k, x]: ck)c2[x]++, tot += x;

    int r = n, remain = 0, remain_cnt = 0, last = -1;
    for (auto it = c2.rbegin(); it != c2.rend(); it++) {
        auto[size, cnt] = *it;
        tot -= size * cnt;
        remain += (last - size) * remain_cnt;
        r = min(r, tot + remain);
        remain_cnt += cnt;
        last = size;
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
