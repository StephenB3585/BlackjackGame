#include "Card.hpp"
#include "Deck.hpp"
#include "BlackjackHand.hpp"
#include <iostream>
#include <string>


int main()
{
	Card card1(Spade, 'A');
	Card card2(Heart, 'A');
	BlackjackHand hand;
	hand += card1;
	hand += card2;
	std::cout << "Hand: " << std::endl << hand.toString() << std::endl << "Score = " << hand.scoresToString() << std::endl;
	return 0;
}


