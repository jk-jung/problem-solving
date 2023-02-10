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

    string r, s = "aeiou";
    for (int i = 5; i * i <= n; i++) {
        if (n % i)continue;
        int j = n / i;
        if (j >= 5) {
            for (int y = 0; y < i; y++) {
                for (int x = 0; x < j; x++) {
                    r += s[(x + y) % 5];
                }
            }
            cout << r << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
