//
//  main.cpp
//  Lab 8 Player List
//
//  Created by jim bailey on 2/22/21.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::cin, std::cout, std::endl, std::string;

#include "helper.hpp"

// comment out the following lines to skip a particular test
#define TEST_PERSON
#define TEST_POLY
#define TEST_OPERATORS


#ifdef TEST_PERSON
#include "Person.hpp"
#endif
#if defined(TEST_POLY) or defined(TEST_OPERATORS)
#include "Player.hpp"
#endif


int main()
{
    // initalize random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    
    string fName, lName;
    int age;
    
#ifdef TEST_PERSON
    cout << "Testing Person" << endl;
    
    makePersonInfo(fName, lName, age);
    
    Person testPerson(fName, lName, age);
    
    cout << "Testing constructor" << endl;
    cout << " expected: " << fName << " " << lName << " " << age << endl;
    cout << " actually: " << testPerson.getFirstName() << " "
    << testPerson.getLastName() << " " << testPerson.getAge() << endl;
    
    makePersonInfo(fName, lName, age);
    testPerson.setFirstName(fName);
    testPerson.setLastName(lName);
    testPerson.setAge(age);
    
    cout << "Testing setters" << endl;
    cout << " expected: " << fName << " " << lName << " " << age << endl;
    cout << " actually: " << testPerson.getFirstName() << " "
    << testPerson.getLastName() << " " << testPerson.getAge() << endl;
    
    cout << "Done testing Person " << endl << endl;
    
#endif // TEST_PERSON
    
#ifdef TEST_POLY
    cout << "Testing Player polymorphism" << endl;
    
    Player ** players = new Player * [eNUM_CHARS];
    
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        players[i] = makePlayer(static_cast<Characters>(i));
    }
    
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        cout << " " << players[i]->getPlayerName()
        << " aged " << players[i]->getPlayerAge()
        << " playing a " << players[i]->getClassName()
        << " " << players[i]->getAction() << endl;
    }
    
    for (int i = 0; i < eNUM_CHARS; i++)
    {
        delete players[i];
    }
    delete [] players;
    cout << "Done testing Player polymorphism" << endl << endl;
    
#endif // TEST_POLY
    
#ifdef TEST_OPERATORS
    cout << "Testing overloaded operators for Player" << endl;
    Player * priest = makePlayer(ePriest);
    Player * ranger = makePlayer(eRanger);
    Player copy(*priest);
    
    cout << "The priest and priest copy are: " << endl;
    cout << " " << *priest << endl;
    cout << " " << copy << endl << endl;
    
    copy = *ranger;
    cout << "The ranger and assigned copy are: " << endl;
    cout << " " << *ranger << endl;
    cout << " " << copy << endl << endl;
    
    cout << "The priest and ranger " << ((*ranger==*priest)?"are":"are not") << " equal." << endl;
    cout << "The ranger and copy " << ((*ranger==copy)?"are":"are not") << " equal." << endl << endl;
    
    cout << "Done testing overloaded operators for Player" << endl << endl;
    
    delete priest;
    delete ranger;
#endif // TEST_OPERATORS
    
    return 0;
}
