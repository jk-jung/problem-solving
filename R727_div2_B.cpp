#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

char s[100005];
int v[100005];

int main() {
    int n, q;

    cin >> n >> q >> s;
    for (int i=1;i<=n;i++)
        v[i] = v[i-1] + s[i-1] - 'a' + 1;

    while (q--) {
        int s, e;
        scanf("%d%d", &s, &e);
        printf("%d\n", v[e] - v[s-1]);
    }

}
