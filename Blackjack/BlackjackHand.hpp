#pragma once
#include <vector>
#include <string>
#include "Card.hpp"

#define MAX_BLACKJACK_SCORE 21

class BlackjackHand
{
public:
	BlackjackHand();
	~BlackjackHand();
	void addCard(Card card);
	unsigned int getNumberCards();
	Card popLastCard();

	unsigned int getMinScore();
	bool isBlackjack();
	bool isBust();
	std::vector<unsigned int> getScores();
	std::string toString();
	std::string scoresToString();
	BlackjackHand operator+(Card card);
	void operator+=(Card card);
private:
	std::vector<Card> m_cards;
	unsigned int m_score;
	unsigned int m_number_aces;
};

