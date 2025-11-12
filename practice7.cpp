/*
* EECS 348 Lab 11 Practice 7
* Matrix Operations
* Update user-specified row and column indices of a matrix with a user-specified value, defaulting to indices 0, 0 and value=100
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

        void updateMatrix(int row_index=0, int col_index=0, int val=100){
            matrix[row_index][col_index] = val;
        }
};

class Executive{
    private:
        string filename;
        ifstream file;
        int n;
        string line;
        int row_index;
        int col_index;
        int val;
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
                cout << "Enter the row-index: ";
                if (!(cin >> row_index)){
                    cout << "Invalid row-index. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                if(row_index < 0 or row_index >= n ){
                    cout << "Invalid column-index. Please enter an index within the matrix bounds." << endl;
                } else {
                    break;
                }
            }

            while(1){
                cout << "Enter the column-index: ";
                if (!(cin >> col_index)){
                    cout << "Invalid column-index. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                if(col_index < 0 or col_index >= n ){
                    cout << "Invalid column-index. Please enter an index within the matrix bounds." << endl;
                } else {
                    break;
                }
            }

            while(1){
                cout << "Enter a value: ";
                if (!(cin >> val)){
                    cout << "Invalid value. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                } else {
                    break;
                }
            }


            while(1){
                cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
                cin >> user_choice;
                if(toupper(user_choice) == 'A'){
                    A.updateMatrix(row_index, col_index, val);
                    A.display_matrix();
                    break;
                } else if (toupper(user_choice) == 'B'){
                    B.updateMatrix(row_index, col_index, val);
                    B.display_matrix();
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