#include "header.h"

int main (){
//-------Kintamieji---------
    string inputType;
    string text;
    int hash;
//--------------------------
    cout << "Input'a nuskaityti is failo (f) ar komandines eilutes (k)?\n";
    inputType = askCommand(0);

//--------------------------
    if (inputType == "f") {
        text = readFile();
    } else
    if (inputType == "k") {
        cout << "Iveskite teksta: " ;
        cin >> text;
    } else {
        cout << "Error: netinkamai pasirinktas inputas" << endl;
    }

    hashNo1 (text);
    return 0;
}

