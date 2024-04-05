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

int r[] = {0, 0, 0, 4};

void solve() {
    string s;
    cin >> s;
    // 1: 1 1 1 1 1 1
    // 2: 2 4 3 1 2 4 3 1
    // 3: 3 4 2 1 3 4 2 1
    // 4: 4 1 4 1 4 1 4 1
    ll t = stoll(s.substr(max(0, (int) s.size() - 2)));
    cout << r[(t + 3) % 4];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
