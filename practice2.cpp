/*
* EECS 348 Lab 11 Practice 2
* Matrix Operations
* Add two matrices and display their sum
* Collaborators: None
* Sources: None
* Author: John Vitha
* KU ID: 3158626
* Creation date: 11/11/2025
*/

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
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    file >> matrix[i][j];
                }
            }
        }

        void display_matrix(){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        Matrix operator+(const Matrix& other) const{
            Matrix sum(n);
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
        string line;
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

            while(getline(file, line)){
                if(!line.empty()){
                    break;
                }
            }

            Matrix A(n);
            Matrix B(n);
            
            A.readFromFile(file);
            B.readFromFile(file);

            Matrix C = A + B;
            C.display_matrix();

            file.close();
        }
};

int main(){
    Executive exec;
    exec.run();
}