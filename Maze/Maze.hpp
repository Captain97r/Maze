#pragma once
#include <SFML/Graphics.hpp>

class Maze
{
	static const int CELL_SIZE = 40;
	static const int MAZE_SIZE = 20;

	sf::Vertex walls[MAZE_SIZE][MAZE_SIZE * 2];
	sf::Vertex floors[MAZE_SIZE][MAZE_SIZE * 2];

public:
	Maze();
	void create_cell(int i, int j);

	sf::Vertex* get_floors() { return reinterpret_cast<sf::Vertex*>(floors); }
	sf::Vertex* get_walls()  { return reinterpret_cast<sf::Vertex*>(walls); }
	const int get_cell_size() { return CELL_SIZE; }
	const int get_maze_size() { return MAZE_SIZE; }
};