#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp    make_pair
#define pb    push_back
#define ab(x) (((x)<0)?-(x):(x))

int n, m;
char a[55][55];
char b[55][55];

bool color(int k) {
    memcpy(b, a, sizeof(b));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char t = (i + j) % 2 == k ? 'R' : 'W';
            if (b[i][j] != '.' && b[i][j] != t) return false;
            b[i][j] = t;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)cin >> a[i];

        if (color(0) || color(1)) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)cout << b[i] << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
