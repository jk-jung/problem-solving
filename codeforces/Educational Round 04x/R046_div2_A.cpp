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
    vector<string> a(n), b(n);
    map<string, int> c;
    for (auto &x: a)cin >> x;
    for (auto &x: b)cin >> x, c[x]++;

    int r = 0;
    for (auto &x: a) {
        if (c[x] > 0)c[x]--;
    }
    for (auto &x: a) {
        if (c[x] > 0);
        else {
            for (auto &[y, z]: c) {
                if (x.size() == y.size() && z > 0) {
                    z--;
                    r++;
                    break;
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
