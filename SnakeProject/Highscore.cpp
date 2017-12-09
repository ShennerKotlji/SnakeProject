#include "Highscore.h"
#include "Snake.h"
#include <string>
#include <sstream>
#include <fstream>


Highscore::Highscore()
{
	this->score = 0;
	this->count = 0;
	Candara.loadFromFile("Candara.ttf");
	scoreTxt.setCharacterSize(30);
	scoreTxt.setPosition(10, 10);
	scoreTxt.setFont(Candara);
	scoreTxt.setFillColor(sf::Color::White);



	for (int i = 0; i < 10; i++) {

		scoreArr[i] = -1;
	}

}

Highscore::~Highscore()
{
}

void Highscore::addScore()
{

	if (count == TopScores)
	{

		for (int i = count - 1; i >= 0; i--)
		{
			if (scoreArr[i] < getScore())
			{
				scoreArr[i] = getScore();
				i = -1;
			}
		}
	}

	else
	{
		scoreArr[count] = getScore();
		count++;

	}

	sortAll();
}

void Highscore::setScore(int points)
{
	score = score + points;

	scoreTxt.setString(ToString());
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

			if (scoreArr[i] < scoreArr[i + 1]) {

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

void Highscore::SaveToFile()
{
	addScore();
	std::ofstream fout("highscore.txt");
	fout << count << std::endl;

	for (int i = 0; i < count; i++) {

		fout << scoreArr[i] << std::endl;
	}

}

void Highscore::ReadFromFile()
{

	Highscore ToAdd;

	std::ifstream fileIn("highscore.txt");
	if (fileIn.is_open()) 
	{
		fileIn >> count;
		fileIn.ignore();
		for (int i = 0; i < count; i++)
		{
			int points;
			fileIn >> points;
			fileIn.ignore();
			scoreArr[i] = points;
			
		}

	}
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





