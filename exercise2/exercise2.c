#include <stdio.h>

int main(){
	int score;
	//Using a while loop to continue prompting the user
	while (1){
		printf("Enter the NFL score: ");
		scanf("%d", &score);
		
		//Here is our stop function
		if (score <=1){
			printf("Enter 0 or 1 to Stop\n");
			break;
		}

		printf("Possible combination of scoring plays:\n");
		
		//By using nested for loops, we are able to count the amount that it takes of each of the ways to score to reach the score, it is then printed to the user
		for (int td = 0; td*6 <= score; td++){
			for (int fg = 0; fg*3 <= score; fg++){
				for (int safety = 0; safety*2 <= score; safety++){
					int total_score = td*6+fg*3+safety*2;

					if (total_score == score){
						printf("%d TD, %d FG, %d Safety\n", td, fg, safety);
					}
				}
			}
		}
	}

	return 0;
}

