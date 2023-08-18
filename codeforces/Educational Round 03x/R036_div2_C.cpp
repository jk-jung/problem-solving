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
    string a, b, r;
    cin >> a >> b;
    sort(a.begin(), a.end());
    if(a.size() < b.size())b = string(a.size(), '9');

    for (int _ = 0; _ < b.size(); _++) {
        for (int i = a.size() - 1; i >= 0; i--) {
            string t = r + a[i] + a.substr(0, i) + a.substr(i + 1);
            if (t <= b) {
                r += a[i];
                a = a.substr(0, i) + a.substr(i + 1);
                break;
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
