#include "Card.hpp"
#include "Deck.hpp"
#include "BlackjackPlayer.hpp"
#include <iostream>
#include <string>


int main()
{
	Deck deck;
	// we need 6 standard decks for Blackjack
	for (int i = 0; i < 5; i++)
	{
		deck += Deck();
	}
	// make sure the base deck is our standard blackjack 6 decks
	deck.resetBaseDeck();
	BlackjackPlayer dealer;
	BlackjackPlayer player;
	bool done = false;
	while (!done)
	{
		deck.shuffle();

		std::cout << "Time to play blackjack!" << std::endl << std::endl;
		player.hit(&deck);
		dealer.hit(&deck);
		player.hit(&deck);
		dealer.hit(&deck);
		std::cout << "Dealer Hand: " << std::endl << dealer.toString() << std::endl;
		std::cout << "Dealer Score: " << dealer.scoreToString() << std::endl;
		std::cout << std::endl;
		std::cout << "Your Hand: " << std::endl << player.toString() << std::endl;
		std::cout << "Your Score: " << player.scoreToString() << std::endl;
		done = true;
	}
	return 0;
}


