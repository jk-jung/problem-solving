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
    string s;
    cin >> n >> s;
    int a = (n - 11) / 2;
    int b = a;

    for (int i = 0; i < n; i++) {
        if (s[i] == '8' && b > 0) {
            s[i] = ' ';
            b--;
        }
        else if (s[i] != '8' && a > 0) {
            s[i] = ' ';
            a--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            cout << (s[i] == '8' ? "YES" : "NO") << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
