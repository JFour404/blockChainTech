#include "header.h"

void hashNo1(string text){
    vector <int> eulerisBi;
    stringstream hash;
    baseHash(eulerisBi);
    binaryToHex (eulerisBi);
}

void baseHash (vector<int>& eulerisBi) {
    char skc;
    string konst = "e.txt";
    
    ifstream open_f("../data/" + konst);
    if (!open_f) throw runtime_error("Failas nerastas arba nepavyko atidaryti.");

    while (open_f.get(skc)) {
        if (isdigit(skc)) {
            int intSkc = skc - '0';
            if (intSkc >= 5) eulerisBi.push_back(1);
            else eulerisBi.push_back(0);
        }
    }

    open_f.close();
    cout << "Binary euler: ";
    for (int d : eulerisBi) {
        cout << d;
    }
    cout << endl;   
}

void binaryToHex(vector <int> eulerisBi) {
    int i = 0;
    string temp1;
    string temp4 = "";
    int tempInt;
    string tempHex;

    for (int d : eulerisBi) {
        if (i==3) {
            temp1 = to_string(d);
            temp4 += temp1;
            
            tempInt = stoi(temp4);

                switch (tempInt) {
                    case 0:
                        tempHex += "0";
                        break;
                    case 1:
                        tempHex += "1";
                        break;
                    case 10:
                        tempHex += "2";
                        break;
                    case 11:
                        tempHex += "3";
                        break;
                    case 100:
                        tempHex += "4";
                        break;
                    case 101:
                        tempHex += "5";
                        break;
                    case 110:
                        tempHex += "6";
                        break;
                    case 111:
                        tempHex += "7";
                        break;
                    case 1000:
                        tempHex += "8";
                        break;
                    case 1001:
                        tempHex += "9";
                        break;
                    case 1010:
                        tempHex += "a";
                        break;
                    case 1011:
                        tempHex += "b";
                        break;
                    case 1100:
                        tempHex += "c";
                        break;
                    case 1101:
                        tempHex += "d";
                        break;
                    case 1110:
                        tempHex += "e";
                        break;
                    case 1111:
                        tempHex += "f";
                        break;
                    default:
                        tempHex += "0";
                
                }

            temp4 = "";
            i = 0;
        } else {
            temp1 = to_string(d);
            temp4 += temp1;
            i++;
        } 
    } 

    cout << "Hexbit euler: " << tempHex;

}
