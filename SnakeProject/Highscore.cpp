#include "Highscore.h"
#include "Snake.h"
#include <string>
#include <sstream>


Highscore::Highscore(sf::Font &textType)
{
	scoreTxt.setCharacterSize(30);
	scoreTxt.setPosition(10, 10);
	scoreTxt.setFont(textType);
	scoreTxt.setString(ToString());
	

	for (int i = 0; i < 10; i++) {

		scoreArr[i] = -1;
	}

}

Highscore::~Highscore()
{
}

void Highscore::addScore(int result)
{

	if (count == TopScores)
	{

		for (int i = count - 1; i >= 0; i--)
		{
			if (scoreArr[i] < result)
			{
				scoreArr[i] = result;
				i = -1;
			}
		}
		
	}

	else 
	{
		scoreArr[count] = result;
		count;;
		
	}

	sortAll();
}

void Highscore::setScore(int points)
{
	this->score = this->score + points;
}

void Highscore::GameOver()
{
}

void Highscore::sortAll()
{
	bool sorted = false;

	while (sorted == false)

	{
		sorted = true;
		for (int i = 0; i < count - 1; i++) {

			if (scoreArr[i] > scoreArr[i + 1]) {

				std::swap(scoreArr[i], scoreArr[i + 1]);
				sorted = false;
			}

		}

	}
}

void Highscore::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(scoreTxt);
}



std::string Highscore::ToString() const
{
	std::stringstream ss;
	ss << "Score: " << getScore();

	return ss.str();
}

int Highscore::getScore() const
{
	return score;
}




