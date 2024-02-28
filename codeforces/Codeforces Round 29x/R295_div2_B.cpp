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

int a[100005];

void solve() {
    int n, m;
    cin >> n >> m;
    a[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == m) {
            cout << a[x] - 1 << endl;
            return;
        }
        if (x * 2 <= 100000 && a[x * 2] == 0) {
            a[x * 2] = a[x] + 1;
            q.push(x * 2);
        }
        if (x - 1 >= 0 && a[x - 1] == 0) {
            a[x - 1] = a[x] + 1;
            q.push(x - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
