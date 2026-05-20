#include <iostream>
#include <vector>

using namespace std;

int main() {
    int hit = 0, fault = 0;
    int np, nf;

    cout << "Enter number of pages: ";
    cin >> np;

    cout << "Enter number of frames: ";
    cin >> nf;

    vector<int> pages(np);
    vector<int> memory(nf, -1);

    cout << "\nEnter reference string:\n";
    for(int i = 0; i < np; i++) {
        cin >> pages[i];
    }

    for(int i = 0; i < np; i++) {
        bool found = false;

        // Hit check
        for(int j = 0; j < nf; j++) {
            if(memory[j] == pages[i]) {
                hit++;
                found = true;
                cout << "Page " << pages[i] << " -> Hit\n";
                break;
            }
        }

        if(!found) {
            int replaceIndex = -1;
            int leastRecent = i;

            // Empty frame check
            for(int j = 0; j < nf; j++) {
                if(memory[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // Apply LRU
            if(replaceIndex == -1) {
                leastRecent = i;

                for(int j = 0; j < nf; j++) {
                    int k;

                    for(k = i - 1; k >= 0; k--) {
                        if(memory[j] == pages[k]) {
                            if(k < leastRecent) {
                                leastRecent = k;
                                replaceIndex = j;
                            }
                            break;
                        }
                    }

                    if(k < 0) {
                        replaceIndex = j;
                        break;
                    }
                }
            }

            memory[replaceIndex] = pages[i];
            fault++;

            cout << "Page " << pages[i] << " -> Fault\n";
        }
    }

    cout << "\nTotal Hits: " << hit << endl;
    cout << "Hit Ratio: " << double(hit)/np << endl;
    cout << "Total Faults: " << fault << endl;
    cout << "Fault Ratio: " << double(fault)/np << endl;

    return 0;
}