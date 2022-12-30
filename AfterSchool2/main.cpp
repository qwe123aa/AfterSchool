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
	int click_cnt = 0;

	Font font;
	font.loadFromFile("c:/windows/Fonts/arial.ttf");
	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);
	text.setPosition(0, 0);
	char info[40];

	while (window.isOpen()) {
		mouse_pos = Mouse::getPosition(window);

		Event event;
		
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				case Event :: MouseButtonPressed:
					if (event.mouseButton.button == Mouse::Left) {
						click_cnt++;
					}
			}

		}

		sprintf(info, "(%d,%d)  clicks : %d\n", mouse_pos.x, mouse_pos.y, click_cnt);
		text.setString(info);	
		window.clear(Color::Black);

		window.draw(text);

		window.display();

	}


	return 0;
}