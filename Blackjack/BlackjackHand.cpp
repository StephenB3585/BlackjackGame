#include "BlackjackHand.hpp"
#include <map>

#define ACE 'A'
#define ACE_OFFSET 10

static const std::map<char, int> score_map =
{
	{'A', 1},
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
	{'0', 10},
	{'J', 10},
	{'Q', 10},
	{'K', 10}
};

BlackjackHand::BlackjackHand()
{
	m_score = 0;
	m_number_aces = 0;
}
BlackjackHand::~BlackjackHand()
{

}

void BlackjackHand::addCard(Card card)
{
	// need to check for ace when calculating scores in other functions
	if (card.getCardValue() == ACE)
	{
		m_number_aces++;
	}
	m_score += score_map.at(card.getCardValue());
	m_cards.push_back(card);
}
unsigned int BlackjackHand::getNumberCards()
{
	return m_cards.size();
}
Card BlackjackHand::popLastCard()
{
	Card card = m_cards.back();
	m_cards.pop_back();
	return card;
}
unsigned int BlackjackHand::getMinScore()
{
	return m_score;
}
std::vector<unsigned int> BlackjackHand::getScores()
{
	std::vector<unsigned int> scores;
	scores.push_back(m_score);
	for (int i = 0; i < m_number_aces; i++)
	{
		unsigned int new_score = m_score + ACE_OFFSET * (i + 1);

		// only consider scores less than or equal to blackjack
		// and non repeat scores
		if (new_score <= MAX_BLACKJACK_SCORE && std::find(scores.begin(), scores.end(), new_score) == scores.end())
		{
			scores.push_back(new_score);
		}
	}
	return scores;
}
bool BlackjackHand::isBlackjack()
{
	std::vector<unsigned int> scores = this->getScores();
	for (int i = 0; i < scores.size(); i++)
	{
		// we found a blackjack
		if (scores[i] == MAX_BLACKJACK_SCORE)
		{
			return true;
		}
	}
	// we did not find a blackjack, return false
	return false;
}

bool BlackjackHand::isBust()
{
	return (m_score > MAX_BLACKJACK_SCORE);
}
BlackjackHand BlackjackHand::operator+(Card card)
{
	BlackjackHand new_hand = *this;
	new_hand.addCard(card);
	return new_hand;
}
void BlackjackHand::operator+=(Card card)
{
	this->addCard(card);
}
std::string BlackjackHand::toString()
{
	std::string return_string;
	for (int i = 0; i < m_cards.size(); i++)
	{
		return_string += m_cards[i].toString() + '\n';
	}
	return return_string;
}
std::string BlackjackHand::scoresToString()
{
	std::vector<unsigned int> scores = this->getScores();
	std::string return_string;
	for (int i = 0; i < scores.size(); i++)
	{
		if (i > 0)
		{
			return_string += "/";
		}
		return_string += std::to_string(scores[i]);
	}
	return return_string;
}

