#include "hedz.h"


/***********************************************************
 *  array to init the 'new' deck for each game of poker     *
 *  Deck get_new_Deck() returns a deck to the driver which  *
 *  will persist for the life of the game via pass by       *
 *  reference when queue/dequeing occurs                    *
 ***********************************************************/

char *face[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
char *suit[] = { "♠", "♥", "♦", "♣"};

Deck get_new_Deck(){
	 int i;
	 Deck newDeck ;
	 for (i = 0; i<DECK_SIZE; i++){
		  newDeck.deckCards[i].face = face[i % 13];
		  newDeck.deckCards[i].suit = suit[i / 13]; 
	 }
	 newDeck.cardsDealt = 0;
	 newDeck.cardsLeft = DECK_SIZE;

	 return newDeck;
}

/***********************************************************
 *  The shuffle function here is the permute in place algo  *
 *  which serves up a rando position in the range of 1-52   *
 *  for each index which simulates card shuffling via pass  *
 *  by reference of the persisting game deck                *
 ***********************************************************/

void shuffle(Deck *newDeck, int deckSize){
	 int i, j;
	 Card temp;
	 srand(time(NULL));

	 for (i = 0; i<deckSize; i++){
		  j = rand() % deckSize;
		  temp = newDeck->deckCards[i];
		  newDeck->deckCards[i] = newDeck->deckCards[j];
		  newDeck->deckCards[j] = temp;
	 }
}

/***********************************************************
 *  functions dequeue and update represent queuing and      *
 *  dequeuing of the deck. dequeue passes a card back to    *
 *  the calling function while update is void to move a     *
 *  card to the bottom of the deck                          *
 ***********************************************************/

Card dequeue(Deck playDeck){
	 Card next;
	 next =  playDeck.deckCards[0];
	 playDeck.cardsDealt++;
	 playDeck.cardsLeft--;
	 return next;
}


void update(Deck *queue){
	 int i;
	 Card temp;
	 temp = queue->deckCards[0];
	 for(i = 1; i<DECK_SIZE; i++){
		  queue->deckCards[i-1] = queue->deckCards[i];
	 }
	 queue->deckCards[DECK_SIZE-1] = temp;
}

/***********************************************************
 *  first_Deal and exchange use the persisting deck, and    *
 *  Player types to access both the tables hands and the    *
 *  individual player hand to 'deal out' cards for the      *
 *  game play.                                              *
 ***********************************************************/

int first_Deal(Deck *dealer, Player *table[], int numPlayers){
	 int i,j;
	 for (i = 0; i < HAND_SIZE; i++){
		  for(j = 0; j< numPlayers; j++){
				table[j]->hand[i] = dequeue(*dealer);
				update(dealer);		
		  }
	 }
	 return 0;
}

int exchange(Deck *toDeal, Player *person, int cardNum){
	 person->hand[cardNum] = dequeue(*toDeal);
	 update(toDeal);

	 return 0;
}

int exchangeMC(Deck *toDeal, Player *person, int cardNum){
	 person->hand[cardNum] = dequeue(*toDeal);
	 updateMC(toDeal);

	 return 0;
}

void updateMC(Deck *queue){
	 int i;
	 Card temp;
	 temp = queue->deckCards[0];
	 for(i = 1; i<47; i++){
		  queue->deckCards[i-1] = queue->deckCards[i];
	 }
	 queue->deckCards[47-1] = temp;
}


