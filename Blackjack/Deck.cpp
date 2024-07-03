#include "Deck.hpp"
#include <algorithm>
#include <random>
#include <chrono>

static const Suit STANDARD_SUIT_LIST[] = { Heart, Spade, Diamond, Club };

Deck::Deck(std::vector<Card> cards)
{
	m_cards.insert(m_cards.end(), cards.begin(), cards.end());
	m_original_cards.insert(m_original_cards.end(), cards.begin(), cards.end());
}

Deck::Deck()
{
	std::vector<Card> cards;
	for (int i = 0; i < sizeof(STANDARD_SUIT_LIST) / sizeof(STANDARD_SUIT_LIST[0]); i++)
	{
		Suit suit = STANDARD_SUIT_LIST[i];
		for (int j = 0; j < sizeof(VALID_CARD_VALUES) / sizeof(VALID_CARD_VALUES[0]); j++)
		{
			char card_value = VALID_CARD_VALUES[j];
			Card card(suit, VALID_CARD_VALUES[j]);
			cards.push_back(card);
		}
	}
	m_cards.insert(m_cards.end(), cards.begin(), cards.end());
	m_original_cards.insert(m_original_cards.end(), cards.begin(), cards.end());
}
Deck::~Deck()
{

}

Card Deck::popTopCard()
{
	Card card = m_cards.back();
	m_cards.pop_back();
	return card;
}
Card Deck::peekTopCard()
{
	return m_cards.back();
}
void Deck::addCard(Card card)
{
	m_cards.push_back(card);
}
void Deck::addDeck(Deck deck)
{
	m_cards.insert(m_cards.end(), deck.m_cards.begin(), deck.m_cards.end());
	m_original_cards.insert(m_original_cards.end(), deck.m_original_cards.begin(), deck.m_original_cards.end());
}
void Deck::resetDeck()
{
	m_cards = m_original_cards;
}
void Deck::resetBaseDeck()
{
	m_original_cards = m_cards;
}
void Deck::shuffle()
{
	auto rng = std::default_random_engine{};
	// make sure the RNG is seeded
	rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(std::begin(m_cards), std::end(m_cards), rng);
}
unsigned int Deck::getDeckSize()
{
	return m_cards.size();
}
Deck Deck::operator+(Card card)
{
	Deck deck = *this;
	deck.addCard(card);
	deck.resetBaseDeck();
	return deck;
}
Deck Deck::operator+(Deck deck)
{
	Deck new_deck = *this;
	new_deck.addDeck(new_deck);
	new_deck.resetBaseDeck();
	return new_deck;
}
void Deck::operator+=(Card card)
{
	this->addCard(card);
}
void Deck::operator+=(Deck deck)
{
	this->addDeck(deck);
}
