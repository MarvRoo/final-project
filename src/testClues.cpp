#include "clue.h"
#include "gtest/gtest.h"

TEST(Clue, testDefaultClueConstructor) {
	EXPECT_NO_THROW(Clue());
}

TEST(Clue, testDefaultClueGetName) {
	Clue defaultClue;
    EXPECT_STREQ(defaultClue.getName().c_str(), "N/A");
}

TEST(Clue, testClueConstructor) {
	EXPECT_NO_THROW(Clue(1109, "Mallet"));
}

TEST(Clue, testClueGetName) {
    Clue bracelet(1106, "sitter's bracelet");
    EXPECT_STREQ(bracelet.getName().c_str(), "sitter's bracelet");
}


