#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

#include <string> // 

class Matrix {
private: //
    std::vector<std::vector<int>> data; //

public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diag_major() const;
    int sum_diag_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void display_matrix() const;
};

//
bool read_matrix_file(const std::string &filename, Matrix &matrix1, Matrix &matrix2);

#endif // __MATRIX_HPP__