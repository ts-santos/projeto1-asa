#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int n, m, goal;
vector<vector<int>> *table;
list<int> *sequence; 

void storeData();
int goalCheck(vector<vector<int>> *table, int n, int j, int goal, vector<int> *iToCheck);

int main () {}

void storeData() {
    cin >> n >> m;
    table = new vector<vector<int>>(n, vector<int>(n));      //eu tentei colocar *table = new vector<vector<int>>(n, vector<int>(n)); mas não deu certo
    sequence = new list<int>(m);                            //eu tentei colocar *sequence = new list<int>(m); mas não deu certo
    int value, num;                                         //mas tambem nao tenho a certeza se era suposto fazer isso

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> value;  //value = (*table)[i][j];
            table[i][j].push_back(value); //stores the value in the table
        }
        cin.ignore();
    } for (int i = 0; i < m; i++) {
        cin >> num;  //num = (*sequence)[i];
        sequence[i].push_back(num);  //stores one of the numbers in the sequence

    }
    
}

int goalCheck(vector<vector<int>> *table, int n, int j, int goal, vector<int> *iToCheck) {
    int samei = 0, diffi = n;
    list<int> *iToCheck = new list<int>(n);
    for (int i = 0; i < n; i++) {
        if ((*table)[i][j-1] == goal) {
            (*iToCheck).push_back(i);    //if i equals goal, it is stored in the beggining of the list          //consegui alterar isto
        
        //este nao sei como fazer, tentei utilizar o insert mas nao consegui desta forma: (*iToCheck).insert(n--, i);

        } else {
            (*iToCheck)[--diffi] = i;  //stores in the end i if it doesn't equal goal
        }
    }
    return samei;    
}


