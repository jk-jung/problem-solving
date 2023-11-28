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
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    string t;
    cin >> t;


    int r = 0, tr = 0;
    for (auto &x: v) {
        if (x.size() >= t.size())continue;
        r++;
        if (++tr % k == 0)r += 5;
    }
    cout << r + 1<< " ";
    for (auto &x: v) {
        if (x.size() != t.size())continue;
        if (x == t)continue;
        r++;
        if (++tr % k == 0)r += 5;
    }
    cout << r + 1<< " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
