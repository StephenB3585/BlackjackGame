#include "Card.hpp"
#include "Deck.hpp"
#include "BlackjackPlayer.hpp"
#include <iostream>
#include <string>

#define DEALER_STAND_VALUE 17

#define HIT_STRING "Hit"
#define STAND_STRING "Stand"

#define CONTINUE_GAME_STRING "Y"
#define END_GAME_STRING "N"

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
		// Player Turn
		do 
		{
			std::cout << "Type [" << HIT_STRING << "] to hit, [" << STAND_STRING << "] to stand: ";
			std::string user_input;
			std::cin >> user_input;

			if (!user_input.compare(HIT_STRING))
			{
				player.hit(&deck);
			}
			else if (!user_input.compare(STAND_STRING))
			{
				std::cout << "Standed" << std::endl;
				player.stand();
			}
			else
			{
				std::cout << "Invalid Input" << std::endl;
			}
			std::cout << "Your Hand: " << std::endl << player.toString() << std::endl;
			std::cout << "Your Score: " << player.scoreToString() << std::endl;
		} while (!player.hasBusted() && !player.hasStanded());

		// Dealer turn
		while (!dealer.hasBusted() && !dealer.hasStanded())
		{
			bool stand_condition = dealer.getMaxScore() >= DEALER_STAND_VALUE;
			if (stand_condition)
			{
				dealer.stand();
			}
			else
			{
				dealer.hit(&deck);
				std::cout << "Dealer Hand: " << std::endl << dealer.toString() << std::endl;
				std::cout << "Dealer Score: " << dealer.scoreToString() << std::endl;
			}
		}

		// results
		std::cout << "Your Score: " << player.scoreToString() << std::endl;
		std::cout << "Dealer Score: " << dealer.scoreToString() << std::endl;
		bool dealer_bust = dealer.hasBusted();


		if (player.hasBusted() || ((dealer.getMaxScore() > player.getMaxScore()) && !dealer.hasBusted()))
		{
			std::cout << "You Lose!" << std::endl;
		}
		else if (dealer.hasBusted() || (player.getMaxScore() > dealer.getMaxScore()))
		{
			std::cout << "You won!" << std::endl;
		}
		else
		{
			std::cout << "Tie game!" << std::endl;
		}

		// play again?
		bool valid_end_game = false;
		while (!valid_end_game)
		{
			std::cout << "Play again? [" << CONTINUE_GAME_STRING << "] for Yes, [" << END_GAME_STRING << "] for No: ";
			std::string play_again_string;
			std::cin >> play_again_string;
			if (!play_again_string.compare(CONTINUE_GAME_STRING))
			{
				player.resetPlayer();
				dealer.resetPlayer();
				deck.resetDeck();
				valid_end_game = true;
			}
			else if (!play_again_string.compare(END_GAME_STRING))
			{
				done = true;
				valid_end_game = true;
			}
			else
			{
				std::cout << "Invalid response" << std::endl << std::endl;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}


