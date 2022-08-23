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
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = -1, ri=0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!q.empty() && q.front() == i - k + 1)q.pop();
        if(i >= k - 1 && r < (int)q.size()){
            r = q.size();
            ri = i;
        }
        if (i && i + 1 < n && v[i - 1] < v[i] && v[i] > v[i + 1]) q.push(i);
    }
    cout << r + 1<<" " << ri - k + 2 << endl;
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
