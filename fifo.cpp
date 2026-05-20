#include<iostream>
#include<vector>

using namespace std;

int main() {
    int index = 0;
    int hit = 0;
    int fault = 0;
    int np, nf;

    cout << "Enter number of pages: ";
    cin >> np;

    cout << "Enter number of frames: ";
    cin >> nf;

    vector<int> pages(np);
    vector<int> memory(nf, -1);

    cout << "\nEnter reference string:\n";
    for(int i = 0; i < np; i++) {
        cout << "Reference " << i + 1 << ": ";
        cin >> pages[i];
    }

    for(int i = 0; i < np; i++) {
        bool found = false;

        for(int j = 0; j < nf; j++) {
            if(memory[j] == pages[i]) {
                hit++;
                found = true;
                cout << "Page " << pages[i] << " -> Hit" << endl;
                break;
            }
        }

        if(!found) {
            memory[index] = pages[i];
            cout << "Page " << pages[i] << " -> Fault" << endl;
            index = (index + 1) % nf;
            fault++;
        }
    }

    cout << "\nFinal Output\n";
    cout << "Total Hits: " << hit << endl;
    cout << "Hit Ratio: " << double(hit) / np << endl;
    cout << "Total Faults: " << fault << endl;
    cout << "Fault Ratio: " << double(fault) / np << endl;

    return 0;
}