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

const int MAX = 100005;
vector<int> prime(MAX + 1);

void fast_factorization_for_many_numbers() {
    prime[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = 1;
    }
}
int xx[555];
int yy[555];
int a[555][555];

void solve() {
    fast_factorization_for_many_numbers();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            int t = 0;
            while (prime[x]) {
                x++;
                t++;
            }
            a[i][j] = t;
            xx[j] += t;
            yy[i] += t;
        }
    }
    int r = 1 << 30;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){
        r = min(r, xx[j]);
        r = min(r, yy[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
