/**
 * The Game of Master Mind is played as follows:
 * The Computer has four slots containing balls that are red(R), yellow(Y), green(G) or blue(B).
 * For example, the computer might have RGGB(e.g., Slot#1 is red, Slots #2 and #3 are green, Slot #4 is blue)
 * You, the user, are trying to guess the solution.
 */

#include <stdio.h>

typedef struct result {
	int hits;
	int pseudo_hits;
} result;

void estimate(char *solution, char *guess)
{
	result res;
	res.hits = res.pseudo_hits = 0;
	int i, solution_mask = 0;

	for (i = 0; i < 4; i ++) {
		solution_mask |= 1 << (solution[i] - 'A');
	}

	for (i = 0; i < 4; i ++) {
		if (solution[i] == guess[i])
			res.hits ++;
		else if (solution_mask & (1 << (guess[i] - 'A')))
			res.pseudo_hits ++;
	}

	printf("The guess %s has %d hits and %d preudo hits\n", guess, res.hits, res.pseudo_hits);
}


int main(void)
{
	char *solution = "RYGB";
	char guess[5];

	while (scanf("%s", guess) != EOF) {
		estimate(solution, guess);			
	}	

	return 0;
}
