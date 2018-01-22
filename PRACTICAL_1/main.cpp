#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A,
	Keyboard::Z,
	Keyboard::Up,
	Keyboard::Down
};
const Vector2f paddleSize(25.0f, 100.0f);
const float ballRadius = 10.0f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.0f;
Vector2f ballVelocity;
bool server = false;

CircleShape ball;
RectangleShape paddles[2];

void Load()
{
	for (auto &p : paddles)
	{
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.0f);
	}

	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);

}
void reset()
{
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);

	ball.setPosition(gameWidth / 2, gameHeight / 2);

	ballVelocity = { (server ? 100.0f : -100.0f), 50.0f };
}
void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
	float direction = 0.0f;

	if (Keyboard::isKeyPressed(controls[0]) && paddles[0].getPosition().y > paddleSize.y / 2)
	{
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1]) && paddles[0].getPosition().y < gameHeight - paddleSize.y/2)
	{
		direction++;
	}

	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight)
	{
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (by < 0)
	{
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, 10);
	}
	else if (bx > gameWidth)
	{
		reset();
	}
	else if (bx < 0)
	{
		reset();
	}
	else if (bx <= 10 + paddleSize.x && by > paddles[0].getPosition().y - (paddleSize.y * 0.5f) && by < paddles[0].getPosition().y + (paddleSize.y * 0.5f))
	{
		ballVelocity.x *= -1.1f;
	}
	else if (bx > gameWidth - 10 - paddleSize.x && by > paddles[1].getPosition().y - (paddleSize.y * 0.5f) && by < paddles[1].getPosition().y + (paddleSize.y * 0.5f))
	{
		ballVelocity.x *= -1.1f;
	}

	if (paddles[1].getPosition().y > ball.getPosition().y && paddles[1].getPosition().y > paddleSize.y / 2)
	{
		paddles[1].move(0, -paddleSpeed *dt);
	} else if (paddles[1].getPosition().y < ball.getPosition().y  && paddles[1].getPosition().y < gameHeight - paddleSize.y / 2)
	{
		paddles[1].move(0, paddleSpeed *dt);
	}
	paddles[0].move(0, direction * paddleSpeed * dt);
	ball.move(ballVelocity *dt);
}

void Render(RenderWindow &window)
{
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	reset();
	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}