#include "gameLoader.h"
#include <iostream>
#include <cassert>

using namespace std;

/*int test() {
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
        assert(!data.locationLibrary.empty());
        assert(!data.clueLibrary.empty());
        assert(!data.dayLibrary.empty());

        // Check if gameDialogue has any entries and that their values aren't empty
        for (const auto& pair : data.gameDialogue) {
            cout << "Dialogue key: " << pair.first << ", entries: " << pair.second.size() << endl;
            assert(!pair.second.empty());
        }

        cout << "All files loaded and validated successfully!" << endl;

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
}*/

int test() {
    try {
        GameData data = LoadFiles();

        cout << "=== Load Report ===" << endl;

        // LOCATIONS
        cout << "\nLocations Loaded: " << data.locationLibrary.size() << endl;
        for (const auto& loc : data.locationLibrary) {
            cout << " - " << loc.getName() << endl;
        }

        // DIALOGUE
        cout << "\nDialogue Groups Loaded: " << data.gameDialogue.size() << endl;
        for (const auto& pair : data.gameDialogue) {
            cout << " - Key: " << pair.first << " | Entries: " << pair.second.size() << endl;
            for (size_t i = 0; i < pair.second.size(); ++i) {
                cout << "   [" << i + 1 << "] ";
                if (pair.second[i]) {
                    pair.second[i]->print();
                } else {
                    cout << "(null DialogueUnit)" << endl;
                }
            }
        }

        // PEOPLE
        cout << "\nPeople Loaded: " << data.personLibrary.size() << endl;
        for (const auto& p : data.personLibrary) {
            cout << " - " << p.getPersonName() << endl;
        }

        // PLAYERS
        cout << "\nPlayers Loaded: " << data.playerLibrary.size() << endl;
        for (const auto& p : data.playerLibrary) {
            cout << " - " << p.getPersonName() << endl;
        }

        // Optional: Add assertions
        assert(!data.locationLibrary.empty());
        assert(!data.clueLibrary.empty());
        assert(!data.dayLibrary.empty());
        for (const auto& pair : data.gameDialogue) {
            assert(!pair.second.empty());
        }

        cout << "\nAll files loaded and validated successfully!" << endl;

    } catch (const std::bad_alloc& e) {
        cerr << " Memory allocation failed: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Exception during load: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown error during file loading." << endl;
        return 1;
    }

    return 0;
}

