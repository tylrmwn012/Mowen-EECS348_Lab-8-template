#include "matrix.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>    

Matrix::Matrix(std::size_t N) {
    data = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
}
Matrix::Matrix(std::vector<std::vector<int>> nums) : data(nums) {
}


int Matrix::get_size() const {
    return data.size();
}



int Matrix::get_value(std::size_t i, std::size_t j) const {
  if (i >= data.size() || j >= data.size()) {
    throw std::out_of_range("Error: Index not within bounds");
  }
  return data[i][j];
}



void Matrix::set_value(std::size_t i, std::size_t j, int value) {
    if (i < data.size() && j < data.size()) {
        data[i][j] = value;
    }
}



void Matrix::display_matrix() const {
    for (const auto &row : data) {
        for (int val : row) { 
            std::cout << std::setw(5) << val << " "; 
        }
        std::cout << std::endl;
    }
}



Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = data.size();
    Matrix result(N);

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}



Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = data.size();
    Matrix result(N);

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.data[i][j] = 0; 
            for (std::size_t k = 0; k < N; ++k) {
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return result;
}



int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < data.size(); ++i) {
        sum += data[i][i]; 
    }
    return sum;
}



int Matrix::sum_diagonal_minor() const {
    std::size_t N = data.size();
    int sum = 0;
    for (std::size_t i = 0; i < N; ++i) {
        sum += data[i][N - 1 - i]; 
    }
    return sum;
}



void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < data.size() && r2 < data.size()) {
        std::swap(data[r1], data[r2]);
    }
}



void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < data.size() && c2 < data.size()) {
        for (std::size_t i = 0; i < data.size(); ++i) {
            std::swap(data[i][c1], data[i][c2]); 
        }
    }
}



bool load_matrix_file(const std::string &filename, Matrix &oneMatrix, Matrix &twoMatrix) {
    std::ifstream file(filename); 
    if (!file) { 
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false; 
    }

    std::size_t N; 
    file >> N; 

    std::vector<std::vector<int>> matrix1(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> matrix2(N, std::vector<int>(N, 0));

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix1[i][j]; 
        }
    }

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix2[i][j]; 
        }
    }

    oneMatrix = Matrix(matrix1);
    twoMatrix = Matrix(matrix2);

    return true;
}