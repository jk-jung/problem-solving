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
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    if (t1 > t2) swap(t1, t2);
    bool a = t1 <= h && h < t2;
    bool b = t1 * 5 <= m && m < t2 * 5;
    bool c = t1 * 5 <= s && s < t2 * 5;
    if(a && b && c) {
        cout << "YES\n";
        return;
    }if(!a && !b && !c) {
        cout <<"YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
