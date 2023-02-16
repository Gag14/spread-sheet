#include <iostream>
#include <string>
//dffinclude "Spreadsheet.h"
#include "Cell.h"
//#include "Date.h"
// Tests for Cell class methods
class TestforCell 
{
	public:
		Cell testCell;
		void _setValue () 
		{
			testCell.setValue("Working");
			if (testCell.getValue() == "Working") 
			{
				std::cout << "Cell's value setter test passed" << std::endl;
			}
			else 
			{
				std::cout << "Cell's value setter test NOT passed" << std::endl;
			}
		}	
		void _setColor () 
		{
			testCell.setColor(red) ;
			if (testCell.getColor() == red) 
			{
				std::cout << "Cell's color setter test passed" << std::endl;
			}
			else 
			{
				std::cout << "Cell's color setter test NOT passed" << std::endl;
			}
		}
		void _toInt () 
		{
			testCell.setValue("34");
			if (testCell.toInt(testCell.getValue()) == 34) 
			{
				std::cout << "Cell's to Int test passed" << std::endl;
			}
			else 
			{
				std::cout << "Cell's to int test NOT passed" << std::endl;
			}
		}
		void _toDouble () 
		{
			testCell.setValue("5.7");
			if (testCell.toDouble(testCell.getValue()) == 5.7) 
			{
				std::cout << "Cell's to double test passed" << std::endl;
			}
			else 
			{
				std::cout << "Cell's to double test NOT passed" << std::endl;
			}
		}
		void _toDate () 
		{
			testCell.setValue("12-5-2023");
			Date date(12, 5, 2023);
			if (testCell.toDate(testCell.getValue()) == date) 
			{
				std::cout << "Cell's to Date test passed" << std::endl;
			}
			else 
			{
				std::cout << "Cell's to Date test NOT passed" << std::endl;
			}
		}
		void _reset () 
		{
			testCell.setValue("tetsts");
			testCell.setColor(red);			
			testCell.reset();
			if (testCell.getValue() != "" || testCell.getColor() != white) 
			{
				std::cout << "Cell's reset test NOT passed" << std::endl;
			}
			else 
			{
				std::cout << "Cell's reset test passed" <<  std::endl;
			}
		}
		void runAllTests () 
		{
			_setValue();
			_setColor();
			_toInt();
			_toDouble();
			_toDate();
			_reset();
		}
		
};
int main () 
{
	TestforCell a;
	a.runAllTests();
}
