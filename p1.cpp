#include <iostream>
#include <vector>

using namespace std;

int n, m, goal;
vector<vector<int>> table;
vector<int> sequence; 

void storeData();
void showData();

int main () {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    storeData();
    showData();
}

void showData() {
    
    cout << n << " ";
    cout << m << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    } 

    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }

    cout << endl << goal << endl;

}

void storeData() {
    cin >> n; cin.ignore();
    cin >> m; cin.ignore();
    table = vector<vector<int>>(n, vector<int>(n));
    sequence = vector<int>(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j]; cin.ignore();
        }
    } 

    for (int i = 0; i < m; i++) {
        cin >> sequence[i]; cin.ignore();
    }

    cin >> goal;
}

