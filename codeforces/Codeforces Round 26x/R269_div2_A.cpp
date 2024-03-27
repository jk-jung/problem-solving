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
    vi v(6);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    if (v[0] == v[3]) {
        cout << (v[4] < v[5] ? "Bear" : "Elephant");
    } else if (v[1] == v[4]) {
        cout << (v[0] < v[5] ? "Bear" : "Elephant");
    } else if (v[2] == v[5]) {
        cout << (v[0] < v[1] ? "Bear" : "Elephant");
    } else {
        cout << "Alien";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
