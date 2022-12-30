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

	while (window.isOpen()) {
		mouse_pos = Mouse::getPosition(window);

		Event event;
		
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				case Event :: MouseButtonPressed:
					if (event.mouseButton.button == Mouse::Right) {
						click_cnt++;
					}
			}

		}

		//마우스 누른 상태면 여러번 클릭됌
		if (Mouse::isButtonPressed(Mouse::Left)) {
			click_cnt++;
		}
		printf("(%d,%d)\n  클릭횟수 : %d\n", mouse_pos.x, mouse_pos.y, click_cnt);
	}

	return 0;
}