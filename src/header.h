#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>
#include <limits>
#include <chrono>
#include <list>
#include <deque>
#include <filesystem>
#include <bitset>
#include <locale>
#include <codecvt>
#include <unordered_map>

using std::string;
using std::cout;
using std::cin;
using std::stoi;
using std::left;
using std::right;
using std::fixed;
using std::setw;
using std::setprecision;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::bernoulli_distribution;
using std::vector;
using std::isspace;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::ofstream;
using std::sort;
using std::runtime_error;
using std::exception;
using std::cerr;
using std::to_string;
using std::count_if;
using std::isdigit;
using std::list;
using std::advance;
using std::deque;
using std::remove_if;
using std::istream;
using std::getline;
using std::bitset;

string askCommand (int select);
string fileSelect ();
string readFile(string failas);
string readFileByLine(string failas, int lineNum);

vector<int> hashNo1(string text);
string hexHashNo1(string text);
void baseHash (vector<int>& eulerisBi);
string binaryToHex(vector <int> eulerisBi);

vector <int> bitsGen (unsigned int seed);
vector<int> sequenceGen (unsigned int seed);
wint_t seedGen (char symbol);
void shiftRight (vector<int>& hash, int seq);
vector <int> hashTornado (vector<int> prevHash, vector<int> newHash);

void testavimas ();
void firstFaze();
void secondFaze();
void thirdFaze();
void fourthFaze();
void writeTestRez(string rezFile, vector<string> firstFazeFiles, vector<string> firstFazeRezHex);
void genRandom();
void poruGen();
void poruGenSimilar();
void findCollisions(string filename);