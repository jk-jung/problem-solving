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

int n, m;
int d[100000];
vector<string> v;

void solve() {
    cin >> n >> m;
    v.resize(n);
    for (auto &x: v)cin >> x;

    d[0] = 0;
    for (int i = 1; i < m; i++) {
        for (auto &x: v) {
            int s = x.size();
            if (s > i) continue;
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
