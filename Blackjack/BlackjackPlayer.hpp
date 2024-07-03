#pragma once
#include <vector>
#include <string>
#include "BlackjackHand.hpp"
#include "Deck.hpp"
#include "Card.hpp"
class BlackjackPlayer
{
public:
	BlackjackPlayer();
	~BlackjackPlayer();
	void hit(Deck* deck);
	void stand();
	bool hasStanded();
	bool hasBusted();
	bool hasBlackjack();
	BlackjackHand getHand();
	unsigned int getMaxScore();
	std::string toString();
	void resetPlayer();
private:
	BlackjackHand m_hand;
	bool m_has_standed;
};

