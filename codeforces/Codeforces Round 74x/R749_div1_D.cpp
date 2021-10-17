#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int r[2005];

void solve() {
    int n;
    cin >> n;

    r[n] = n;
    for (int i = 1; i < n; i++) {
        int x = n - i + 1;
        cout << "? ";
        for (int j = 1; j < n; j++)cout << 1 << " ";
        cout << x << endl;

        int q;
        cin >> q;
        if (q > 0) {
            r[n] = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == r[n]) continue;

        cout << "? ";
        for (int j = 1; j < n; j++)cout << r[n] << " ";
        cout << i << endl;

        int q;
        cin >> q;
        r[q] = i;
    }

    cout << "! ";
    for (int j = 1; j <= n; j++)cout << r[j] << " ";
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
