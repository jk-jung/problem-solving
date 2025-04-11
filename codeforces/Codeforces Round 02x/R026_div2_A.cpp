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


bool f(int x) {

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)return false;
    }
    return true;
}

bool g(int n) {
    int a = 0;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)n /= i;
            a++;
        }
    }
    return a == 2;
}

void solve() {
    int n;
    cin >> n;
    int r = 0;
    for (int i = 6; i <= n; i++)if (g(i))r++;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
