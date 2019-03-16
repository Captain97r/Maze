#pragma once

#include <random>
#include <SFML/Graphics.hpp>

static class Generator
{
	static void delete_cell_wall(int i, int j, sf::Vertex* walls, const int MAZE_SIZE);
	static void delete_cell_floor(int i, int j, sf::Vertex* floors, const int MAZE_SIZE);

public:
	static void BinaryTreeAlg(int i, int j, sf::Vertex* walls, sf::Vertex* floors, const int MAZE_SIZE);
	static void Sidewalker(int i, int j, sf::Vertex* walls, sf::Vertex* floors, const int MAZE_SIZE);
};