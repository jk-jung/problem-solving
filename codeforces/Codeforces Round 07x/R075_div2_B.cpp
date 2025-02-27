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
    string a;
    cin >> a;
    reverse(a.begin(), a.end());

    int carry = 0;
    int r = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        int x = a[i] - '0' + carry;
        if (x % 2)x++, r++;
        carry = x / 2;
        r++;
    }
    int last = 1 + carry;
    if(last == 2)r ++;
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
