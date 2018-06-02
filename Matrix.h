#include <initializer_list>
#include <fstream>
using namespace std;

template <typename type, size_t M, size_t N> //Реализовывается матрица MxN
class Matrix
{
private:
	type * *ptr;
public:
	template <typename type, size_t M, size_t N>
	Matrix() : ptr(nullptr)
	{

	}
	typedef int type;
	Matrix(initializer_list <type> list)
	{
		type ptr = new type *[M];
		auto p = list.begin();
		for (int i = 0; i < M; i++)
		{
			ptr[i] = new type[N]
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ptr[i][j] = (*p);
				p++;
			}
		}
	}

	template <typename type, size_t M, size_t N>
	Matrix(const Matrix& m_matrix) 
	{
		ptr = new type *[M];
		for (unsigned int i = 0; i < M; i++) 
		{
			ptr[i] = new type[N];
			for (unsigned int j = 0; j < N; j++)
				ptr[i][j] = m_matrix.ptr[i][j];
		}
	}

	template <typename type, size_t M, size_t N>
	void _swap(Matrix &m_matrix)
	{
		type **curr = new type *[M];
		for (int i = 0; i < M; i++)
		{
			curr[i] = new type[N];
			for (int j = 0; j < N; j++)
			{
				curr[i][j] = m_matrix.ptr[i][j]
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				m_matrix.ptr[i][j] = this->ptr[i][j];
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				this->ptr[i][j] = curr[i][j];
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				delete[][] ptr;
			}
		}
	}
	template <typename type, size_t M, size_t N>
	bool empty()
	{
		if (ptr == nullptr)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	template <typename type, size_t M, size_t N>
	size_t columns()
	{
		return N;
	}

	template <typename type, size_t M, size_t N>
	size_t rows()
	{
		return M;
	}

	template <typename type, size_t M, size_t N>
	type *operator[](size_t index)
	{
		return ptr[index];
	}

	template <typename type, size_t M, size_t N>
	Matrix operator-(const Matrix& m_matrix)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ptr[i][j] = ptr[i][j] - m_matrix.ptr[i][j];
			}
		}

		return *this;
	}

	template <typename type, size_t M, size_t N>
	Matrix operator+(const Matrix& m_matrix)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ptr[i][j] = ptr[i][j] + m_matrix.ptr[i][j];
			}
		}

		return *this;
	}

	template <typename type, size_t M, size_t N>
	Matrix operator==(const Matrix& m_matrix)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (ptr[i][j] != m_matrix.ptr[i][j])
				{
					return false;
				}
			}
		}

		return true; //Если не вернул false, значит вернёт true
	}

	template <typename type, size_t M, size_t N>
	ostream& operator<<(ostream& fout, const Matrix<type, N, M>& m_matrix)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fout << m_matrix.ptr[i][j];
			}
			fout << endl;
		}
		return fout;
	}

	template <typename type, size_t M, size_tN>
	istream& operator>>(istream& fin, Matrix<type, N, M>& m_matrix) {
		if (fin.is_open()) 
		{
			type m_matrix.ptr = new type*[M];
			for (unsigned int i = 0; i < M; i++)
			{
				m_matrix.ptr[i] = new type[N];
			}
				
			for (unsigned int i = 0; i < M; i++) 
			{
				for (unsigned int j = 0; j < N; j++)
				{
					fin >> m_matrix.ptr[i][j];
				}
			}
		}
		return is;
	}
};
