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

char a[555][555];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)cin >> (a[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#') {
                if (a[i + 1][j] == '#' && a[i + 2][j] == '#' && a[i + 1][j - 1] == '#' && a[i + 1][j + 1] == '#') {
                    a[i][j] = '.';
                    a[i + 1][j] = '.';
                    a[i + 2][j] = '.';
                    a[i + 1][j - 1] = '.';
                    a[i + 1][j + 1] = '.';
                } else {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
