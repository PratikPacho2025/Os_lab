int main() {
    int np;       
    int nf;        
    int pagesize; 
    int LA;        
    int offset;    
    int framenum;  
    int PA;        
    int pagenum;   

    cout << "Enter number of pages (np): ";
    cin >> np;

    cout << "Enter number of frames (nf): ";
    cin >> nf;

    cout << "Enter page size: ";
    cin >> pagesize;

    cout << "Enter Logical Address (LA): ";
    cin >> LA;

    
    int *pagetable = (int*)calloc(np, sizeof(int));

    cout << "\nEnter page table values:\n";
    for (int i = 0; i < np; i++) {
        cout << "Frame for page " << i << ": ";
        cin >> pagetable[i];
    }

    pagenum = LA / pagesize;
    offset  = LA % pagesize;

    framenum = pagetable[pagenum];

    PA = (framenum * pagesize) + offset;

    cout << "\n--- Details ---\n";
    cout << "Logical Address   : " << LA << endl;
    cout << "Physical Address  : " << PA << endl;
    cout << "Page Number       : " << pagenum << endl;
    cout << "Frame Number      : " << framenum << endl;
    cout << "Offset            : " << offset << endl;

    free(pagetable); 
    return 0;
}
