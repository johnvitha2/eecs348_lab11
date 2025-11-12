/*
* EECS 348 Lab 11 Practice 4
* Matrix Operations
* Output the sum of all elements on the two main diagonals of a matrix
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

        int get_diagonal_sum(){
            int sum = 0;
            int col1_index = 0;
            int col2_index = n-1;

            for(int i = 0; i < n; i++){
                sum += matrix[i][col1_index] + matrix[i][col2_index];

                col1_index++;
                col2_index--;
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
        char user_choice;
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

            while(1){
                cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
                cin >> user_choice;
                if(toupper(user_choice) == 'A'){
                    cout << "Diagonal sum: " << A.get_diagonal_sum();
                    break;
                } else if (toupper(user_choice) == 'B'){
                    cout << "Diagonal sum: " << B.get_diagonal_sum();
                    break;
                } else {
                    cout << "Invalid matrix selection. Please try again." << endl;
                }
            }

            file.close();
        }
};

int main(){
    Executive exec;
    exec.run();
}