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
    int n, s;
    cin >> n >> s;
    vi v(n);
    for (int &x: v)cin >> x;

    queue<int> q;
    int r = 0, t = 0;
    for (int x: v) {
        q.push(x);
        if (x == 1)t++;

        while (t > s) {
            t -= q.front();
            q.pop();
        }
        if (t == s)r = max(r, (int)q.size());
    }
    if(r == 0) r = n + 1;
    cout << (n - r) << endl;
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
