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

int a[10005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i];
    while (m--) {
        int s, e, x;
        cin >> s >> e >> x;

        int c = 0;
        for (int i = s; i <= e; i++) {
            if (a[i] < a[x])c++;
        }
        cout << (c == x - s ? "Yes" : "No") << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
