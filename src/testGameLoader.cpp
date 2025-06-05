#include "gameLoader.h"
#include <iostream>
#include <cassert>

using namespace std;

/*int main() {
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

