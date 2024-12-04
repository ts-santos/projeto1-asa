#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

bool equationOp(int y, int x, vector<vector<int>> table, int tsize) {
    for (int i = 1; i <= tsize; i++) {
        if (table[i][x] == y) {
            return true;
        }
    }
    return false;
}

string putParenthesis(vector<vector<int>> table, vector<int> sequence, int tsize, int ssize, int *state) {

    int x = sequence[ssize];
    string s;
    if (*state == 2) {
        *state = 1;
        return "(" + putParenthesis(table, sequence, tsize, ssize, state) + ")";
    }
    if (equationOp(sequence[ssize + 1], x, table, tsize)) {
        s = "(" + putParenthesis(table, sequence, tsize, ssize-1, state) + ") " + to_string(x);
        return s;
    } else if (ssize > 1) {
        s = "(" + putParenthesis(table, sequence, tsize, ssize-1, state) + " " + to_string(x) + ")";
        return  s;
    } else if (ssize == 1) {
        return to_string(x);
    }
    *state = 0;
    return "";
}

void storeData(
        vector<vector<int>> *table, int *n, 
        vector<int> *sequence, int *m, 
        int *goal
        ) {
    scanf("%d %d\n", n, m);


    string result;
    int inn, out, tsize, ssize, state;
    scanf("%d %d\n", &tsize, &ssize);
    vector<vector<int>> table(tsize + 1, vector<int>(tsize + 1));
    vector<int> sequence(ssize+2);
    for (out = 1; out <= tsize; out++)
        for (inn = 1; inn <= tsize; inn++) 
            scanf("%d", &table[out][inn]);
    for (out = 1; out <= ssize + 1; out++) 
        scanf("%d", &sequence[out]);
}


int main () {
    vector<vector<int>> table;
    vector<int> sequence;
    int n, m, goal;

    storeData(&table, &n, &sequence, &m, &goal);
    


    state = 2;
    result = putParenthesis(table, sequence, tsize, ssize, &state);
    cout << state << endl;
    if (state == 1) cout << result[1] << endl;

    return 0;
}

