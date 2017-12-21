#include "Highscore.h"
#include "Snake.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Highscore::Highscore()
{
	//this->score = 0;
	this->count = 0;
	Candara.loadFromFile("Candara.ttf");
	scoreTxt.setCharacterSize(30);
	scoreTxt.setPosition(10, 10);
	scoreTxt.setFont(Candara);
	scoreTxt.setFillColor(sf::Color::White);
	scoreTxt.setString(ToString());

	for (int i = 0; i < 11; i++) {

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
	
	this->score = this->score + 1;
	scoreTxt.setString(ToString());
	
}

void Highscore::PrintTop10()
{
	showingHighscores = true;
	int score;
	std::stringstream ss;
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		count = count + 20;
		score = scoreArr[i];
		textArr[i].setCharacterSize(20);
		textArr[i].setString("Score: " + to_string(score));
		textArr[i].setPosition(200, 80 + count);
		textArr[i].setFont(Candara);
		textArr[i].setFillColor(sf::Color::White);
	}

	textArr[10].setCharacterSize(25);
	textArr[10].setString("PRESS ENTER TO RETURN TO THE MENU");
	textArr[10].setFillColor(sf::Color::Red);
	textArr[10].setFont(Candara);
	textArr[10].setPosition(28, 40);

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
	if (showingHighscores == true) {

		for (int i = 0; i < 11; i++)
		{

			target.draw(textArr[i]);
		}
	}

	else 
	{
	target.draw(scoreTxt);
	}
	
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
	ss << "Score: " << score;

	return ss.str();
}

int Highscore::getScore() const
{
	return this->score;
}





