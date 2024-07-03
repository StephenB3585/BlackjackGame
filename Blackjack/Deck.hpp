#pragma once
#include <vector>
#include "Card.hpp"
class Deck
{
public:
	Deck();
	Deck(std::vector<Card> cards);
	~Deck();

	void shuffle();
	Card peekTopCard();
	Card popTopCard();
	void addCard(Card card);
	void addDeck(Deck deck);
	void resetDeck();
	void resetBaseDeck();
	unsigned int getDeckSize();
	Deck operator+(Card card);
	Deck operator+(Deck deck);
	void operator+=(Card card);
	void operator+=(Deck deck);
private:
	std::vector<Card> m_cards;
	std::vector<Card> m_original_cards;
};

