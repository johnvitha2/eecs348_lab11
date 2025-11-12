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
        char matrix;
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
            
            A.readFromFile(file, n);
            B.readFromFile(file, n);

            while(1){
                cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
                cin >> matrix;
                if(toupper(matrix) == 'A'){
                    cout << "Diagonal sum: " << A.get_diagonal_sum();
                    break;
                } else if (toupper(matrix) == 'B'){
                    cout << "Diagonal sum: " << B.get_diagonal_sum();
                    break;
                } else {
                    cout << "Invalid matrix selection. Please try again.";
                }
            }
        }
};

int main(){
    Executive exec;
    exec.run();
}