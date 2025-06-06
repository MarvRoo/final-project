#include "autopsy.h"
#include "gtest/gtest.h"

TEST(Autopsy, testGetCharacterName) {
    Autopsy gardener("Gardener", "Fingerprint taken, with no match to the fingerprint on Angie. Found dead in the downstairs bathroom from a self-inflicted gunshot wound to the head. Suspicious suicide.");
    EXPECT_EQ(gardener.getCharacterName(), "Gardener");
}

TEST(Autppsy, testGetCharacterDescription) {
    Autopsy angie("Angie", "Single gun shot wound to the head. Mallet was used to mislead the cause of death. Fingerprints located on body. Fingerprints show less ridge density suggesting the killer is most likely male.");
    EXPECT_EQ(angie.getAutopsyDescription(), "Single gun shot wound to the head. Mallet was used to mislead the cause of death. Fingerprints located on body. Fingerprints show less ridge density suggesting the killer is most likely male.");
}

TEST(Autopsy, testAutopsyConstructor) {
    EXPECT_NO_THROW(Autopsy("Gardener", "Fingerprint taken, with no match to the fingerprint on Angie. Found dead in the downstairs bathroom from a self-inflicted gunshot wound to the head. Suspicious suicide."));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
