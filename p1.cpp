#include <iostream>
#include <vector>

using namespace std;

int n, m, goal;
vector<vector<vector<vector<int>>>> rtable;
vector<vector<int>> table;
vector<int> sequence; 

void storeData();
void showData();
void fillCell(int i, int j);

int main () {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    storeData();

    
    //construct table of results
    for (int d = 1; d < m; d++) {
        int i = 0;
        int j = d;
        while (j < m) {
            fillCell(i, j);
            j++; i++;
        }
    }
    //is result found -> print 1 else print 0
    // print sequence w parenthesis function (recursive)


    showData();
}

bool checkResult(int v, int i, int j, int siz) {
    while (siz-- != 0 && v != table[i][j][siz-1][0]);
    return siz == 0;
}

void fillCell(int i, int j) {
    int siz = 0, value;
    for (int ncel = 0; ncel < j - i; ncel++)
        for (vector<int>(3) rc: rtable[j-ncel][j])
            for (vector<int>(3) lc: rtable[i][i+ncel]) {
                value = table[rc[0]][lc[0]];
                if (checkResult(value, i, j, siz)) {
                    siz++;
                    rtable[i][j].resize(siz, vector<int>(3));
                    rtable[i][j][siz] = {value, i+ncel, j-ncel};
                }
            }
}

void storeData() {
    cin >> n; cin.ignore();
    cin >> m; cin.ignore();
    table = vector<vector<int>>(n, vector<int>(n));
    rtable = vector<vector<vector<vector<int>>>>
        (m, vector<vector<vector<int>>>
         (m, vector<vector<int>>
          (1, vector<int>(3))));
    sequence = vector<int>(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j]; cin.ignore();
        }
    } 

    for (int i = 0; i < m; i++) {
        cin >> sequence[i]; cin.ignore();
        rtable[i][i][0][0] = sequence[i];
    }

    cin >> goal;
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

    cout << endl << goal << endl << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (long unsigned k = 0; k < rtable[i][j].size(); k++) {
                cout << rtable[i][j][k][0] << " ";
            }
        }
        cout << endl;
    } 
}

