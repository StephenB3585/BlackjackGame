#include "BlackjackPlayer.hpp"

BlackjackPlayer::BlackjackPlayer()
{
	m_has_standed = false;
}

BlackjackPlayer::~BlackjackPlayer()
{
}

void BlackjackPlayer::hit(Deck* deck)
{
	m_hand.addCard(deck->popTopCard());
}

void BlackjackPlayer::stand()
{
	m_has_standed = true;
}

bool BlackjackPlayer::hasStanded()
{
	return m_has_standed;
}

bool BlackjackPlayer::hasBusted()
{
	return m_hand.isBust();
}

bool BlackjackPlayer::hasBlackjack()
{
	return m_hand.isBlackjack();
}

BlackjackHand BlackjackPlayer::getHand()
{
	return m_hand;
}

unsigned int BlackjackPlayer::getMaxScore()
{
	std::vector<unsigned int> scores = m_hand.getScores();
	unsigned int max_val = scores[0];
	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i] > max_val)
		{
			max_val = scores[i];
		}
	}
	return max_val;
}

std::string BlackjackPlayer::toString()
{
	return m_hand.toString();
}

void BlackjackPlayer::resetPlayer()
{
	m_has_standed = false;
	m_hand = BlackjackHand();
}
