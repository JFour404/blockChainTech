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
        if (!(cin >> input)||(input!="/1"&&input!="/2"&&input!="/3"&&input!="/4"&&input!="/5"&&input!="/6"&&input!="/7"&&input!="/e")){
            cout << "Neteisinga ivestis. Prasome ivesti is naujo" << std::endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            } else break;
        } 
    }
    if (select==3){
        while(1){
        if (!(cin >> input)||(input!="/1"&&input!="/2"&&input!="/3"&&input!="/4"&&input!="/5"&&input!="/e")){
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

string readFile(string failas){
    char d;
    string text;

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

string readFileByLine(string failas, int lineNum){
    string line;
    int lineCount = 0;
    string text;

    ifstream open_f("../data/" + failas);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + failas);
    }

    while (getline(open_f, line) && lineCount < lineNum) {
        text += line + "\n";
        lineCount++;
    }

    open_f.close();
    return text;
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

void poruGen() {
    string fileName = "100kPoru.txt";

    cout << "Generuojamos atsitiktines poros.\n";

    ofstream open_f("../data/"+fileName);
    if (!open_f.is_open()) {
        cout << "Failas nerastas arba nepavyko atidaryti." << fileName << endl;
        return;
    }

    srand(time(NULL));
    vector<int> lenght = {10, 100, 500, 1000};
    for (int i=0; i<4; i++){
        int tempLenght = lenght[i];
        for (int j=0; j<25000; j++){
            for (int k=0; k<2; k++){
                for (int i = 0; i < tempLenght; i++) {
                char symbol = rand() % 25 + 'a';
                open_f << symbol;
                }
                if (k==0) open_f << " ";
            }
            open_f << endl;
        }
    }

    open_f.close();
    cout << "Failas: " << fileName << " sukurtas.\n";
}

void poruGenSimilar() {
    string fileName = "100kPoruPanasiu.txt";

    cout << "Generuojamos atsitiktines panasios poros.\n";

    ofstream open_f("../data/"+fileName);
    if (!open_f.is_open()) {
        cout << "Failas nerastas arba nepavyko atidaryti." << fileName << endl;
        return;
    }

    srand(time(NULL));
    vector<int> lenght = {10, 100, 500, 1000};
    for (int i=0; i<4; i++){
        int tempLenght = lenght[i];
        for (int j=0; j<25000; j++){
            string temp = "";
            for (int i = 0; i < tempLenght; i++) {
            char symbol = rand() % 25 + 'a';
            temp = temp + symbol;
            }
            open_f << temp <<" ";
            int randomChange = rand() % (tempLenght);
            
            char symbol;
            do {
                symbol = rand() % 25 + 'a';
            } while (temp[randomChange] == symbol);
            temp[randomChange] = symbol;
            
            open_f << temp << endl;
        }
    }

    open_f.close();
    cout << "Failas: " << fileName << " sukurtas.\n";
}

