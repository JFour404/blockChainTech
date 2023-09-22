#include "header.h"

string askCommand (int select) {
    string input;
    if (select==0){
        while(1){
        if (!(cin >> input)||(input!="f"&&input!="k")){
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } else break;
        } 
    }
    if (select==1){
        while(1){
        if (!(cin >> input)||(input!="y"&&input!="n")){
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } else break;
        } 
    }
    if (select==2){
        while(1){
        if (!(cin >> input)||(input!="/1"&&input!="/2"&&input!="/3"&&input!="/4"&&input!="/e")){
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } else break;
        } 
    }
    return input;
}

string fileSelect () {
    string failas;
    cout << "Prieinami failai: \n";
    int result = system("cd ..\\data\\ && dir /b | findstr \\.txt$");
    while (1) {
        cout << "Iveskite failo pavadinima is saraso, is kurio norite nuskaityti duomenis: \n";
        cin >> failas;
        try {
            ifstream open_f("../data/" + failas);
            if (!open_f) throw runtime_error("Failas nerastas arba nepavyko atidaryti.");
            break;
        }
        catch (exception const& e) {
            cerr << "Klaida: " << e.what() << endl; 
        }                     
    }
    return failas;
}

string readFile(){
    char d;
    string text;
    string failas;
    failas = fileSelect();

    ifstream open_f("../data/" + failas);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + failas);
    }

    while (open_f >> std::noskipws >> d){
        text = text + d;
    }

    open_f.close();
    return text;
}


