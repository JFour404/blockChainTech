#include "header.h"

void testavimas (){
    cout << "\nVykdomas testavimas.\n";

    
}

void genRandom() {
    string fileName;
    int num;
    cout << "Iveskite failo pavadinima: ";
    cin >> fileName;
    cout << "Iveskite simboliu skaiciu: ";
    cin >> num;
    
    ofstream open_f("../data/"+fileName);
    if (!open_f.is_open()) {
        cout << "Failas nerastas arba nepavyko atidaryti." << fileName << endl;
        return;
    }
    
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        char symbol = rand() % 95 + 32;
        open_f << symbol;
    }
    
    open_f.close();
    cout << "Failas " << fileName << " sukurtas su " << num << " atsitiktiniu simboliu." << endl;
}