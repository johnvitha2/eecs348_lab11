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

        Matrix swap_rows(int row1, int row2){
            Matrix C(n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == row1){
                        C.matrix[i][j] = matrix[row2][j];
                    } else if(i == row2){
                        C.matrix[i][j] = matrix[row1][j];
                    } else {
                        C.matrix[i][j] = matrix[i][j];
                    }
                }
            }
            return C;
        }  
};

class Executive{
    private:
        string filename;
        ifstream file;
        int n;
        int row1_index;
        int row2_index;
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

            Matrix A(n);
            Matrix B(n);
            
            A.readFromFile(file);
            B.readFromFile(file);

            while(1){
                cout << "Enter the first row-index: ";
                if (!(cin >> row1_index)){
                    cout << "Invalid row-index. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                if(row1_index < 0 or row1_index >= n ){
                    cout << "Invalid row-index. Please enter an index within the matrix bounds." << endl;
                } else {
                    break;
                }
            }

            while(1){
                cout << "Enter the second row-index: ";
                if (!(cin >> row2_index)){
                    cout << "Invalid row-index. Please enter an integer." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                if(row2_index < 0 or row2_index >= n ){
                    cout << "Invalid row-index. Please enter an index within the matrix bounds." << endl;
                } else {
                    break;
                }
            }

            while(1){
                cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
                cin >> user_choice;
                if(toupper(user_choice) == 'A'){
                    Matrix C = A.swap_rows(row1_index, row2_index);
                    C.display_matrix();
                    break;
                } else if (toupper(user_choice) == 'B'){
                    Matrix C = B.swap_rows(row1_index, row2_index);
                    C.display_matrix();
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