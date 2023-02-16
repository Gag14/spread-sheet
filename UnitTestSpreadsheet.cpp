#include <iostream>
#include <string>
#include "Spreadsheet.h"
class TestSpreadsheet 
{
	public:
			Spreadsheet testsheet;	
			Cell cell;
			void _setCellAt () 
			{
				cell.setValue("Se");
				testsheet.setCellAt(2, 2, cell);
				if (testsheet.getCellAt(2, 	2) == cell) 
				{
					std::cout << "Sheet's set test is passed" << std::endl;
				}
				else 
				{
					std::cout << "Sheet's set test NOT passed" << std::endl;
				}
			}
				void _addRow () 
				{
					int check  = testsheet.getRow();
					testsheet.addRow(2);
					if (testsheet.getRow() == check + 1 ) 
					{
						std::cout << "Sheet's add row test passed" << std::endl;
					}	
					else 
					{
						std::cout << "Sheet's add row test NOT passed" << std::endl;
					}
				}
				void _removeRow () 
				{
					int check = testsheet.getRow();
					testsheet.removeRow(2);
					if (testsheet.getRow() == check -1) 
					{
						std::cout << "Sheet's remove row test passed" << std::endl;
					}
					else 
					{
						std::cout << "Sheet's remove row test NOT passed" << std::endl;
					}
				}
				void _addColumn () 
				{
					int check =  testsheet.getColumn();
					testsheet.addColumn(2);
					if (testsheet.getColumn() == check + 1) 
					{
						std::cout << "Sheet's add column test passed" << std::endl;
					}
					else 
					{
						std::cout << "Sheet's add column test NOT passed" << std::endl;
					}
				}
				void _removeColumn () 
				{
					int check = testsheet.getColumn();
					testsheet.addColumn(2);
					if (testsheet.getColumn() == check -1) 
					{
						std::cout << "Sheet's remove column test passed" << std::endl;
					}
					else 
					{
						std::cout << "Sheet's remove column test NOT passed" << std::endl;
					}
				}
				void _swapRows () 
				{
					
					std::string tmp;
					for (int i = 0; i < testsheet.getRow(); ++i) 
					{
						for (int j = 0; j < testsheet.getColumn(); ++j) 
						{
							std::cin >> tmp;
							testsheet.setCellAt(i, j, tmp);
						}
					}
					int row = testsheet.getRow();
					Cell* arr1 = new Cell[row];
					Cell* arr2 = new Cell[row];
					for (int i = 0; i < row; ++i) 
					{
						arr1[i] = testsheet.getCellAt(1, i);
					}
					for (int i = 0; i < row; ++i) 
					{
						arr2[i] = testsheet.getCellAt(2, i);	
					}
					testsheet.swapRows(1, 2) ;
					int check = 0;
					for (int i = 0; i < row; ++i) 
					{
						if (arr1[i] != testsheet.getCellAt(2, i) || arr2[i] != testsheet.getCellAt(1, i)) 
						{
							std::cout << "Sheet's Swaprow test NOT passed" << std::endl;
							++check;
						}
					}
					if (check == 0) 
					{
						std::cout << "Sheet's Swaprow test passed" << std::endl;
					}
					delete[] arr1;
					delete[] arr2;
					/*
					testsheet.setCellAt(0,0,"A");
					testsheet.setCellAt(1,0,"B");
					testsheet.swapColumns(0 ,1);
					if (testsheet.getCellAt(0, 0).getValue() == "B") 
						{
							std::cout << "Sheet's Swap  test passed" << std::endl;
						}
						else 
						{
							std::cout << "Sheet's Swap Column test NOT passed" << std::endl;
						}
						*/
				}
				void _swapColumns () 
				{
			/*		std::string tmp;
					for (int i = 0; i < testsheet.getRow(); ++i) 
					{
						for (int j = 0; j < testsheet.getColumn(); ++j) 
						{
							std::cin >> tmp;
							testsheet.setCellAt(i, j, tmp);
						}
					}
					int col  = testsheet.getColumn();
				/*	Cell* arr1 = new Cell[col];
					Cell* arr2 = new Cell[col];
					for (int i = 0; i < col; ++i) 
					{
						arr1[i] = testsheet.setCellAt(1, 1);
						arr2[i] = testsheet.setCellAt(1, 2);
					}
					
					testsheet.swapColumns(1, 2);
					int check = 0;
					for (int i = 0; i < col; ++i) 
					{
						if (arr1[i] != testsheet.getCellAt(i, 2) || arr2[i] != testsheet.getCellAt(i, 1)) 
						{
							std::cout << "Sheet's Swap column test NOT passed" << std::endl;
							++check;
						}
					}
					if (check == 0) 
					{
						std::cout << "Sheet's Swap columns test passed" << std::endl;
					}		
					delete[] arr1;
					delete[] arr2;
					*/
					testsheet.setCellAt(0,0,"A");
					testsheet.setCellAt(0,1,"B");
					testsheet.swapColumns(0 ,1);

					if (testsheet.getCellAt(0, 0).getValue() == "B") 
					{
						std::cout << "Sheet's Swap Columns test passed" << std::endl;
					}
					else 
					{
						std::cout << "Sheet's Swap Column test NOT passed" << std::endl;
					}
				}
				void RunAllTests () 
				{
					_setCellAt();
					_addRow();
					_removeRow();
					_addColumn();
					_removeColumn();
					_swapRows();
					_swapColumns();
				}
};
int main () 
{
	TestSpreadsheet sheet;
	sheet.RunAllTests();
}
