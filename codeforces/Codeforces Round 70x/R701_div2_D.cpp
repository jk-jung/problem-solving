#include <string.h>
#include <stdio.h>
#include <math.h>
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

int M = 1000000;
int a[505][505];
int b[505][505];

void solve() {
    int n, m;
    cin >> n >> m;

    int y = 2;
    for (int i = 3; i <= 16; i++)y = y * i / gcd(y, i);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)cin >> a[i][j];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = a[i][j];
            b[i][j] = y;
            if ((i + j) % 2 == 1) b[i][j] += x * x * x * x;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // 2 3 5 7 11 13
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
