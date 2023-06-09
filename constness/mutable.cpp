#include <iostream>
#include <string>

using namespace std;

class Date
{
    uint8_t date;
    uint8_t month;
    uint8_t year;
    // String representation
    mutable bool is_cached_string_valid;
    mutable string cached_string;
    void compute_string() const
    {
        cached_string = "DD-MM-YY"; //I'm lazy and I don't know how to format strings in C++ :-)
        is_cached_string_valid = true;
    }
    public :
        Date(uint8_t date = -1, uint8_t month = -1, uint8_t year = -1):
            date(date), month(month), year(year) 
        { 
            is_cached_string_valid = false; 
            cached_string = {};
        }
             
        string get_string() const
        {
            if(is_cached_string_valid)
            {
                return cached_string;
            }
            compute_string();
            return cached_string;
        }

        void inc_date() const
        {
            date++; // This still won't work since date is not a mutable data field
        }
};

int main()
{
    // This is const object so no methods that mutate the data members can be called
    const Date d(1, 1, 23);
    // However marking the is_cached_string_valid and cached_string as mutable date fields, we can say that evena const object can have this field changed
    cout << d.get_string();
    d.inc_date(); // Won't work

}
