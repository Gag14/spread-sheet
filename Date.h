#include <iostream>
/*enum Month 
{
January = 1,
Febuary,
March,
April,
May,
June,
July,
August,
September,
October,
November,
December
};
*/
class Date 
{
	private:
		int m_year = 2023;
		int m_month = 2;
		int m_day = 15;
	public:
		Date() 
		{
			m_year = 2023;
			m_month = 5;
			m_day = 15;
		}
		Date(int day, int month, int year) 
		{
			m_day = day;
			m_month = month;
			m_year = year;
		}
		void setYear (int year) 
		{
			m_year = year;
		}
		int getYear () 
		{
			return m_year;
		}
		void setMonth (int month) 
		{
			if (month < 13 && month > 0)
			{
				m_month = month;
			}
		}
		int getMonth () 
		{
			return m_month;
		}
		void setDay (int day) 
		{
			if (day > 0 && day < 31) 
			{			
				m_day = day;
			}
		}
		int getDay () 
		{
			return m_day;
		}
		bool operator== (const Date& date) 
		{
			if (this -> m_year != date.m_year || this -> m_month != date.m_month || this -> m_day != date.m_day)	{return 0;}
			return 1;
		}

};
