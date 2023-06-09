#include <iostream>

using namespace std;

class Date
{
    uint8_t date;
    uint8_t month;
    uint8_t year;
    public:
        Date (uint8_t date = -1, uint8_t month = -1, uint8_t year = -1) : 
            date(date), month(month), year(year) {}
        uint8_t get_date() const
        {
            return date;
        }
        uint8_t dec_date() 
        {
            return date++; 
        }
        uint8_t inc_date() const
        {
            date++; // This won't work and will throw compilation error since we are mutating a data member
        }
        uint8_t get_decremented_date() const
        {
            return dec_date(); // This won't work since we are calling a non-const member function
        }
};



int main()
{
    Date d{9,6,23};
    cout << d.get_date();
    cout << d.inc_date();


}
