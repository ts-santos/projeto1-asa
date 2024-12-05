#include <iostream>
#include <vector>

using namespace std;

int main () {
    int m, o;
    scanf("%d\n", &m);
    o = m*m - 1;
    vector<int> lista(o);
    cout << o << endl;

    for (int i = 0; i < o; i++) {
        cout << lista[i];
    }
    cout << endl;

    return 0;
}

