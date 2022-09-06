/*#include"Resources.h"

#include "Direction.h"

#include <stdexcept>

namespace
{
	AnimationData redGhostData()
	{
		const auto size = sf::Vector2i(40, 40);
		const auto initSpace = sf::Vector2i(1, 2);
		const auto middleSpace = sf::Vector2i(0, 10);

		auto redGhost = AnimationData{};
		auto currentStart = initSpace;

		auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.y += size.y;
			return currentStart;
		};

		redGhost.m_data[Direction::Right].emplace_back(currentStart, size);
		redGhost.m_data[Direction::Right].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Down].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Down].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Left].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Left].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Up].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Up].emplace_back(nextStart(), size);

		return redGhost;
	}

	AnimationData pacmanData()
	{
		const auto size = sf::Vector2i(40, 40);
		const auto initSpace = sf::Vector2i(851, 2);
		const auto middleSpace = sf::Vector2i(0, 10);

		auto pacman = AnimationData{};
		auto currentStart = initSpace;

		auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.y += size.y;
			return currentStart;
		};

		pacman.m_data[Direction::Right].emplace_back(currentStart, size);
		pacman.m_data[Direction::Right].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Right].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Up].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Up].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Up].emplace_back(nextStart(), size);

		return pacman;
	}
}

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

Resources::Resources()
	: m_data(Max)
{
	if (!m_texture.loadFromFile("Pacman.png"))
	{
		throw std::runtime_error("Can't load file");
	}
	m_data[Pacman] = pacmanData();
	m_data[RedGhost] = redGhostData();
}*/
