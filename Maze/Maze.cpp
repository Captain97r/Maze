#include "Maze.hpp"

Maze::Maze()
{
	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++)
			create_cell(i, j);
}

void Maze::create_cell(int i, int j)
{
	sf::Vector2f right_up = sf::Vector2f((i + 1) * CELL_SIZE, (j)* CELL_SIZE);
	sf::Vector2f right_down = sf::Vector2f((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
	sf::Vector2f left_up = sf::Vector2f((i)* CELL_SIZE, (j)* CELL_SIZE);
	sf::Vector2f left_down = sf::Vector2f((i)* CELL_SIZE, (j + 1) * CELL_SIZE);


	walls[i][j * 2] = sf::Vertex(right_up, sf::Color::White);
	walls[i][(j * 2) + 1] = sf::Vertex(right_down, sf::Color::White);

	floors[i][j * 2] = sf::Vertex(left_up, sf::Color::White);
	floors[i][(j * 2) + 1] = sf::Vertex(right_up, sf::Color::White);
}