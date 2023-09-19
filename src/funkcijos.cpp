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
    string text;
    string line;
    string failas;
    failas = fileSelect();
    
    ifstream open_f("../data/" + failas);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + failas);
    }

    while (getline(open_f, line)) {
        text += line + "\n";
    }

    open_f.close();

    std::cout << "File Contents:\n" << text << std::endl;
    return text;
}

string readCmd(){

}