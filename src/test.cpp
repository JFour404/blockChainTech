#include "header.h"

void testavimas (){
    cout << "\nVykdomas testavimas.\n";
    firstFaze();
    secondFaze();

}

void firstFaze(){
    vector <string> firstFazeFiles = {"onlyA.txt", "onlyB.txt", "2kRndA.txt", "2kRndB.txt", "1kS_diff1.txt", "1kS_diff2.txt"};
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

