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

int a[5555];
int m, M;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            a[y] = 1;
            a[z] = 1;
        } else {
            cin >> y;
            a[y] = 1;
        }
    }
    int i = 1;
    while (i < n) {
        if (a[i] == 0) {
            if (i + 1 < n && a[i + 1] == 0) {
                a[i] = 1;
                a[i + 1] = 1;
                m++;
                M += 2;
                i += 2;
            } else {
                a[i] = 1;
                m++;
                M++;
                i++;
            }
        } else i++;
    }
    cout << m << " " << M << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
