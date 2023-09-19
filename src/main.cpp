#include "header.h"

int main (){
//-------Kintamieji---------
    string inputType;
    string text;
//--------------------------
    cout << "Input'a nuskaityti is failo (f) ar komandines eilutes (k)?\n";
    inputType = askCommand(0);

//--------------------------
    if (inputType == "f") {
        system("cd ..\\data\\ && dir /b | findstr \\.txt$");
        text = readFile();
    } else
    if (inputType == "k") {
        //readCmd();
    } else {
        cout << "Error: netinkamai pasirinktas inputas" << endl;
    }


    return 0;
}

