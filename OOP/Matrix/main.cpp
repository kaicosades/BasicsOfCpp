#include <iostream>
using namespace std;

class Matrix
{
	int rows, cols, matrix;
public:
	const int get_rows()const
	{
		return rows;
	}
	const int get_cols()const// т к после гетера стоит конст и возвращается ссылка на указатель, то чар тоже должен быть конст
	{
		return cols;
	}
	const int get_matrix(const int rows,const int cols) const
	{
		return this->matrix[rows][cols];
	}


	void set_rows(int rows)
	{
		this->rows = rows;
	}
	void set_cols(int rows)
	{
		this->cols = cols;
	}
	void set_matrix(int rows, int cols, int nub)
	{
		this->matrix[rows][cols] = nub;
	}


	Matrix()
	{
		this->rows = 1;
		this->cols = 1;
		this->matrix = new int* [rows] {};
		for(int i = 0; i<rows;i++) matrix
	}
};


void main()
{
	setlocale(LC_ALL, "");


}