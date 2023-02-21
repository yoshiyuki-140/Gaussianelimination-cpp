// Author : Yoshiyuki Kurose
// this code defined Gaussian elimination by using C++
#include <iostream>

#define Max_Dimension_size 100
#define Min_Dimension_size 2

class Gaussian_elimination
{
private:
    int Dimension;
    double matrix[Max_Dimension_size][Max_Dimension_size * 2];
    void ask_dimension();
    void ask_matrix();
    void make_argumentied_matrix();
    void change_matrix(int n1);
    void change_matrix2(int n1, int n2, int m2);
    void print_matrix();
    void algorithm_for_matrix_of_3x3();

public:
    Gaussian_elimination();
    void main_algorithm();
};
;

Gaussian_elimination::Gaussian_elimination()
{
    Dimension = 3;
    for (int i = 0; i < Dimension; i++)
    {
        for (int j = 0; j < Dimension * 2; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Gaussian_elimination::ask_dimension()
{
    std::cout << "Hom many Dimension?" << std::endl;
    // print prompt.
    std::cout << ">> ";
    std::cin >> Dimension;
}

void Gaussian_elimination::ask_matrix()
{
    std::cout << "Please input matrix" << std::endl;

    // dynamic memory
    double **tmp_matrix = new double *[Dimension];
    for (int i = 0; i < Dimension; i++)
    {
        tmp_matrix[i] = new double[Dimension];
    }

    // input
    for (int i = 0; i < Dimension; i++)
    {
        std::cout << "Is " << (i + 1) << "row?: ";
        for (int j = 0; j < Dimension; j++)
        {
            std::cin >> tmp_matrix[i][j];
        }
    }

    // copy to matrix
    for (int i = 0; i < Dimension; i++)
    {
        for (int j = 0; j < Dimension; j++)
        {
            matrix[i][j] = tmp_matrix[i][j];
        }
    }

    // clear dynamic memory
    for (int i = 0; i < Dimension; i++)
    {
        delete[] tmp_matrix[i];
    }
    delete[] tmp_matrix;
}

void Gaussian_elimination::make_argumentied_matrix()
{
    double **tmp_matrix = new double *[Dimension];
    for (int i = 0; i < Dimension; i++)
    {
        tmp_matrix[i] = new double[Dimension * 2];
    }

    for (int i = 0; i < Dimension; i++)
    {
        for (int j = 0; j < Dimension; j++)
        {
            tmp_matrix[i][j] = matrix[i][j];
            if (i == j)
            {
                int n = Dimension + j;
                tmp_matrix[i][n] = 1.0;
            }
            else
            {
                int n = Dimension + j;
                tmp_matrix[i][n] = 0.0;
            }
        }
    }

    // copy to matrix
    for (int i = 0; i < Dimension; i++)
    {
        for (int j = 0; j < Dimension * 2; j++)
        {
            matrix[i][j] = tmp_matrix[i][j];
        }
    }

    // clear dynamic memory
    for (int i = 0; i < Dimension; i++)
    {
        delete[] tmp_matrix[i];
    }
    delete[] tmp_matrix;
}

void Gaussian_elimination::change_matrix(int n1)
/*
    n1 of the variable express n1xn1 matrix
*/
{
    double n = matrix[n1 - 1][n1 - 1];
    if (n == 0)
    {
        std::cout << "this matrix have not inverse matrix" << std::endl;
    }
    for (int i = 0; i < Dimension * 2; i++)
    {
        // matrix[n1 - 1][i] = matrix[n1 - 1][i] / n;
        matrix[n1 - 1][i] /= n;
    }
}

void Gaussian_elimination::change_matrix2(int n1, int n2, int m2)
{
    double n = matrix[n2 - 1][m2 - 1];
    // if (n == 0)
    //{
    //     std::cout << "this matrix have not inverse matrix" << std::endl;
    // }
    for (int i = 0; i < Dimension * 2; i++)
    {
        matrix[n2 - 1][i] = matrix[n2 - 1][i] - matrix[n1 - 1][i] * n;
    }
}

void Gaussian_elimination::print_matrix()
{
    for (int i = 0; i < Dimension; i++)
    {
        for (int j = 0; j < Dimension; j++)
        {
            if (j == (Dimension - 1))
            {
                std::cout << matrix[i][j + Dimension];
            }
            else
            {
                std::cout << matrix[i][j + Dimension] << ",  ";
            }
        }
        std::cout << std::endl;
    }
}

void Gaussian_elimination::algorithm_for_matrix_of_3x3()
{
    // 下の main_algorithm
    // の内容がわかりやすくなるようにこいつは残しとく,消すな未来の俺. This
    // matrix is used only 3x3 matrix
    ask_matrix();
    make_argumentied_matrix();
    change_matrix(1);
    change_matrix2(1, 2, 1);
    change_matrix2(1, 3, 1);
    change_matrix(2);
    change_matrix2(2, 1, 2);
    change_matrix2(2, 3, 2);
    change_matrix(3);
    change_matrix2(3, 1, 3);
    change_matrix2(3, 2, 3);
    print_matrix();
}

void Gaussian_elimination::main_algorithm()
{
    ask_dimension();
    ask_matrix();
    make_argumentied_matrix();
    for (int i = 1; i <= Dimension; i++)
    {
        change_matrix(i);
        for (int k = 1; k <= Dimension; k++)
        {
            if (i != k)
            {
                change_matrix2(i, k, i);
            }
        }
    }
    print_matrix();
}

int main(void)
{
    Gaussian_elimination Ge;
    Ge.main_algorithm();

    return 0;
}
