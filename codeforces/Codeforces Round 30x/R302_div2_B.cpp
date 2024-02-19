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
    int n, k;
    cin >> n >> k;

    if (k > (n * n + 1) / 2) {
        cout << "NO\n";
    }else {
        cout <<"YES\n";
        vector<string> a(n, string(n, 'S'));
        for (int i = 0; i < n; i++) {
            for (int j = i % 2; j < n; j += 2) {
                if (k == 0)break;
                a[i][j] = 'L';
                k--;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
