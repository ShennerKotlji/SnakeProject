#pragma once
#define HIGHSCORE_H
#include <SFML\Graphics.hpp>

class Highscore : public sf::Drawable
{
public:
	Highscore();
	~Highscore();

	void addScore(int result);
	void setScore(int points);
	void GameOver();
	void sortAll();
	void draw(sf::RenderTarget & target, sf::RenderStates state) const;

	std::string ToString() const;
	int getScore() const;


private:
	int scoreArr[10];
	int score;
	const int TopScores = 10;
	int count;
	sf::Text scoreTxt;
	sf::Font Candara;


};