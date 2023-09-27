#include "header.h"

void testavimas (){
    cout << "Testavimo funkcijos:\n";
    cout << "/0     Pilnas testavimas\n";
    cout << "/1     1 faze\n";
    cout << "/2     2 faze\n";
    cout << "/3     3 faze\n";
    cout << "/4     4 faze\n";
    cout << "/e     exit\n";
    cout << "\nPasirinkite tesavimo faze: ";
    string faze = askCommand(3);
    
    if (faze != "/e"){
        cout << "\nVykdomas testavimas.\n";
    } 
    if (faze == "/0"){
        firstFaze();
        secondFaze();
        thirdFaze();
        fourthFaze();

    } else if (faze == "/1"){
        firstFaze();

    } else if (faze == "/2"){
        secondFaze();

    } else if (faze == "/3"){
        thirdFaze();

    } else if (faze == "/4"){
        fourthFaze();

    }
    
}

void firstFaze(){
    vector <string> firstFazeFiles = {"onlyA.txt", "onlyB.txt", "2kRndA.txt", "2kRndB.txt", "1kS_diff1.txt", "1kS_diff2.txt", "empty.txt"};
    string text;
    string rezFile = "1stFaze.txt";
    
    cout << "1st phase\n";
    ofstream out_r("../data/" + rezFile);  
    out_r << "*1 FAZES TESTAVIMO REZULTATAI.*\n";
    out_r << "| Input | Hex size | Hash |\n";
    
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

void secondFaze(){
    auto start = std::chrono::high_resolution_clock::time_point();
    auto end = std::chrono::high_resolution_clock::time_point();
    std::chrono::duration<double> diff = end-start;  

    string file = "konstitucija.txt";
    string text;
    string rezFile = "2ndFaze.txt";
    vector <double> avgTime;

    cout << "2nd phase\n";
    ofstream out_r("../data/" + rezFile);
    out_r << "*2 FAZĖS TESTAVIMO REZULTATAI.*\n";
    out_r << "| Input size | Hashing time | Increase in time |\n";
    out_r << "| ---------- | ------------ | ---------------- |\n";

    int l = 0;
    for (int i = 1; i < 790; i=i*2){
        vector <std::chrono::duration<double>> tempTime;
        text = readFileByLine("../data/" + file, i);
        
        for (int j=0; j<5; j++){
            start = std::chrono::high_resolution_clock::now();
            string hexHash = hexHashNo1(text);
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            tempTime.push_back(diff);
        }

        std::chrono::duration<double> tempSum = std::chrono::duration<double>::zero();
        for (int k = 0; k < tempTime.size(); k++){
            tempSum += tempTime[k];
        }

        double timeInS = tempSum.count();
        double avgTimeInS = timeInS/5;
        avgTime.push_back(avgTimeInS);

        out_r << "| " << i  << " | " ;
        out_r << fixed << setprecision(6) << avgTime[l] << " | ";
        if (l != 0){
            out_r << fixed << setprecision(2) << (avgTime[l] / avgTime [l-1]) * 100 - 100 << " %" << " |\n";
        } else {
            out_r << "Nan" << " |\n";
        }
        
        l++;
    }
    
    out_r.close();
}

void thirdFaze() {
    string file = "100kPoru.txt";
    string text;
    string rezFile = "3rdFaze.txt";
    string hashFile = "200kHash.txt";

    cout << "3rd phase\n";
    ofstream out_r("../data/" + rezFile);
    ofstream out_hash("../data/" + hashFile);
    out_r << "*3 FAZĖS TESTAVIMO REZULTATAI.*\n";
    out_r << "| Eilutės numeris | Hex hash |\n";
    out_r << "| --------------- | -------- |\n";

    string word1;
    string word2;
    string hexHash1;
    string hexHash2;

    ifstream open_f("../data/" + file);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + file);
    }    
    
    bool pasikartojo = 0;
    for (int i = 0; i < 100000; i++){
        open_f >> word1;
        open_f >> word2;
        hexHash1 = hexHashNo1(word1);
        hexHash2 = hexHashNo1(word2);
        out_hash << hexHash1 << endl;
        out_hash << hexHash2 << endl;

        if (hexHash1 == hexHash2){
            pasikartojo = 1;
            out_r << "| " << i << " | " << hexHash1 << " |\n";
        }
    }
    open_f.close();
    out_hash.close();

    if (pasikartojo == 0){
        out_r << endl;
        out_r << "Pasikartojančių hash'ų porų nerasta.\n";
    }
    
    out_r.close();

    findCollisions("200kHash.txt");
}

void fourthFaze() {
    int hashNum = 100000;
    string file = "100kPoruPanasiu.txt";
    string text;
    string rezFile = "4thFaze.txt";

    cout << "4th phase\n";
    ofstream out_r("../data/" + rezFile);
    out_r << "*4 FAZĖS TESTAVIMO REZULTATAI.*\n";
    out_r << "| Matavimas | Bit hash | Hex hash |\n";
    out_r << "| --------- | -------- | -------- |\n";

    string word1;
    string word2;
    vector <int> biHash1;
    vector <int> biHash2;
    string hexHash1;
    string hexHash2;
    int sameBit = 0, minBit = 256, maxBit = 0;
    int sameHex = 0, minHex = 64, maxHex = 0;
    double avgBit = 0, avgHex = 0;

    ifstream open_f("../data/" + file);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + file);
    }    
    
    bool pasikartojo = 0;
    int skaitiklis = 0;
    for (int i = 0; i < hashNum; i++){
        if (skaitiklis==25000) {
            cout << "Apdorota " << i << " hash'u." << endl;
            skaitiklis = 0;
        }
        skaitiklis++;

        open_f >> word1;
        open_f >> word2;
        biHash1 = hashNo1(word1);
        biHash2 = hashNo1(word2);
        hexHash1 = binaryToHex(biHash1);
        hexHash2 = binaryToHex(biHash2);

        for (int k=0; k < biHash1.size(); k++){
            if (biHash1[k]==biHash2[k]) sameBit++;
        }
        for (int k=0; k < hexHash1.size(); k++){
            if (hexHash1[k]==hexHash2[k]) sameHex++;
        }
        if (sameBit < minBit) minBit = sameBit;
        if (sameHex < minHex) minHex = sameHex;
        if (sameBit > maxBit) maxBit = sameBit;
        if (sameHex > maxHex) maxHex = sameHex;        
        avgBit += sameBit;
        avgHex += sameHex;

        sameBit = 0;
        sameHex = 0;
    }
    open_f.close();

    double minBitPrec = (static_cast<double>(minBit)/256)*100;
    double minHexPrec = (static_cast<double>(minHex)/64)*100;
    double maxBitPrec = (static_cast<double>(maxBit)/256)*100;
    double maxHexPrec = (static_cast<double>(maxHex)/64)*100;
    double avgBitPrec = (avgBit/(hashNum*256))*100;
    double avgHexPrec = (avgHex/(hashNum*64))*100;

    out_r << "| Min | " << fixed << setprecision(2) << minBitPrec << " % | " << minHexPrec << " % |\n";
    out_r << "| Max | " << fixed << setprecision(2) << maxBitPrec << " % | " << maxHexPrec << " % |\n";
    out_r << "| Avg | " << fixed << setprecision(2) << avgBitPrec << " % | " << avgHexPrec << " % |\n";

    out_r.close();
}

void findCollisions(string file) {
    ifstream open_f("../data/" + file);
    std::unordered_map<string, int> seen;
    string line;
    int lineNumber = 0;
    bool collision = 0;
    while (getline(open_f, line)) {
        lineNumber++;
        if (seen.find(line) != seen.end()) {
            collision = 1;
            cout << "Eilute: " << lineNumber << " kartojasi su eilute " << seen[line] << ": " << line << endl;
        } else {
            seen[line] = lineNumber;
        }
    }
    open_f.close();

    if (collision==0){
        cout << "Pasikartojanciu hash'u nerasta.\n";
    }
}
