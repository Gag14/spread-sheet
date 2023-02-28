#include <iostream>
#include <string>
#include "Date.h"
enum Color 
{
	white, 
	red, 
	green, 
	grey 
};
class Cell 
{
	private:
		std::string m_value  = "";
       		Color m_color  = white;
	public:
		Cell() {}
		Cell(std::string val, Color col) 
		{
			m_value = val;
			m_color = col;
		}	
		void setValue(std::string val) 
		{
			m_value = val;	
		}
		std::string getValue() 
		{
			return m_value;
		}
		void setColor (Color col) 
		{
			m_color = col;
		}
		Color getColor () 
		{
			return m_color;
		}
		int toInt (const std::string& str)
		{
			int num = 0;
			int pos = 1;
			for (int i = str.size() - 1; i >= 0; --i) 
			{
				if (str[i] >= '0' && str[i] <= '9')  
				{
					num = num + pos * (str[i] - '0');
					pos*=10;	
				}	
				else 
				{
					std::cout << "The string is not parsable to int" << std::endl;
				}
			}
			return num;
		}
	       	double toDouble (const std::string& str) 
		{
			double pred = 0;
			double postd = 0;
			double result = 0;
			double count = 0.1;
			int pos = 1;
			int i = str.size() - 1;
			for (; str[i] != '.'; --i) 
			{
				if (str[i] >= '0' && str[i] <= '9') 
				{
					pred = pred + pos * (str[i] - '0');
					pos*=10;
					count*=10;
				}
				else 
				{
					std::cout << "The string is not parsable to double" << std::endl;
				}
			}
			--i;
			pos = 1;
			for (; i >= 0; --i) 
			{
				if (str[i] >= '0' && str[i] <= '9') 
				{
					postd = postd + pos * (str[i] - '0');
					pos*=10;
				}
				else 
				{
					std::cout << "The string is not parsable to double" << std::endl;
				}
			}
			result = postd + pred / 10.0;
			return result;
		}
		Date toDate (const std::string& str) 
		{
			Date date;
			int check = 0;
			for (int i = 0; i < str.size(); ++i) 
			{
				if (str[i] == '-') 
				{
					++check;
				}
			}
			if (check != 2) 
			{
				std::cout << "This is not Date format" << std::endl;
				return date;
			}
			std::string tmp;
			int i = 0;
			for (; str[i] != '-'; ++i) 
			{
				tmp.push_back(str[i]);
			}
			int day = toInt(tmp);
			date.setDay(day);
			tmp.clear();
			++i;
			for(;str[i] != '-'; ++i) 
			{
				tmp.push_back(str[i]);
			}
			int month = toInt(tmp);
			date.setMonth(month);
			tmp.clear();
			++i;
			for(;i < str.size(); ++i) 
			{
				tmp.push_back(str[i]);
			}
			int year = toInt(tmp);
			date.setYear(year);
			return date;
		}
		void reset () 
		{
			m_value = "";
			m_color = white;
		}
		Cell& operator= (const Cell& cell) 
		{
			if (this == &cell) 
			{
				return *this;
			}
			this->m_value = cell.m_value;
			this->m_color = cell.m_color;
			return *this;
		}
		bool operator== (const Cell& cell) 
		{
			return (this->m_value == cell.m_value);
		}
		bool operator!= (const Cell& cell) 
		{
			return !(this->m_value == cell.m_value);
		}
};


