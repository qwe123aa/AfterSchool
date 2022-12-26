#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;
int main(void)
{
	//윈도우창 생성
	RenderWindow window(VideoMode(640, 480), "AfterSchool");
	window.setFramerateLimit(60);
	RectangleShape player;
	player.setSize(Vector2f(40, 40));
	player.setPosition(100, 100);
	player.setFillColor(Color::Red);
	int player_speed = 5;

	RectangleShape enemy;
	enemy.setSize(Vector2f(70, 70));
	enemy.setPosition(500, 300);
	enemy.setFillColor(Color::Yellow);
	int enemy_life = 1;

	//윈도우가 열려있을 때까지 반복
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			//종료(X) 버튼을 누르면
			switch (event.type)
			{
			case Event::Closed:
				window.close();//윈도우 닫는다.
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player.move(-player_speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player.move(player_speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player.move(0, -player_speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			player.move(0, player_speed);
		}
		if (enemy_life > 0) {
			if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()));
			{
				printf("enemy와 충돌 \n");
				enemy_life -= 1;
			}
		}

		window.clear(Color::Black);
		if (enemy_life > 0) {
			window.draw(enemy);
		}
		window.draw(player);
		window.display();
	}

	return 0;
}