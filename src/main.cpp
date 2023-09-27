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
    cout << "/2     hash generavimas (cmd)\n";
    cout << "/3     hash generavimas (file)\n";
    cout << "/4     atsitiktiniu failu kurimas\n";
    cout << "/5     100k eiluciu generavimas\n";
    cout << "/6     find collisions (200kHash.txt)\n";
    cout << "/7     100k panasiu eiluciu generavimas\n";
    cout << "/e     exit\n";

    while (1){
        cout << "\nPasirinkite programos funkcija: ";
        spec = askCommand(2);
        
        if (spec == "/1") {
            testavimas();
        
        } else if (spec == "/2") {
            cout << "Iveskite teksta: " ;
            cin >> text;
            cout << "Hash: " << hexHashNo1(text) << endl;            
            
        } else if (spec == "/3") {
            string failas;
            failas = fileSelect();
            text = readFile(failas);
            cout << "Hash: " << hexHashNo1(text) << endl;
        
        } else if (spec == "/4") {
            genRandom();
        
        } else if (spec == "/5") {
            poruGen();
        
        } else if (spec == "/6") {
            findCollisions("200kHash.txt");
        
        } else if (spec == "/7") {
            poruGenSimilar();
        
        } else if (spec == "/e") {
            return 0;
        }
    }
           
    return 0;
}

