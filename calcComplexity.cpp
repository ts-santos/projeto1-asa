#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n,m, o;
    scanf("%d %d\n", &n, &m);
    o = n * (n/2) * (m-2) + 1;
    vector<int> lista(o);
    cout << o << endl;

    for (int i = 0; i < o; i++) {
        cout << lista[i];
    }
    cout << endl;

    return 0;
}

