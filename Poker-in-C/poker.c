#include "hedz.h"

int main(){

	 int bets = 0, pot = 0;

	 Deck game_deck = get_new_Deck();
	 printf("\n\n");
	 hBorder();	 
	 printf("\n\n");
	 welcomeSign();
	 hBorder();	 
	 welcome();
	 printf("\n");
	 hBorder();
	 printf("\n");
	 printf("\n");

	 Player one = player_init(getName(), getGold());
	 printf("Hi %s, you have %i gold\n",one.name, one.gold);
	 Player two = player_init("Lasthrim", one.gold);
	 Player three = player_init("Mischkra", one.gold);
	 Player four = player_init("Hamzst", one.gold);
	 getStatus(&two);
	 getStatus(&three);
	 getStatus(&four);
	 printf("\n\n");
	 hBorder();	 

	 Player *table[NUM_PLAYERS];
	 table[0] = &one;
	 table[1] = &two;
	 table[2] = &three;
	 table[3] = &four;

	 int gamenumber = 1;
	 int gamesplayed = 0;
	 int gameStatus = 1;
	 while(gamenumber == 1){

		  if(gameStatus == 1){ 
				if(gamesplayed != 0){
					 printf("\n\n");
					 welcomeSign();
					 hBorder();	 
				}
				gamesplayed++;
				printf("\n\nREADY -- Here we go...\n\n");
				shuffle(&game_deck, DECK_SIZE);
				first_Deal(&game_deck, table, NUM_PLAYERS);
				gamescene(3, table);

				print_Hand(table, 1);
				isHand(one.hand);
				bets = betAmount(&one);
				printf("%s, bets %i gold\n",one.name, bets);
				pot += bets;
				/*	cpuBIGACTION(table, &bets, &game_deck);

#pragma omp parallel num_threads(4)
int z;
tid = omp_get_thread_number();
for(z=1;z<NUM_PLAYERS;z++){
if(tid == 1){
				 */		  pot += cpuActions(&game_deck, &two, &one, bets); 
				/*	 }
					 if(tid == 1){
				 */		  
				printf("...hmm...yea...\n");
				pot += cpuActions(&game_deck, &three, &one, bets); 
				/*	 }
					 if(tid == 1){
				 */		  
				printf("...uhhh...ok...\n");
				pot += cpuActions(&game_deck, &four, &one, bets); 
				/*	 }
					 }*/
				hBorder();
				banter(table);
				playersLeft(table, &gameStatus);
		  }
		  if(gameStatus ==1){
				print_Hand(table, 1);
				print_Options();
				isHand(one.hand);

				Deck MC_Deck = create_Monte(&one);
				monteSuggest(monte_Analysis(&MC_Deck, &one));
				printTextReco(&one);

				newCards(&game_deck,&one);
				print_Hand(table, 1);
				isHand(one.hand);
				printf("\n\n");
				bets = betAmount(&one);
				pot += bets;
				pot += cpuBets(&two, &one, bets);
				pot += cpuBets(&three, &one, bets);
				pot += cpuBets(&four, &one, bets);


				playersLeft(table, &gameStatus);
		  }
		  hBorder();
		  printResults(table);
		  evaluateHands(table); 
		  tableCompareTo(table);

		  winnerIs(table, pot);
		  hBorder();
		  printf("\n");
		  banter(table);
		  getTableStatus(table);

		  gamenumber = playgame();
		  printf("\n\n\n\n");
		  bets = 0;
		  pot = 0;
		  tableRefresh(table);
	 }
	 return 0;
}
