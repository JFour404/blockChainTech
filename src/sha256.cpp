#include "header.h"

void compareSHA256(){
    compareTime();
    compareRandomness();
    cout << "Testavimas ivykdytas.\n";
}

string sha256(const string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    string result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        result += hash[i];
    }
    return result;
}

string bytesToHex(const string& bytes) {
    string hex;
    for (int i = 0; i < bytes.length(); i++) {
        char byte = bytes[i];
        char hexChars[3];
        sprintf(hexChars, "%02x", (unsigned char) byte);
        hex += hexChars;
    }
    return hex;
}

void compareTime(){
    auto start = std::chrono::high_resolution_clock::time_point();
    auto end = std::chrono::high_resolution_clock::time_point();
    std::chrono::duration<double> diff = end-start;  

    string file = "konstitucija.txt";
    string text;
    string rezFile = "compareExecTime.txt";
    vector <double> avgTime;
    vector <double> avgTimeSha;

    cout << "2nd phase\n";
    ofstream out_r("../data/" + rezFile);
    out_r << "*SHA256 ir hashF vykdymo laiko palyginimas.*\n";
    out_r << "| Input size | Hashing time (SHA256) | Hashing time (hashF) | hashF performace (kiek kartu leciau)|\n";
    out_r << "| ---------- | --------------------- | -------------------- | ----------------------------------- |\n";

    int l = 0;
    for (int i = 1; i < 790; i=i*2){
        text = readFileByLine("../data/" + file, i);
        
        std::chrono::duration<double> tempSum = std::chrono::duration<double>::zero();
        
        for (int j=0; j<5; j++){
            start = std::chrono::high_resolution_clock::now();
            string hexHash = hexHashNo1(text);
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            tempSum += diff;
        }

        double timeInS = tempSum.count();
        double avgTimeInS = timeInS/5;
        avgTime.push_back(avgTimeInS);

        std::chrono::duration<double> tempSumSha = std::chrono::duration<double>::zero();
        
        for (int j=0; j<5; j++){
            start = std::chrono::high_resolution_clock::now();
            string shaHash = sha256(text);
            end = std::chrono::high_resolution_clock::now();
            diff = end - start;
            tempSumSha += diff;
        }

        double timeShaInS = tempSumSha.count();
        double avgTimeShaInS = timeShaInS/5;
        avgTimeSha.push_back(avgTimeShaInS);


        out_r << "| " << i  << " | " ;
        out_r << fixed << setprecision(8) << avgTimeSha[l] << " | " << avgTime[l] << " | ";
        out_r << fixed << setprecision(2) << (avgTime[l] / avgTimeSha[l]) << " |\n";
        
        l++;
    }
    
    out_r << "\n\n";
    out_r.close();
}

void compareRandomness(){
    string word1, word2, myHash, shaHash, tempHash;
    int countRez = 0;
    vector <double> myHashHexDispersity(256, 0), shaHashHexDispersity(256, 0);  
    vector <double> myHashHexDispersityRatio, shaHashHexDispersityRatio;
    vector <char> sample = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int myHashCharCount = 0, shaHashCharCount = 0;
    string fileData = "100kPoruShort.txt";
    string fileRez = "compareRandomness.txt";

    poruGenShort();

    ifstream open_f("../data/" + fileData);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti " + fileData);
    }

    for (int i = 0; i < 100000; i++){
        open_f >> word1;
        open_f >> word2;
        myHash = hexHashNo1(word1);
        tempHash = sha256(word2);
        shaHash = bytesToHex(tempHash);
        for (char c: myHash){
            myHashHexDispersity[c]++;
            myHashCharCount++;
        } 
        for (char c: shaHash){
            shaHashHexDispersity[c]++;
            shaHashCharCount++;
        } 
    }
    open_f.close();
    
    

    if (myHashCharCount == 0) {
        throw runtime_error("myHashCharCount is zero");
    }
    if (shaHashCharCount == 0) {
        throw runtime_error("shaHashCharCount is zero");
    }
    for (char c : sample) {
        myHashHexDispersityRatio.push_back(static_cast<double>(myHashHexDispersity[c] / myHashCharCount));
        shaHashHexDispersityRatio.push_back(static_cast<double>(shaHashHexDispersity[c] / shaHashCharCount));
    }

    ofstream out_f("../data/" + fileRez);
    out_f << "*SHA256 ir hashF simboliu pasiskirstymas (ideal 6.25 %)*\n";
    out_f << " | Simbolis | SHA256 | hashF | Best result | \n";
    out_f << " | -------- | ------ | ----- | ----------- | \n";
    for (int i = 0; i < sample.size(); i++){
        out_f << " | " << sample[i] << " | ";
        out_f << fixed << setprecision(3) << shaHashHexDispersityRatio[i] * 100 << " % | ";
        out_f << fixed << setprecision(3) << myHashHexDispersityRatio[i] * 100 << " % | ";
        if (fabs(shaHashHexDispersityRatio[i] - 0.0625) < fabs(myHashHexDispersityRatio[i] - 0.0625)){
            out_f << " SHA256 | \n";
            countRez++;
        }
        else if (fabs(myHashHexDispersityRatio[i] - 0.0625) < fabs(shaHashHexDispersityRatio[i] - 0.0625)){
            out_f << " hashF | \n";
        } 
        else
            out_f << " draw | \n";
    }

    out_f << endl;
    if (countRez == 8) out_f << "Abu algoritmai pademonstravo panasu simboliu pasiskirstyma.\n";
    else if (countRez > 8){
        out_f << "Geresni rezultata parode: ";
        out_f << "SHA256 (rezultatu " << countRez << ":" << 16 - countRez << ")\n";
    } 
    else if (countRez < 8){
        out_f << "Geresni rezultata parode: ";
        out_f << "hashF (rezultatu " << countRez << ":" << 16 - countRez << ")\n";
    } 
    out_f.close();
}

void poruGenShort() {
    string fileName = "100kPoruShort.txt";

    cout << "Generuojamos atsitiktines poros.\n";

    ofstream open_f("../data/"+fileName);
    if (!open_f.is_open()) {
        cout << "Failas nerastas arba nepavyko atidaryti." << fileName << endl;
        return;
    }

    srand(time(NULL));
    vector<int> lenght = {10, 20, 30, 40};
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

void dispersityCalc(vector<int>& target, string hash) {

    for (char d: hash){
        target[d]++;
    }

}