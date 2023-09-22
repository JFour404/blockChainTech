#include "header.h"

int main (){
//-------Kintamieji---------
    string inputType;
    string text;
    int hash;
    string spec = "default";
//--------------------------
    cout << "\nPagrindines funkcijos:\n";
    cout << "/1     hashF testavimas\n";
    cout << "/2     atsitiktiniu failu kurimas\n";
    cout << "/3     hash generavimas (cmd)\n";
    cout << "/4     hash generavimas (file)\n";
    cout << "/e     exit\n";
    
    while (1){
        cout << "\nPasirinkite programos funkcija: ";
        spec = askCommand(2);
        
        if (spec == "/1") {
            testavimas();
        
        } else if (spec == "/2") {
            genRandom();
        
        } else if (spec == "/3") {
            cout << "Iveskite teksta: " ;
            cin >> text;
            cout << "Hash: " << hashNo1(text) << endl;
        
        } else if (spec == "/4") {
            text = readFile();
            cout << "Hash: " << hashNo1(text) << endl;
        
        } else if (spec == "/e") {
            return 0;
        }
    }
           
    return 0;
}

