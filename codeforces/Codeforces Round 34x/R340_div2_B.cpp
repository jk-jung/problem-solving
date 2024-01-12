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
    deque<int> q;
    cin >> n;
    for (int x = 1; x <= n; x++) {
        int a;
        cin >> a;
        q.pb(a);
    }
    while (!q.empty() && q.front() == 0)q.pop_front();
    while (!q.empty() && q.back() == 0)q.pop_back();
    ll r = 1, c = 1;
    for (int x: q) {
        if (x == 0)c++;
        else {
            r *= c;
            c = 1;
        }
    }
    if (q.empty())r = 0;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
