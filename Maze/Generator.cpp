#include "Generator.hpp"


void Generator::delete_cell_wall(int i, int j, sf::Vertex* walls, const int MAZE_SIZE)
{
	walls[(i * MAZE_SIZE * 2) + j * 2] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
	walls[(i * MAZE_SIZE * 2) + j * 2 + 1] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
}

void Generator::delete_cell_floor(int i, int j, sf::Vertex* floors, const int MAZE_SIZE)
{
	floors[(i * MAZE_SIZE * 2) + j * 2] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
	floors[(i * MAZE_SIZE * 2) + j * 2 + 1] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Transparent);
}


void Generator::BinaryTreeAlg(int i, int j, sf::Vertex * walls, sf::Vertex * floors, const int MAZE_SIZE)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

	if (i == MAZE_SIZE - 1 && j == 0) return;
	else if (i == MAZE_SIZE - 1) delete_cell_floor(i, j, floors, MAZE_SIZE);
	else if (j == 0) delete_cell_wall(i, j, walls, MAZE_SIZE);
	else dist(rng) == 0 ? delete_cell_floor(i, j, floors, MAZE_SIZE) : delete_cell_wall(i, j, walls, MAZE_SIZE);
}

void Generator::Sidewalker(int i, int j, sf::Vertex * walls, sf::Vertex * floors, const int MAZE_SIZE)
{

}
