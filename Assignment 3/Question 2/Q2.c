#include <stdio.h>

struct Player 
{
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

void playGame(struct Player *player) 
{
    player->totalScore = 0;
    printf("Enter scores for %s:\n", player->playerName);
    for (int i = 0; i < 12; i++) 
    {
        printf("Enter score for ball %d (0 to 6): ", i + 1);
        int score;
        scanf("%d", &score);
        if (score >= 0 && score <= 6) 
        {
            player->ballScores[i] = score;
            player->totalScore += score;
        } 
        else 
        {
            printf("Invalid score! Score for this ball will be ignored.\n");
            player->ballScores[i] = 0;
        }
    }
}

void findWinner(struct Player player1, struct Player player2) 
{
    printf("\nMatch Result:\n");
    printf("Player 1 (%s) Score: %d\n", player1.playerName, player1.totalScore);
    printf("Player 2 (%s) Score: %d\n", player2.playerName, player2.totalScore);

    if (player1.totalScore > player2.totalScore) 
    {
        printf("Winner: %s\n", player1.playerName);
    } 
    else if (player2.totalScore > player1.totalScore) 
    {
        printf("Winner: %s\n", player2.playerName);
    } 
    else 
    {
        printf("It's a tie!\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) 
{
    printf("\nMatch Scoreboard:\n");
    printf("\n");
    printf("Player 1 (%s): Total Score = %d\n", player1.playerName, player1.totalScore);
    printf("Player 2 (%s): Total Score = %d\n", player2.playerName, player2.totalScore);
    
    printf("\nIndividual Ball Scores:\n");
    printf("Player 1 Scores: ");
    for (int i = 0; i < 12; i++) 
    {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\n");

    printf("Player 2 Scores: ");
    for (int i = 0; i < 12; i++) 
    {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\n");
}

int main() 
{
    struct Player player1, player2;

    printf("Enter name for Player 1: ");
    fgets(player1.playerName, 50, stdin);

    printf("Enter name for Player 2: ");
    fgets(player2.playerName, 50, stdin);

    playGame(&player1);
    playGame(&player2);

    findWinner(player1, player2);
    displayMatchScoreboard(player1, player2);

    return 0;
}
