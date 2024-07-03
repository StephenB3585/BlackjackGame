#pragma once
#include <string>

// here, 0 represents 10
static const char VALID_CARD_VALUES[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
typedef enum Suit
{
	Heart,
	Spade,
	Diamond,
	Club,
	Joker
};

class Card
{
public:
	Card(Suit suit, char card_value);
	~Card();

	Suit getSuit();
	std::string getSuitString();
	char getCardValue();
	std::string getCardValueString();

	std::string toString();

private:
	Suit m_suit;
	char m_card_value;

};

