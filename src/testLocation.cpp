#include "location.h"
#include "gtest/gtest.h"
using namespace std;

TEST(LocationTest, ConstructorWithCluesAndGetters){
    string name = "Shed";
    string description = "The shed walls hold up neat rows of tools. One big item noticeably missing.";
    vector<string> clueList = {"Tarp", "Mallet"};
    bool accessible = false;
    bool multiple = true;
    string keyClue = "Mallet";

    Location shed(name, description, clueList, accessible, multiple, keyClue);

    EXPECT_EQ(name, shed.getName());
    EXPECT_EQ(multiple, shed.checkMultiItems());
    EXPECT_FALSE(shed.checkkeyClueFound());
    EXPECT_EQ(keyClue, shed.getKeyClue());
}

TEST(LocationTest, ConstructorWithoutClues){
    string name = "Garden";
    string description = "The flowers are lively but a little overgrown.";
    bool accessible = true;
    bool multiple = false;
    string keyClue = "\"Uncut Grass\"";


    Location garden(name, description, accessible, multiple, keyClue);

    EXPECT_EQ(name, garden.getName());
    EXPECT_TRUE(garden.getClueList().empty());
    EXPECT_EQ(accessible, garden.checkUnlock());
    EXPECT_EQ(multiple, garden.checkMultiItems());
    EXPECT_FALSE(garden.checkkeyClueFound());
    EXPECT_EQ(keyClue, garden.getKeyClue());
}

TEST(LocationTest, UnlockLocation){
    string name = "Shed";
    string description = "The shed walls hold up neat rows of tools. One big item noticeably missing.";
    vector<string> clueList = {"Tarp", "Mallet"};
    bool accessible = false;
    bool multiple = true;
    string keyClue = "Mallet";

    Location shed(name, description, clueList, accessible, multiple, keyClue);

    EXPECT_FALSE(shed.checkUnlock());

    shed.unlockLocation();

    EXPECT_TRUE(shed.checkUnlock());
}

TEST(LocationTest, LockLocation){
    string name = "Kitchen";
    string description = "The walls are painted a pale yellow and drawers and cupboards white.";
    vector<string> clueList = {"Sitter Bracelet", "\"The floor was freshly mopped...\"", "\"Missing Mop\""};
    bool accessibleInitial = true;
    bool multiple = true;
    string keyClue = "\"The floor was freshly mopped...\"";

    Location kitchen(name, description, clueList, accessibleInitial, multiple, keyClue);

    EXPECT_TRUE(kitchen.checkUnlock());

    kitchen.lockLocation();

    EXPECT_FALSE(kitchen.checkUnlock());
}

TEST(LocationTest, MarkClueFound){
    string name = "Backyard";
    string description = "More uncut grass but as you walk further through the backyard...";
    vector<string> clueList = {"Brother's keys", "Body appears to be dragged on grass by blood pattern"};
    bool accessible = true;
    bool multiple = true;
    string keyClue = "Brother's keys";

    Location backyard(name, description, clueList, accessible, multiple, keyClue);

    EXPECT_FALSE(backyard.checkkeyClueFound());

    backyard.markClueFound();

    EXPECT_TRUE(backyard.checkkeyClueFound());
}

TEST(LocationTest, PrintDescription){
    string name = "Dr. Lou's Room";
    string description = "Nothing remarkable...there's a picture of her and Dad next to the bed.";
    vector<string> clueList = {"Dr. Lou's Phone", "Scalpel"};
    bool accessible = true;
    bool multiple = true;
    string keyClue = "Dr. Lou's Phone";

    Location drLousRoom(name, description, clueList, accessible, multiple, keyClue);

    EXPECT_NO_THROW(drLousRoom.printDescript());
}

