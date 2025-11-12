#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Matrix{
    private:
        int** matrix;
        int n;

    public:
        Matrix(int size) : n(size) {
            matrix = new int*[n];
            for (int i = 0; i < n; i++){
                matrix[i] = new int[n];
            }
        }

        void readFromFile(ifstream& file){
            string line;

            matrix = new int*[n];

            while(getline(file, line)){
                if(!line.empty()){
                    break;
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    file >> matrix[i][j];
                }
            }
        }

        void display_matrix(){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << matrix[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
};

class Executive{
    private:
        string filename;
        ifstream file;
        int n;
    public:
        void run(){
            while(1){
                cout << "Enter a file: ";
                cin >> filename;
                file.open(filename);
                if(file) break;
                cout << "Invalid file. Please try again." << endl;
            }

            file >> n;


            Matrix A(n);
            Matrix B(n);

            A.readFromFile(file);
            B.readFromFile(file);

            A.display_matrix();
            B.display_matrix();

            file.close();
        }
};

int main(){
    Executive exec;
    exec.run();
}