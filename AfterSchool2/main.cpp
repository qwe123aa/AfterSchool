#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

using namespace sf;

int main(void) {
	RenderWindow window(VideoMode(1200, 800), "AfterSchool2");
	window.setFramerateLimit(60);

	Vector2i mouse_pos;

	while (window.isOpen()) {
		mouse_pos = Mouse::getPosition(window);

		Event event;
		
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
			}

		}

		printf("(%d,%d)\n", mouse_pos.x, mouse_pos.y);
	}

	return 0;
}