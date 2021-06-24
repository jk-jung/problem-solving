#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int s = 0, k;
        for (int i = 0; i < n; i++) {
            cin >> k;
            s += k;
        }
        int r = 0;
        if (s < n) r = 1;
        else if(s > n) r = s - n;
        cout << r << endl;
    }
}
