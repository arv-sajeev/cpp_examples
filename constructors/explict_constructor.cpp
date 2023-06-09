#include <iostream>
#include <string>

using namespace std;


// Implicit Class definition
class Dude
{
    string name;
    uint8_t age;
    public:
        //Dude(const string &name, uint8_t age) 
        //  : name(name), age(age){}
        //Dude(const string &name) 
        //  : name(name), age(-1){}
        //Dude(uint8_t age)  
        //  : name("John Doe"), age(age){}
        // We could shorten this with a single constructor that takes defaults
        Dude(const string& name="John Doe", uint8_t age = -1) : 
            name(name), age(age) {}
};


// Class definition with Explicit constructor
class ex_Dude
{
    string name;
    uint8_t age;
    public:
        explicit ex_Dude(const string& name="John Doe", uint8_t age = -1) : 
            name(name), age(age) {}

};

// Driver code
int main()
{
    // Different ways to construct
    // Using () notation
    Dude a = Dude("arvind",25);
    Dude b("Adarsh",20);
    //  Dude x; This wouldn't work since there isn't a matching constructor that takes no args
    //  Using {} notation
    Dude c = Dude {"Mini", 52};
    Dude d{"Sajeev", 58};
    string ar = "Arvind";

    // Implicit conversion
    Dude e = ar; // This surprisingly works, 
                 //     what happens is compiler assumes implicit conversion is required 
                 //     the String "arvind" is used as the argument name and the default for age is given
                 //     This is messed up  :-B
    Dude f = {ar};
    Dude g = Dude{ar};
    Dude h{ar};

    // Explicit conversion
    ex_Dude i{ar};
    ex_Dude j = ex_Dude{ar};
    // So only if you explicitly call the constructor does an object get created

    // Weird ass impliciti conversions are no longer valid
    ex_Dude k = ar; // Doesn't work
    ex_Dude l = {ar}; // Doesn't wor
}


