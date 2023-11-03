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
    string s;
    cin >> s;
    bool r = true;
    if (s[0] != 'a')r = false;
    map<int, int> ck;
    ck[s[0]] = 1;
    for (char x: s) {
        if (ck.count(x))continue;
        char y = ck.rbegin()->first;
        if ( y + 1 < x)r = false;
        ck[x] = 1;
    }
    cout << (r ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
