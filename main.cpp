#include "matrix.hpp"
#include <iostream>

int main() {
    std::string filename;
    std::cout << "Enter your file's name: ";
    std::cin >> filename;

    Matrix matrix1(0), matrix2(0);



    // Problem 1
    /* Implement a function to load matrix data from a user-specified file. 
    The first line of the file should contain an integer N indicating the size of the matrices, followed by two N × N matrices. 
    After reading the file, print the matrices with proper formatting, such as aligned columns. Note that N can be any valid positive integer.*/
    if (!read_matrix_file(filename, matrix1, matrix2)) {
        return 1;
    }
    std::cout << "\nProblem 1: Printing Matrix from file:";
    std::cout << "\nMatrix One:\n";
    matrix1.display_matrix();
    std::cout << "\nMatrix Two:\n";
    matrix2.display_matrix();



    // Problem 2
    /* Implement a function that adds two matrices and displays the resulting matrix.*/
    Matrix sum = matrix1 + matrix2;
    std::cout << "\nProblem 2: Sum of Matrices:\n";
    sum.display_matrix();



    // Problem 3
    /* Implement a function that multiplies two matrices and displays the resulting matrix. */
    Matrix product = matrix1 * matrix2;
    std::cout << "\nProblem 3: Product of Matrices:\n";
    product.display_matrix();



    // Problem 4
    /* Implement a function to calculate and display the sum of the main and secondary diagonal elements of a matrix. */
    std::cout << "\nProblme 4: Sum of Major Diagonal (Matrix 1): " << matrix1.sum_diag_major() << std::endl;
    std::cout << "Problem 4: Sum of Minor Diagonal (Matrix 1): " << matrix1.sum_diag_minor() << std::endl;
    std::cout << "\nProblme 4: Sum of Major Diagonal (Matrix 2): " << matrix2.sum_diag_major() << std::endl;
    std::cout << "Problme 4: Sum of Minor Diagonal (Matrix 2): " << matrix2.sum_diag_minor() << std::endl;



    // Problem 5
    /* Implement a function that takes a matrix and two-row indices as input (with indexing starting at 0). 
    If both indices are within valid bounds, swap the specified rows and output the resulting matrix.*/
    std::size_t row1, row2;
    std::cout << "\nEnter row 1 of 2 rows indices to swap (Matrix 1): ";
    std::cin >> row1;
    std::cout << "\nEnter row 2 of 2 rows indices to swap (Matrix 1): ";
    std::cin >> row2;
    if ( (row1 < 0 || row1 >= matrix1.get_size()) || (row2 < 0 || row2 >= matrix1.get_size()) ) {
        std::cout << "\nInvalid index entered; skip this operation... \n";
    } else {
        matrix1.swap_rows(row1, row2);
        std::cout << "Problem 5: Matrix 1 after swapping rows:\n";
        matrix1.display_matrix();
    }
    
    std::cout << "\nEnter row 1 of 2 rows indices to swap (Matrix 2): ";
    std::cin >> row1;
    std::cout << "\nEnter row 2 of 2 rows indices to swap (Matrix 2): ";
    std::cin >> row2;
    if ( (row1 < 0 || row1 >= matrix2.get_size()) || (row2 < 0 || row2 >= matrix2.get_size()) ) {
        std::cout << "\nInvalid index entered; skip this operation... \n";
    } else {
        matrix2.swap_rows(row1, row2);
        std::cout << "Problem 5: Matrix 2 after swapping rows:\n";
        matrix2.display_matrix();
    }



    // Problem 6
    /* Implement a function that takes a matrix and two-column indices as input (with indexing starting at 0). 
    If both indices are within valid bounds, swap the specified rows and output the resulting matrix.*/
    std::size_t c1, c2;
    std::cout << "\nEnter col 1 of 2 cols indices to swap (Matrix 1): ";
    std::cin >> c1;
    std::cout << "\nEnter col 2 of 2 cols indices to swap (Matrix 1): ";
    std::cin >> c2;
    if ( (c1 < 0 || c1 >= matrix1.get_size()) || (c2 < 0 || c2 >= matrix1.get_size()) ) {
        std::cout << "\ninvalid col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        matrix1.swap_cols(c1, c2);
        std::cout << "Problme 6: Matrix 1 after swapping cols:\n";
        matrix1.display_matrix();
    }
    // Swapping Columns 
    std::cout << "\nEnter col 1 of 2 cols indices to swap (Matrix 2): ";
    std::cin >> c1;
    std::cout << "\nEnter col 2 of 2 cols indices to swap (Matrix 2): ";
    std::cin >> c2;
    if ( (c1 < 0 || c1 >= matrix2.get_size()) || (c2 < 0 || c2 >= matrix2.get_size()) ) {
        std::cout << "\ninvalid col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        matrix2.swap_cols(c1, c2);
        std::cout << "Problem 6: Matrix 2 after swapping cols:\n";
        matrix2.display_matrix();
    }



    // Problem 7
    /* Implement a function that accepts a matrix, a row index, a column index, and a new value. 
    If both indices are valid (with indexing starting at 0), update the element at the specified position and display the resulting matrix. */
    std::size_t row, col;
    int newVal;
    std::cout << "\nEnter row index for new value update for (Matrix 1): ";
    std::cin >> row;
    std::cout << "\nEnter col index for new value update for (Matrix 1): ";
    std::cin >> col;
    std::cout << "\nEnter new value for new value update for (Matrix 1): ";
    std::cin >> newVal;
    if ( (row< 0 || row >= matrix1.get_size()) || (col < 0 || col >= matrix1.get_size()) ) {
        std::cout << "\ninvalid row or col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        matrix1.set_value(row, col, newVal);
        std::cout << "Problem 7: Matrix 1 after updating value:\n";
        matrix1.display_matrix();
    }

    std::cout << "\nEnter row index for new value update for (Matrix 2): ";
    std::cin >> row;
    std::cout << "\nEnter col index for new value update for (Matrix 2): ";
    std::cin >> col;
    std::cout << "\nEnter new value for new value update for (Matrix 2): ";
    std::cin >> newVal;
    if ( (row< 0 || row >= matrix2.get_size()) || (col < 0 || col >= matrix2.get_size()) ) {
        std::cout << "\ninvalid row or col index entered, sorry, skipping this operation and onto the next.\n";
    } else {
        matrix2.set_value(row, col, newVal);
        std::cout << "Problme 7: Matrix 2 after updating value:\n";
        matrix2.display_matrix();
    }

    return 0;
}