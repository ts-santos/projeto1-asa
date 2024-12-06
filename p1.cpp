#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, goal, found = -1;
vector<vector<vector<vector<int>>>> rtable;
vector<vector<int>> table;
vector<int> sequence; 

void storeData();
void showData();
void fillCell(int i, int j, int d);
string printSequence(vector<int> head, int i, int j);

int main () {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    storeData();

    
    //construct table of results
    for (int d = 1; d < m; d++) {
        int i = 0;
        int j = d;
        while (j < m) {
            fillCell(i++, j++, d);
        }
    }
    //is result found -> print 1 else print 0
    cout << (found > -1) << endl;
    // print sequence w parenthesis function (recursive)
    showData();
    cout << printSequence(rtable[0][m-1][found], 0, m-1) << endl;

}

string printSequence(vector<int> head, int i, int j) {
    long unsigned k = 0;
    string left, right;
    vector<vector<int>> aux;
    if (i - j == 0) return "" + head[0];
    aux = vector<vector<int>>(rtable[i][head[1]].size(), vector<int>(5));
    aux = rtable[i][head[1]];
    for (; k < aux.size() && head[3] != aux[k][0]; k++);
    left = printSequence(aux[k], i, head[1]);
    aux = vector<vector<int>>(rtable[head[2]][j].size(), vector<int>(5));
    aux = rtable[head[2]][j];
    for (; k < aux.size() && head[4] != aux[k][0]; k++);
    right = printSequence(aux[k], head[1], j);
    return "(" + left + " " + right + ")";
}

bool checkResult(int v, int i, int j, int siz) {
    int counter = siz;
    while (counter-- != 0 && v != rtable[i][j][counter][0]);
    return counter == -1;
}

void fillCell(int i, int j, int d) {
    int siz = 0, value;
    for (int ncel = 0; ncel < j - i; ncel++) {
        vector<vector<int>> rc = vector<vector<int>>(1, vector<int>(5));
        rc = rtable[j-ncel][j];
        for (long unsigned rci = 0; rci < rc.size(); rci++) {
            vector<vector<int>> lc = vector<vector<int>>(1, vector<int>(5));
            lc = rtable[i][i+(d - 1 - ncel)]; // d - 1 - ncel (progressão inversa a ncel)
            for (long unsigned lci = 0; lci < lc.size(); lci++) {
                value = table[lc[lci][0]-1][rc[rci][0]-1];
                if (checkResult(value, i, j, siz)) {
                    siz++;
                    rtable[i][j].resize(siz, vector<int>(3));
                    rtable[i][j][siz-1][0] = value;
                    rtable[i][j][siz-1][1] = i+(d - 1 - ncel);
                    rtable[i][j][siz-1][2] = j-ncel;
                    rtable[i][j][siz-1][3] = lc[lci][0];
                    rtable[i][j][siz-1][4] = rc[rci][0];
                    if (d == m-1 && value == goal) {
                        found = siz-1;
                        return;
                    }
                }
            }
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
          (1, vector<int>(5))));
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
                cout << (j == m-1 ? "(" : "") << rtable[i][j][k][0] << " ";
            }
        }
        cout << endl;
    } 
}

