#include <iostream>
#include <vector>
using namespace std;

int main() {
    int np, nb;

    cout << "Enter number of processes: ";
    cin >> np;
           
    cout << "Enter number of blocks: ";
    cin >> nb;

    vector<int> process(np);
    vector<int> block(nb);
    vector<int> allocation(np, -1);

    cout << "Enter process sizes:\n";
    for(int i = 0; i < np; i++) {
        cin >> process[i];
    }

    cout << "Enter block sizes:\n";
    for(int i = 0; i < nb; i++) {
        cin >> block[i];
    }

    for(int i = 0; i < np; i++) {
        for(int j = 0; j < nb; j++) {
            if(block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    cout << "\nProcess\tSize\tBlock\n";
    for(int i = 0; i < np; i++) {
        cout << i+1 << "\t" << process[i] << "\t";

        if(allocation[i] != -1)
            cout << allocation[i]+1;
        else
            cout << "Not Allocated";

        cout << endl;
    }

    return 0;
}