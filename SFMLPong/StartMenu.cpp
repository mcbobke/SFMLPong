#include "StartMenu.hpp"
#include "MainGameState.hpp"

void StartMenu::Initialize(sf::RenderWindow *window)
{
	font = sf::Font();
	font.loadFromFile("retganon.ttf");

	titleText = sf::Text("SFMLPong", font, 20);
	titleText.setColor(sf::Color::White);

	startButton = Button("Start", font, 30,  sf::Vector2f(400, 200), window);
	quitButton = Button("Quit", font, 30, sf::Vector2f(400, 300), window);
}

void StartMenu::Update(sf::RenderWindow *window)
{
	if (startButton.isClicked())
	{
		stateManager.SetState(new MainGameState());
	}
	else if (quitButton.isClicked())
	{
		stateManager.SetState(nullptr);
	}
}

void StartMenu::Render(sf::RenderWindow *window)
{
	window->clear();
	window->draw(titleText);
	startButton.draw(window);
	quitButton.draw(window);
	window->display();
}

void StartMenu::Destroy(sf::RenderWindow *window)
{

}