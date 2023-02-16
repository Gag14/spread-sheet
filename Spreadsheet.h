#include <iostream>
#include <string>
#include "Cell.h"
class Spreadsheet 
{
	private:
		int m_row = 3;
		int m_column = 3;
		Cell** m_cells = new Cell*[m_row]; 
	public:
		Spreadsheet() 
		{
			for (int i = 0; i < m_row; ++i) 
			{
				m_cells[i] = new Cell[m_column];
			}
						
		}
		int getRow () 
		{
			return m_row;
		}
		int getColumn () 
		{
			return m_column;
		}
		void setCellAt(int i, int j, std::string str) 
		{
			m_cells[i][j].setValue(str);
		}
		void setCellAt (int i, int j, Cell cell) 
		{
			m_cells[i][j] = cell;
		}
		Cell getCellAt (int i, int j) 
		{
			return m_cells[i][j];
		}
		void addRow (int index) 
		{
			Cell** tmp = new Cell*[m_row];
			for (int i = 0; i < m_row; ++i) 
			{
				tmp[i] = new Cell[m_column];
			}
			for (int i = 0; i < m_row; ++i) 
			{
				for (int j = 0; j < m_column; ++j) 
				{
					tmp[i][j] = m_cells[i][j];
				}
			}
			for (int i = 0; i < m_row; ++i) 
			{
				delete[] m_cells[i];
			}
			delete[] m_cells;
			int tmprow = m_row;
			++m_row;
			m_cells = new Cell*[m_row];
			for (int i = 0; i < m_row; ++i) 
			{
				m_cells[i] = new Cell[m_column];
			}
			for (int i = 0; i <= index; ++i) 
			{
				for (int j = 0; j < m_column; ++j) 
				{
					m_cells[i][j] = tmp[i][j];
				}
			}
			for (int i = index + 1; i < m_row; ++i) 
			{
				for (int j = 0; j < m_column; ++j) 
				{
					m_cells[i][j] = tmp[i-1][j];
				}
			}
			for (int i = 0; i < tmprow; ++i) 
			{
				delete[] tmp[i];
			}
			delete tmp;
		}
		void removeRow (int index) 
		{
			Cell** tmp = new Cell*[m_row];
                        for (int i = 0; i < m_row; ++i)
                        {
                                tmp[i] = new Cell[m_column];
                        }
                        for (int i = 0; i < m_row; ++i)
                        {
                                for (int j = 0; j < m_column; ++j)
                                {
                                        tmp[i][j] = m_cells[i][j];
                                }
                        }
			for (int i = 0; i < m_row; ++i) 
			{
				delete[] m_cells[i];
			}
			delete[] m_cells;
			int tmprow = m_row;
			--m_row;
			m_cells = new Cell*[m_row];
			for (int i = 0; i < m_row; ++i) 
			{
				m_cells[i] = new Cell[m_column];
			}
			for (int i = 0; i < index; ++i) 
			{
				for (int j = 0; j < m_column; ++j) 
				{
					m_cells[i][j] = tmp[i][j];
				}
			}
			for (int i = index + 1; i < tmprow; ++i) 
			{
				for (int j = 0; j < m_column; ++j) 
				{
					m_cells[i - 1][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < tmprow; ++i) 
			{
				delete[] tmp[i];
			}
			delete[] tmp;

		}
		void addColumn (int index) 
		{
			Cell** tmp = new Cell*[m_row];
                        for (int i = 0; i < m_row; ++i)
                        {
                                tmp[i] = new Cell[m_column];
                        }
                        for (int i = 0; i < m_row; ++i)
                        {
                                for (int j = 0; j < m_column; ++j)
                                {
                                        tmp[i][j] = m_cells[i][j];
                                }
                        }
                        for (int i = 0; i < m_row; ++i)
                        {
                                delete[] m_cells[i];
                        }
                        delete[] m_cells;
			int tmpcol = m_column;
			++m_column;
			m_cells = new Cell*[m_row];
			for (int i = 0; i < m_row; ++i) 
			{
				m_cells[i] = new Cell[m_column];
			}
			for (int i = 0; i < m_row; ++i) 
			{
				for (int j = 0; j <= index; ++j) 
				{
					m_cells[i][j] = tmp[i][j];
				}
				for (int j = index + 1; j < m_column; ++j) 
				{
					m_cells[i][j] = tmp[i][j - 1];
				}
			}
			for (int i = 0; i < m_row; ++i) 
			{
				delete[] tmp[i];
			}
			delete[] tmp;
		}
		void removeColumn (int index) 
		{
			Cell** tmp = new Cell*[m_row];
                        for (int i = 0; i < m_row; ++i)
                        {
                                tmp[i] = new Cell[m_column];
                        }
                        for (int i = 0; i < m_row; ++i)
                        {
                                for (int j = 0; j < m_column; ++j)
                                {
                                        tmp[i][j] = m_cells[i][j];
                                }
                        }
                        for (int i = 0; i < m_row; ++i)
                        {
                                delete[] m_cells[i];
                        }
                        delete[] m_cells;
			--m_column;
			m_cells = new Cell*[m_row];
			for (int i = 0; i < m_row; ++i) 
			{
				m_cells[i] = new Cell[m_column];
			}
			for (int i = 0; i < m_row; ++i) 
			{
				for (int j = 0; j < index; ++j) 
				{
					m_cells[i][j] = tmp[i][j];
				}
				for (int j = index + 1; j < m_column; ++j) 
				{
					m_cells[i][j] = tmp[i][j - 1];
				}
			}
			for (int i = 0; i < m_row; ++i) 
			{
				delete[] tmp[i];
			}
			delete[] tmp;	
		}
		void swapRows (int i1, int i2) 
		{
			Cell* tmp = new Cell[m_column];
			for (int i = 0; i < m_column; ++i) 
			{
				tmp[i] = m_cells[i1][i];
				m_cells[i1][i] = m_cells[i2][i];
			}
			for (int i = 0; i < m_column; ++i) 
			{
				m_cells[i2][i] = tmp[i];
			}
			delete[] tmp;
		}
		void swapColumns (int i1, int i2) 
		{
			Cell* tmp = new Cell[m_row];
			for (int i = 0; i < m_row; ++i) 
			{
				tmp[i] = m_cells[i][i1];
				m_cells[i][i1] = m_cells[i][i2];
			}
			for (int i = 0; i < m_row; ++i) 
			{
				m_cells[i][i2] = tmp[i];
			}
			delete[] tmp;
		}
		~Spreadsheet () 
		{
			for (int i = 0; i < m_row; ++i) 
			{
				delete[] m_cells[i];
			}
			delete[] m_cells;
		}
};
