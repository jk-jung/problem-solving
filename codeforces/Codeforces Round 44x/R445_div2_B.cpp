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
    cin >> n;
    vi v(n);
    set<int> ck;
    for (int &x: v)cin >> x, ck.insert(x);
    for (int i = n - 1; i >= 0; i--) {
        if (ck.size() == 1) {
            cout << *ck.begin() << endl;
            return;
        }
        if (ck.count(v[i]))ck.erase(v[i]);
        if (ck.size() == 1) {
            cout << *ck.begin() << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
