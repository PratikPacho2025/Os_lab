#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> available(m);

    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter Max Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter Available Resources:\n";
    for(int i = 0; i < m; i++) {
        cin >> available[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    vector<bool> finish(n, false);
    vector<int> safeSequence;
    vector<int> work = available;

    int count = 0;

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool possible = true;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }

                if(possible) {
                    for(int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if(!found) {
            break;
        }
    }

    if(count == n) {
        cout << "System is in SAFE state\n";
        cout << "Safe Sequence: ";

        for(int i = 0; i < safeSequence.size(); i++) {
            cout << "P" << safeSequence[i];

            if(i != safeSequence.size() - 1) {
                cout << " -> ";
            }
        }
    }
    else {
        cout << "System is in UNSAFE state";
    }

    return 0;
}