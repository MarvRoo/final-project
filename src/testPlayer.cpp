#include "player.cpp"
#include "gtest/gtest.h"


TEST(Player, testConstructorOnly) {
    Player player("Ally", "A+", "Phone", "Just returned from Barbados. She has long brown hair and is 5'3. She is a smart, independent person.");

    EXPECT_NO_THROW({Player player("Ally", "A+", "Phone", "Just returned from Barbados. She has long brown hair and is 5'3. She is a smart, independent person.");});
}

TEST(Player, testAddUnlockedRoom) {
    Player player("Ally", "A+", "Phone", "Just returned from Barbados. She has long brown hair and is 5'3. She is a smart, independent person.");
    
    EXPECT_NO_THROW({
        player.addUnlockedRoom("Shed");
    });

    vector<string>* rooms = player.shareRoomListPtr();
    ASSERT_NE(rooms, nullptr);
    ASSERT_GE(rooms->size(), 6);         // 5 default + 1 added
    EXPECT_EQ(rooms->at(5), "Shed");
}

