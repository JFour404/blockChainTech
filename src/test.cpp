#include "header.h"

void testavimas (){
    cout << "\nVykdomas testavimas.\n";
    firstFaze();


}

void firstFaze(){
    vector <string> firstFazeFiles = {"onlyA.txt", "onlyB.txt", "2kRndA.txt", "2kRndB.txt", "1kS_diff1.txt", "1kS_diff2.txt"};
    string text;
    string rezFile = "1stFaze.txt";
    
    cout << "1st phase\n";
    ofstream out_r("../data/" + rezFile);  
    out_r << "*1 FAZES TESTAVIMO REZULTATAI.*\n";
    out_r << "| Input | Hexabits | Hash |\n";
    for (int i = 0; i < firstFazeFiles.size(); i++){
        for (int j = 0; j < 2; j++){
            string file = firstFazeFiles[i];
            text = readFile("../data/" + file);
            string hexHash = hexHashNo1(text);
            out_r << "| " << firstFazeFiles[i] << " | " << hexHash.size() << " |"
                << hexHash << " |\n";   
        }
        
    }
    
    out_r.close();
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

