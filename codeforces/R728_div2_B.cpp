#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

int n;
int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        int r = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            int m = a[i] - i % a[i];
            if (m == 0) m = a[i];

            for (int j = m; j < i; j += a[i])
                if ((ll)a[i] * a[j] == i + j) r += 1;

        }

        cout << r << endl;

    }
}

