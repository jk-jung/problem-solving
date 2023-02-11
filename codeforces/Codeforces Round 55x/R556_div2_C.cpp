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
    int a = 0, b = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 1) a++;
        else b++;
    }
    if (b)cout << "2 ", b--;
    if (a)cout << "1 ", a--;

    while(b--)cout << "2 ";
    while(a--)cout << "1 ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
