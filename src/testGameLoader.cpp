#include "gameLoader.h"
#include "gtest/gtest.h"
#include <iostream>
#include <cassert>

using namespace std;
void printOutGameDataLibraries(GameData* data);

int test() {
    //turn into a google test when all days are ready
    try {
        GameData data = LoadFiles();

        // Basic sanity checks to see if data loaded
        cout << "Locations loaded: " << data.locationLibrary.size() << endl;
        cout << "Clues loaded: " << data.clueLibrary.size() << endl;
        cout << "Dialogue groups loaded: " << data.gameDialogue.size() << endl;
        cout << "Days loaded: " << data.dayLibrary.size() << endl;
        cout << "Autopsies loaded: " << data.autopsyLibrary.size() << endl;
        cout << "People loaded: " << data.personLibrary.size() << endl;
        cout << "Players loaded: " << data.playerLibrary.size() << endl;
        cout << "Endings loaded: " << data.endingsLibrary.size() << endl;

        // Optional: Add basic assertions
        ASSERT_TRUE(!data.locationLibrary.empty());
        ASSERT_TRUE(!data.clueLibrary.empty());
        ASSERT_TRUE(!data.dayLibrary.empty());
        ASSERT_TRUE(!data.autopsyLibrary.size());
        ASSERT_TRUE(!data.personLibrary.size());
        ASSERT_TRUE(!data.playerLibrary.size());
        ASSERT_TRUE(!data.endingsLibrary.size());

        // Check if gameDialogue has any entries and that their values aren't empty
        for (const auto& pair : data.gameDialogue) {
            cout << "Dialogue key: " << pair.first << ", entries: " << pair.second.size() << endl;
            assert(!pair.second.empty());
        }

        cout << "All files loaded and validated successfully!" << endl;
        //call printer
        printOutGameDataLibraries(&data);

    } catch (const std::bad_alloc& e) {
        cerr << "Memory allocation failed during file loading: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Error during file loading: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown error during file loading." << endl;
        return 1;
    }

    return 0;
}

void printOutGameDataLibraries(GameData* data){
    cout << "\n=== LOCATIONS ===\n";
    for (const auto& loc : data->locationLibrary) {
        cout << "- Name: " << loc.getName() << "\n";
        cout << "  Unlocked: " << (loc.checkUnlock() ? "Yes" : "No") << "\n";
        cout << "  Clues: ";
        for (const auto& clue : loc.getClues()) {
            cout << clue << ", ";
        }
        cout << "\n";
        cout << "  Key Clue: " << loc.getKeyClue() << "\n\n";
    }

    cout << "\n=== CLUES ===\n";
    for (const auto& clue : data->clueLibrary) {
        cout << "- Name: " << clue->getName();
        cout << " | Type: " << clue->getType() << "\n";
        clue->print();
        cout << "\n";
    }

    cout << "\n=== PEOPLE ===\n";
    for (const auto& person : data->personLibrary) {
        cout << "- Name: " << person.getPersonName() << "\n";
        cout << "  Description: " << person.grabDescription() << "\n";
    }

    cout << "\n=== PLAYERS ===\n";
    for (const auto& player : data->playerLibrary) {
        cout << "- Name: " << player.getPersonName() << "\n";
    }

    cout << "\n=== AUTOPSIES ===\n";
    for (const auto& autopsy : data->autopsyLibrary) {
        cout << "- Name: " << autopsy.getCharacterName() << "\n";
    }

    cout << "\n=== ENDINGS ===\n";
    for (const auto& ending : data->endingsLibrary) {
        cout << "- Scene: " << ending.getSceneName() << "\n";
        cout << "  Description: " << ending.getStoryDescription() << "\n";
    }

    cout << "\n=== DAYS ===\n";
    int count;
    for (const auto& day : data->dayLibrary) {
        ++count;
    }
    cout << "NumofDays: " << count << endl;

    cout << "\n=== DIALOGUE ===\n";
    for (const auto& [key, list] : data->gameDialogue) {
        cout << "Key: " << key << ", Entries: " << list.size() << "\n";
    }

    cout << "\n=== DONE ===\n";
}

