#include <iostream>
using namespace std;

int main() {
    int rows = 10;
    int cols = 10;
    char x[rows][cols];   
    
    // for(int row = 0; row < rows; row++) {
    //     for(int col = 0; col < cols; col++) {
    //         cout << x[row][col] << " "; 
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // for(int row = 0; row < rows; row++) {
    //     cout << "row : " << row << endl;
    //     for(int col = 0; col < cols; col++) {
    //         cin >> x[row][col] ;
    //         // cout << " ";
    //     }
    //     cout << endl;
    // }

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if ( row == col || row + col == cols - 1)
            cout << "* " ; 
            else 
            cout << "  ";
        }
        cout << endl;
    }



    // for(int row = 0; row < rows; row++) {
    //     for(int col = 0; col < cols; col++) {
    //         cout << x[row][col] << " "; 
    //     }
    //     cout << endl;
    // }
    return 0;

}