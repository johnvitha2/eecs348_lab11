#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Matrix{
    private:
        int** matrix_a;
        int** matrix_b;
        int n;

    public:
        void readFromFile(ifstream& file){
            string line;
            file >> n;
            matrix_a = new int*[n];
            matrix_b = new int*[n];

            while(getline(file, line)){
                if(!line.empty()){
                    break;
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    file >> matrix_a[i][j];
                }
            }

            while(getline(file, line)){
                if(!line.empty()){
                    break;
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    file >> matrix_b[i][j];
                }
            }
        }

        void display_matrices(){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << matrix_a[i][j];
                }
                cout << endl;
            }
            cout << endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << matrix_b[i][j];
                }
                cout << endl;
            }
        }
};

class Executive{
    private:
        string filename;
        ifstream file;
    public:
        void run(){
            while(1){
                cout << "Enter a file: ";
                cin >> filename;
                file.open(filename);
                if(file) break;
                cout << "Invalid file. Please try again." << endl;
            }

            Matrix matrix_pair;
            matrix_pair.readFromFile(file);

            matrix_pair.display_matrices();
        }
};

int main(){
    Executive exec;
    exec.run();
}