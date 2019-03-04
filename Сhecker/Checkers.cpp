#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	setlocale(LC_ALL, "rus");
	Game game;
	bool start = 1;
	RenderWindow window(VideoMode(500, 500), "Checker");
	while (window.isOpen()) {
		Event event; 
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			game.make_move(window, event);
		}
		window.clear(Color(245, 210, 175));
		if (start) {
			game.start_game(window, event, start);
		}
		game.get_checkers_on_board().draw_checkers(window);//рисую поле и шашки
		game.end_game(window, event);//рисую если конец игры	
		window.display();
	}
	return 0;
}