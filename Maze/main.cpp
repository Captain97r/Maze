#include <random>
#include <SFML/Graphics.hpp>
#include "Maze.hpp"
#include "Generator.hpp"

const int SPEED = 20;							//less is faster

sf::Clock clk;

int main()
{
	Maze maze = Maze();

	const int CELL_SIZE = maze.get_cell_size();
	const int MAZE_SIZE = maze.get_maze_size();

	sf::Vertex* floors = maze.get_floors();
	sf::Vertex* walls  = maze.get_walls();

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(CELL_SIZE * MAZE_SIZE, CELL_SIZE * MAZE_SIZE), "Maze");

	sf::RectangleShape current = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	current.setFillColor(sf::Color::Green);
	current.setPosition(sf::Vector2f(0, 0));
	
	int i = 0;

	while (window->isOpen())
	{
		float time = clk.getElapsedTime().asMilliseconds();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		if (time > SPEED && i < MAZE_SIZE * MAZE_SIZE)
		{
			current.setPosition(sf::Vector2f(((i % MAZE_SIZE) * CELL_SIZE - 1), ((i / MAZE_SIZE) * CELL_SIZE) - 1));
			Generator::BinaryTreeAlg(i % MAZE_SIZE, i / MAZE_SIZE, walls, floors, MAZE_SIZE);
			i++;
			clk.restart();
		}
		else if (i >= MAZE_SIZE * MAZE_SIZE)
		{
			current.setPosition(sf::Vector2f(-100, -100));
			i++;
		}

		window->clear();
		window->draw(floors, 2 * MAZE_SIZE * MAZE_SIZE, sf::Lines);
		window->draw(walls, 2 * MAZE_SIZE * MAZE_SIZE, sf::Lines);
		window->draw(current);
		window->display();
	}

	return 0;
}