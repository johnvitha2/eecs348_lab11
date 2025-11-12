#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Matrix{
    private:
        int** matrix;
        int n;

    public:
        void readFromFile(ifstream& file, int n){
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

        Matrix operator+(const Matrix& other) const{
            Matrix sum;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    sum.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
                }
            }
            return sum;
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

            Matrix A;
            Matrix B;
            Matrix C;
            
            A.readFromFile(file, n);
            B.readFromFile(file, n);

            C = A + B;
            C.display_matrix();
        }
};

int main(){
    Executive exec;
    exec.run();
}