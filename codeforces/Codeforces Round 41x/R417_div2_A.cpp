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

int a[5][5];

void solve() {
    for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)cin >> a[i][j];

    for (int i = 0; i < 4; i++) {
        if (a[i][3] == 1) {
            if (a[i][0] || a[i][1] || a[i][2]) {
                cout << "YES\n";
                return;
            }
            int right = (i + 1) % 4;
            int front = (i + 2) % 4;
            int left = (i + 3) % 4;

            if(a[right][0] || a[front][1] || a[left][2]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
