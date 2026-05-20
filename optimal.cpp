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
            int replacement_index = -1;
            int farthest = i+1;
           //memory is emoty so fill it out 
            for(int j=0;j<nf;j++){
                      if(memory[j]==-1){
                                 replacement_index = j;
                                 break;
                      }
            }
            if(replacement_index == -1){
                      farthest = -1; 

                      for(int j=0;j<nf;j++){
                                 int k;
                                 for(k=i+1;k<np;k++){
                                            if(memory[j]==pages[k]){
                                                       if(k>farthest){
                                                                  farthest = k;
                                                                  replacement_index = j;
                                                       }
                                                       break;
                                            }
                                 }
                                 if(k == np){
                                            replacement_index = j;
                                            break;
                                 }         
                      }        
            }

            memory[replacement_index] = pages[i];
            fault++;

            cout << "Page " << pages[i] << " -> Fault" << endl;
        }
    }

    cout << "\nFinal Output\n";
    cout << "Total Hits: " << hit << endl;
    cout << "Hit Ratio: " << double(hit) / np << endl;
    cout << "Total Faults: " << fault << endl;
    cout << "Fault Ratio: " << double(fault) / np << endl;

    return 0;
}