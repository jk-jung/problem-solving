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

bool f(string &s, string a, string b) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == a[0] && i + 1 < n && s[i + 1] == a[1]) {
            for (int j = i + 2; j < n; j++) {
                if (s[j] == b[0] && j + 1 < n && s[j + 1] == b[1]) return true;
            }
            break;
        }
    }
    return false;
}
void solve() {
    string s;
    cin >> s;
    cout << (f(s, "AB", "BA") || f(s, "BA", "AB") ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
