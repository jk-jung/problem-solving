#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        string s = string((n - i) * 2, ' ');
        for (int j = 0; j <= i; j++) {
            s += char(j + '0');
            s += ' ';
        }
        for (int j = i - 1; j >= 0; j--) {
            s += char(j + '0');
            s += ' ';
        }
        if (s.back() == ' ')s.pop_back();
        cout << s << endl;
    }
    for (int i = n - 1; i >= 0; i--) {
        string s = string((n - i) * 2, ' ');
        for (int j = 0; j <= i; j++) {
            s += char(j + '0');
            s += ' ';
        }
        for (int j = i - 1; j >= 0; j--) {
            s += char(j + '0');
            s += ' ';
        }
        if (s.back() == ' ')s.pop_back();
        cout << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
