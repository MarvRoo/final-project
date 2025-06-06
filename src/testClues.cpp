#include "clue.h"
#include "gtest/gtest.h"

TEST(Clue, testDefaultClueConstructor) {
	EXPECT_NO_THROW(Clue());
}

TEST(Clue, testDefaultClueGetName) {
	Clue defaultClue;
    EXPECT__STREQ(defaultClue.getName(), "N/A");
}

TEST(Clue, testClueConstructor) {
	EXPECT_NO_THROW(Clue(1109, “Mallet”));
}

TEST(Clue, testClueGetName) {
    Clue bracelet(1106, "sitter's bracelet");
    EXPECT__STREQ(bracelet.getName(), "sitter's bracelet");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
