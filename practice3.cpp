/*
* EECS 348 Lab 11 Practice 3
* Matrix Operations
* Multiply two matrices and display their product
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
            string line;

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

        Matrix operator*(const Matrix& other) const{
            Matrix product(n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    product.matrix[i][j] = 0;
                    for(int k = 0; k < n; k++){
                        product.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                    }
                }
            }
            return product;
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

            Matrix C = A * B;
            C.display_matrix();

            file.close();
        }
};

int main(){
    Executive exec;
    exec.run();
}