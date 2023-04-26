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

map<int, int> ck;
vi r;
int day;
int n, m, d;

int pop(map<int, int>::iterator it) {
    auto [x, v] = *it;
    r[v] = day;
    ck.erase(x);
    return x;
}

void solve() {
    cin >> n >> m >> d;

    r.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ck[x] = i;
    }

    while (!ck.empty()) {
        day++;
        int x = pop(ck.begin());
        while (!ck.empty()) {
            auto it = ck.lower_bound(x + d + 1);
            if (it == ck.end())break;
            x = pop(it);
        }
    }
    cout << day << endl;
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
