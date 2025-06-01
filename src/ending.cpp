#include "ending.h"

Ending::Ending() {
    sceneName = "";
    storyDescription = "";
    hpcap = 0;
}

Ending::Ending(string name, string storyDescript, int hp) : sceneName(name), storyDescription(storyDescript), hpcap(hp){}

