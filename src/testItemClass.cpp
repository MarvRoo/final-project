#include "item.h"
#include "gtest/gtest.h"


TEST(Item, testConstructor) {
    Item poolNoodle("pool noodle", true, "A", true, "pool guy", "pool", "Blood found on the pool noodle", true, 1104);
    EXPECT_TRUE(poolNoodle.isItemFound());
    EXPECT_NO_THROW(poolNoodle.print());
}

TEST(Item, testDefaultConstructor){
    Item defaultItem;
    EXPECT_FALSE(defaultItem.isItemFound());
    EXPECT_NO_THROW(defaultItem.print());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
/*
#include "../include/item.h"
#include <iostream>

using namespace std;


int main() {

//testing default item
Item defaultItem;
defaultItem.print();
cout << "Finished testing default item" << endl;

cout << " ---------------------------------------------" << endl;

//testing constructed item ex. Pool Noodle
Item poolNoodle("pool noodle", true, "A", true, "pool guy", "pool", "Blood found on the pool noodle", true, 1104);
cout << "Has the pool noodle been found? ";
if (poolNoodle.isItemFound() == true) cout << "True." << endl;
else cout << "False." << endl;
cout << "Now printing out the pool noodle description: " << endl;
poolNoodle.print(); 

cout << " ---------------------------------------------" << endl;

//testing constructed tiem ex. Tarp
Item tarp("Tarp", true, "A-", true, "Jacob", "Shed", "Angie's dead body was found on top of the tarp.", true, 1101);
cout << "Has the pool noodle been found? ";
if (tarp.isItemFound() == true) cout << "True." << endl;
else cout << "False." << endl;
cout << "Now printing out the tarp description: " << endl;
tarp.print();

cout << " ---------------------------------------------" << endl;

//testing constructed item ex. Grass
Item grass("Grass", true, "A-", false, "N/A", "Backyard", "Bloody trail left in the grass leading to the shed.", true, 1103);
cout << "Has the grass been found? ";
if(grass.isItemFound() == true) cout << "True." << endl;
else cout << "False." << endl;
cout << "Now printing out the grass description: " << endl;
grass.print();

return 0;
};
*/