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

bool sf(string &a, string &b) {
    return a + b < b + a;
}

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    sort(v.begin(), v.end(), sf);
    for (const auto &x: v)cout << x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
