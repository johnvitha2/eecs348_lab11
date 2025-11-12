#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Matrix{

};

class Executive{
    int main(){
        string filename;
        ifstream file;
        while(1){
            cout << "Enter a file: ";
            cin >> filename;
            file.open(filename);
            if(file) break;
            cout << "Invalid file. Please try again." << endl;
        }

        string line;
        int n;
        file >> n;

        while (getline(file, line)) {
            if (!line.empty()) {
                break;
            }  
        }
    }
};