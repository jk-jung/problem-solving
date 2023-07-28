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

    if (n <= 5)cout << "-1\n";
    else {
        cout << "1 2\n";
        for (int i = 3; i <= n; i++) {
            if (i % 2 == 0)cout << 1 << " " << i << endl;
            else cout << 2 << " " << i << endl;
        }
    }
    for (int i = 1; i < n; i++)cout << i << " " << i + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
