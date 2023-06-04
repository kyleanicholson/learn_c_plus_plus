//
//  Helper.hpp
//  Player List
//
//  Created by jim bailey on 3/3/21.
//

#ifndef Helper_hpp
#define Helper_hpp
#include <string>
#include "Player.hpp"

using std::string;

class Player;

enum Characters {ePlayer, ePriest, eRanger, eRogue, eWizard, eNUM_CHARS};

void makePersonInfo(string & fName, string & lName, int & age);

Player * makePlayer(Characters choice);

int getInteger(int min, int max);


#endif /* Helper_hpp */
