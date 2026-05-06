#include "Game.h"

int main() {
    Game g;

    g.addPlayer(1, 10);
    g.addPlayer(2, 20);
    g.addPlayer(3, 30);

    cout << "\nPlayers:\n";
    g.display();

    g.nextTurn();
    g.skipPlayer();

    g.removePlayer(2);

    cout << "\nAfter Removal:\n";
    g.display();

    return 0;
}