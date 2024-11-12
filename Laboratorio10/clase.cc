#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Game {
private:
    string name;
    string genre;
    int playTime; // tiempo en minutos

public:
    Game() {}

    Game(string name, string genre, int playTime)
        : name(name), genre(genre), playTime(playTime) {}

    void showGame() const {
        cout << "Nombre: " << name << "\nGénero: " << genre 
             << "\nTiempo de juego restante: " << playTime << " minutos" << endl;
    }

    void play(int minutes) {
        if (minutes <= playTime) {
            playTime -= minutes;
            cout << "Jugaste " << minutes << " minutos en " << name 
                 << ". Tiempo restante: " << playTime << " minutos\n";
        } else {
            cout << "No tienes suficiente tiempo de juego en " << name << ". Juega menos tiempo.\n";
        }
    }

    string getName() const { return name; }
    int getPlayTime() const { return playTime; }
};

class Library {
private:
    vector<Game> games;

public:
    void addGame(const Game& game) {
        games.push_back(game);
    }

    void showAllGames() const {
        cout << "Biblioteca de Videojuegos:" << endl;
        for (const auto& game : games) {
            game.showGame();
            cout << "------------------------" << endl;
        }
    }

    void playGame(const string& name, int minutes) {
        for (auto& game : games) {
            if (game.getName() == name) {
                game.play(minutes);
                return;
            }
        }
        cout << "Juego no encontrado en la biblioteca." << endl;
    }
};

int main() {
    Library library;

    // Agregar juegos de ejemplo
    library.addGame(Game("The Legend of Zelda", "Aventura", 300));
    library.addGame(Game("Super Mario Bros.", "Plataformas", 200));

    // Ver todos los juegos en la biblioteca
    library.showAllGames();

    // Jugar cierto tiempo de un juego
    library.playGame("The Legend of Zelda", 60);

    // Intentar jugar más tiempo del disponible
    library.playGame("Super Mario Bros.", 250);

    return 0;
}