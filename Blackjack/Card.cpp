#include "Card.hpp"
#include <string>

Card::Card(Suit suit, char card_value)
{
	std::string valid_strings = VALID_CARD_VALUES;

	if (valid_strings.find(card_value) == std::string::npos)
	{
		m_card_value = VALID_CARD_VALUES[0];
	}
	else
	{
		m_card_value = card_value;
	}
	m_suit = suit;
}

Card::~Card()
{

}

Suit Card::getSuit()
{
	return m_suit;
}
std::string Card::getSuitString()
{
	std::string suit_string;
	switch (m_suit)
	{
	case Heart:
		suit_string = "Heart";
		break;
	case Spade:
		suit_string = "Spade";
		break;
	case Diamond:
		suit_string = "Diamond";
		break;
	case Club:
		suit_string = "Club";
		break;
	case Joker:
		suit_string = "Joker";
		break;
	}
	return suit_string;
}
std::string Card::getCardValueString()
{
	std::string value_string;
	switch (m_card_value)
	{
	case 'A':
		value_string = "Ace";
		break;
	case 'K':
		value_string = "King";
		break;
	case 'Q':
		value_string = "Queen";
		break;
	case 'J':
		value_string = "Jack";
		break;
	case '0':
		value_string = "10";
		break;
	default:
		value_string = m_card_value;
		break;
	}
	return value_string;
}
std::string Card::toString()
{
	std::string return_string = this->getCardValueString() + " of " + this->getSuitString() + "s";
	return return_string;
}
char Card::getCardValue()
{
	return m_card_value;
}