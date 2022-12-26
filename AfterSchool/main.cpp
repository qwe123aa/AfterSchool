#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(void)
{
	// 윈도창 생성
	RenderWindow window(VideoMode(640, 480), "AfterSchool");


	RectangleShape player;
	player.setSize(Vector2f(40, 40));
	player.setPosition(100, 100);
	player.setFillColor(Color::Red);
	

	// 윈도가 열려있을 때까지 반복
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// 종료(x) 버튼을 누르면 Event::Closed(0)
			case Event::Closed:
				window.close();		// 윈도를 닫는다
			}
		}


		window.draw(player);

		window.display();
	}

	return 0;
}