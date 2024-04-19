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
    if( n == 1){
        cout << (k == 0 ? 1 : -1);
        return;
    }
    if (n / 2 > k) {
        cout << -1;
        return;
    }
    for (int i = 0; i < (n / 2 - 1) * 2; i+= 2) {
        cout << 1000000000 - i - 1<< " " << 1000000000 - i - 2 << " ";
        k--;
    }
    cout << k << " " << k * 2 << " ";
    if (n % 2)cout << 1000000000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
