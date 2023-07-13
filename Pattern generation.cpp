// Building Game using the Concepts of BackTracking.

#include <iostream>
using namespace std;

bool can_shift(int **arr, int x, int y, int size) {
    // This function will tell us Can we move to the next position or not.
    /*
      The function takes 4 argument
          1.} The array of the track { As a Dynamic Array }.
          2.} (x) and (y) will denote for which box we are checking.
          3.} size will denote to the size of the 2D matrix.
  */
    if (x < size && y < size && x >= 0 && y >= 0 && arr[x][y] == 1) {
       /*
            The Zeros (0) represent closed blocks and Ones (1) represents open Blocks
                -> The RAT can only move if there is One(1);
                -> The condiction will only return true if the value if one(1) at the corresponding indexes
                    and they are less than the size of the matrix.
        */

        return true;
    }
    return false;
}

bool movement(int **arr, int x, int y, int size, int **final_result_array) {
    /*
    This functions takes 5 arguments
        {*} final_result_array will be the final result outputed in the form of a track to escape.
    */

    // Base Condition;
    /*
        Here we are checking if the position of both the indexes are at the last index then covert
        the value to one(1) and return true because all of the matrix is check and the possible movements are
        been made so ther is no need for further movenments, and the base fuction also deals with an error
        of infinite recursion.
    */
    if (x == (size - 1) && y == (size - 1)) {
        final_result_array[x][y] = 1;
        return true;
    }
    // Now we'll check if it is possible to change position or not ??
    if (can_shift(arr, x, y, size)) {
        // if the movement is possible we'll sset the value to one(1) in the final_array
        final_result_array[x][y] = 1;

        // Now we'll check the horizontal increment in the position.
        if (movement(arr, x + 1, y, size, final_result_array)) {
            return true;
        }
        // Now we'll check the Vertical increment in the position.
        if (movement(arr, x, y + 1, size, final_result_array)) {
            return true;
        }

        /*
            If both the transformation is not possible we will retuen false and we will also backtrack
                -> Backtracking means returning back to the previous position.
        */


        final_result_array[x][y] = 0; // Backtracking
        return false;
    }

    return false;
}

int main() {
    // Here we assuming that the it's a square matrix;
    int size;
    cout << "Enter the size of the Matrix: ";
    cin >> size;

    // Dynamic allocation of the array;
    int **arr = new int *[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
    }

    // Now we'll take the input from the user to fill in the matrix;
    cout << endl << "Enter the values in the form of (0 and 1):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }

    // Now we will Dynamically allocate another array for the final result array;
    int **final_result_array = new int *[size];
    for (int i = 0; i < size; i++) {
        final_result_array[i] = new int[size];
        for (int j = 0; j < size; j++) {
            // we also need to initialize every value in this matrix equal to zero(0) to avoid garbage value from the compiler
            final_result_array[i][j] = 0;
        }
    }

    // Now if the movement function will return true then we will print the final_array_result;
    if (movement(arr, 0, 0, size, final_result_array)) {
        cout<<endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << final_result_array[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No valid path exists." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
        delete[] final_result_array[i];
    }
    delete[] arr;
    delete[] final_result_array;

    return 0;
}
