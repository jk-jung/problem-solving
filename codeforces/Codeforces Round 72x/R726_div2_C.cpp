#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

int h[200005], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)cin >> h[i];
        sort(h, h + n);
        int diff = h[1] - h[0];
        for (int i = 1; i < n; i++)
            diff = min(diff, h[i] - h[i - 1]);

        for (int i = 1; i < n; i++) {
            if (h[i] - h[i - 1] == diff) {
                cout << h[i - 1];
                for (int j = i + 1; j < n; j++) cout << " " << h[j];
                for (int j = 0; j < i - 1; j++)cout << " " << h[j];

                cout << " " << h[i] << endl;
                break;
            }
        }
    }
}
