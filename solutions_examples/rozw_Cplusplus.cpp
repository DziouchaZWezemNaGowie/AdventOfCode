#include <iostream>
#include <fstream> // pliki
#include <vector>
#include <string>
#include <sstream> // żeby wyciągnąć int ze stringa
#include <algorithm> // żeby mieć sort, count

using namespace std;

int main() {
    ifstream dane("Dane/1.txt");
    string line;
    vector<int> lewa, prawa;
    int x, y;
    while (getline(dane, line)) {
        istringstream iss(line);
        iss >> x;
        iss >> y;
        lewa.push_back(x);
        prawa.push_back(y);
    }

    vector<int> lewa_sorted = lewa;
    vector<int> prawa_sorted = prawa;

    sort(lewa_sorted.begin(), lewa_sorted.end());
    sort(prawa_sorted.begin(), prawa_sorted.end());

    int odl = 0, i;

    for (i=0; i<lewa_sorted.size(); i++) {
        odl += abs(lewa_sorted[i] - prawa_sorted[i]);
    }

    cout << odl << endl;

    int podob = 0;

    for (i=0; i<lewa.size(); i++) {
        podob += lewa[i]*count(prawa.begin(), prawa.end(), lewa[i]);
    }

    cout << podob << endl;

    dane.close();
    
}
