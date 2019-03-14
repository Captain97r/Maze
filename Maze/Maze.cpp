#include "stdafx.h"
#include <random>
#include <SFML/Graphics.hpp>

const int CELL_SIZE = 40;
const int MAZE_SIZE = 20;

const int SPEED = 20;							//less is faster

sf::Vertex walls[MAZE_SIZE][MAZE_SIZE * 2];
sf::Vertex floors[MAZE_SIZE][MAZE_SIZE * 2];

sf::Clock clk;

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

void createCell(int i, int j);
void deleteCellWall(int i, int j);
void deleteCellFloor(int i, int j);
void BinaryTreeAlg(int i, int j);

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(CELL_SIZE * MAZE_SIZE, CELL_SIZE * MAZE_SIZE), "Maze");

	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++)
			createCell(i, j);

	int i = 0;

	sf::RectangleShape current = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	current.setFillColor(sf::Color::Green);
	current.setPosition(sf::Vector2f(0, 0));

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
			BinaryTreeAlg(i % MAZE_SIZE, i / MAZE_SIZE);
			i++;
			clk.restart();
		}
		else if (i >= MAZE_SIZE * MAZE_SIZE)
		{
			current.setPosition(sf::Vector2f(-100, -100));
			i++;
		}

		window->clear();
		window->draw(reinterpret_cast<sf::Vertex*>(walls), 2 * MAZE_SIZE * MAZE_SIZE, sf::Lines);
		window->draw(reinterpret_cast<sf::Vertex*>(floors), 2 * MAZE_SIZE * MAZE_SIZE, sf::Lines);
		window->draw(current);
		window->display();
	}

	return 0;
}


void createCell(int i, int j)
{
	sf::Vector2f right_up   = sf::Vector2f((i + 1) * CELL_SIZE, (j)     * CELL_SIZE);
	sf::Vector2f right_down = sf::Vector2f((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
	sf::Vector2f left_up    = sf::Vector2f((i)     * CELL_SIZE, (j)     * CELL_SIZE);
	sf::Vector2f left_down  = sf::Vector2f((i)     * CELL_SIZE, (j + 1) * CELL_SIZE);


	walls[i][j * 2]		   = sf::Vertex(right_up, sf::Color::White);
	walls[i][(j * 2) + 1]  = sf::Vertex(right_down, sf::Color::White);

	floors[i][j * 2]	   = sf::Vertex(left_up, sf::Color::White);
	floors[i][(j * 2) + 1] = sf::Vertex(right_up, sf::Color::White);
}

void deleteCellWall(int i, int j)
{
	walls[i][j * 2] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
	walls[i][j * 2 + 1] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
}

void deleteCellFloor(int i, int j)
{
	floors[i][j * 2] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
	floors[i][j * 2 + 1] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
}

void BinaryTreeAlg(int i, int j)
{
	if (i == MAZE_SIZE - 1 && j == 0) return;
	else if (i == MAZE_SIZE - 1) deleteCellFloor(i, j);
	else if (j == 0) deleteCellWall(i, j);
	else dist(rng) == 0 ? deleteCellFloor(i, j) : deleteCellWall(i, j);
}
