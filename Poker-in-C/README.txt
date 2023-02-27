------
Prologue
------
We use the code we have found from:
https://github.com/stvschmdt/Draw_Poker_C

Then we edit / modify the name of the currency and the players name.
Thanks for the creator of this game, it is very fun.

------
Copyright
------
Steve Schmidt
steveschmidt

------
TO RUN
------
From the directory containing the files of the game, open terminal then type:

~$ (sudo) make
~$./poker

/*makefile is included, running make will compile necessary files and executables and ./poker will begin the program*/

-------------------------------
Poker in C Programming Language
-------------------------------

5-card draw poker application in C using 3 simulated players and one "live" player (the user). 5-card draw: en.wikipedia.org/woki/Five-card_draw.

----------
GAME LOGIC
----------

The game logic is as follows:

*create a deck of cards
*shuffle the deck
*deal five cards to each of the four players
*loop over each of the three automated players and have them make a decision on which cards (if any) to exchange * using an AI decision making process. Monte Carlo simulation of all possible hands, resulting in a ranking of each hand and thus a decision on the probable best move.
*request input from live player (MC simulator will advise live player as well). MC advisor should advise on the absolute quality of the best move.
*compare the hands and determine a winner
*wraps the above single hand simulator in a game loop which allows for a round of betting at each hand, eliminates players when they fold, etc.


-------------------
AXIOMS OF THE GAME
-------------------

 --running out of money:
 		-players do not run out of money, treated like a cash game where funds are restored as a 'loan' or additional 'buy in'
		-this is displayed to the player as a decision function of the game and handled appropriately in the sequence

 --player rotation
 		-no player rotation, the user player is always first dealt and first to bet/fold
		-if a raise occurs by a cpu player, cpu players acting after them bet the original amount or raise


Notes on Abstractions:

Poker.c
	--this is the driver file which contains the game loop, it serves as initially calls to init functions for the table and holds only a few variables regarding the status of the game
	--the control flow of this file within the loop is straightforward and pedantic at times for testing and readability into the 'axiomatic rules' of this particular poker game

Cards.c
	--very simple init function for cards structs


Player.c
	--simple init for player struct
	--player folding logical functions
	--table statuses


Interface.c
	--the interface file contains stdout functions which are very gameplay related, but contain 90% of the actual stdio between user and game.
	--this file also contains ascii art and player banter to simulate chatter during play
	--betAmount is the most robust function, some notes on it:
			-a player can only bet if they are in the game
			-if they enter the loop with 0 rupies, they are granted a 'loan' and asked to fill their pockets like in the initialization
			-if they fold, their position and game status are updated
			-if a player calls a bet with less funds than they have, they only call the amount currently in posession


Analysis.c
	--all hand evaluations are handled here in 3 section functions:
			-numerical valuation
			-printf statement based off valuation
			-high card tie determination based off two players having same top pair, high card, etc, the usual tie breakers are handled here
	--cpuActions and cpuBets are auto play functions for the computer player with some randomness involved
	--***EXTRA***cpuBets uses rand to randomly raise


Monte.c
	--monte carlo simulation run on MCTRIALS amount of runs on each of the 32 hand options, the decision to disclude no cards exchanged was nixed based off it returning the best option
	--best ave, best type of hand, ***EXTRA***probability of said hand occuring and trial info is stored in player struct and displayed
	--all runs are made on a dummy deck and dummy hand



