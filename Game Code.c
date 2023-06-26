// NAME OF THE GAME : RUN THE DIAMOND IS UNSAFE!
// MY CODE ADAPTS THE IDEA OF A TREASURE HUNT GAME BUT IS PATTERNED TOWARDS USING CLUES IN ORDER TO SURVIVE A FLOOD HAPPENING A THTE DIAMOND, A SCHOOL BUILDING IN SHEFFIELD.
// AUTHOR: POWELL LONGJOHN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CREATING THE LAYOUT OF THE GAME
            void print_TheDiamondmap(char TheDiamondmap[5][5]) {
            printf("\n--1--2--3--4--5-\n");
            printf("1[%c][%c][%c][%c][%c]\n",TheDiamondmap[0][0],TheDiamondmap[0][1],TheDiamondmap[0][2],TheDiamondmap[0][3],TheDiamondmap[0][4]);
            printf("2[%c][%c][%c][%c][%c]\n",TheDiamondmap[1][0],TheDiamondmap[1][1],TheDiamondmap[1][2],TheDiamondmap[1][3],TheDiamondmap[1][4]);
            printf("3[%c][%c][%c][%c][%c]\n",TheDiamondmap[2][0],TheDiamondmap[2][1],TheDiamondmap[2][2],TheDiamondmap[2][3],TheDiamondmap[2][4]);
            printf("4[%c][%c][%c][%c][%c]\n",TheDiamondmap[3][0],TheDiamondmap[3][1],TheDiamondmap[3][2],TheDiamondmap[3][3],TheDiamondmap[3][4]);
            printf("5[%c][%c][%c][%c][%c]\n\n",TheDiamondmap[4][0],TheDiamondmap[4][1],TheDiamondmap[4][2],TheDiamondmap[4][3],TheDiamondmap[4][4]);
}
// DECLARING ARRAY OF STRUCTS
      struct calculation {
      int p, q, r, s, difference_r, difference_s;
                                    };

        int main() {

        struct calculation juju;

        int game_on,hunt,result,y,z;

        char play_on;

        char TheDiamondmap[5][5]={

            {'-', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-'}

        };

                int map[5][5];

                srand(time(NULL));
                juju.p=rand()%5;
                juju.q=rand()%5;

                for(juju.r=0; juju.r<=4; juju.r++){
                                juju.difference_r = abs(juju.p-juju.r);
                                for (juju.s=0; juju.s<=4; juju.s++){
                                                juju.difference_s = abs(juju.q-juju.s);
                                                if(juju.r==juju.p && juju.s==juju.q){
                                                                map[juju.r][juju.s]=0;
                                                }else if(juju.difference_r<=1 && juju.difference_s<=1){
                                                                map[juju.r][juju.s]=1;
                                                }else if(juju.difference_r<=2 && juju.difference_s<=2){
                                                                map[juju.r][juju.s]=2;
                                                }else if(juju.difference_r<=3 && juju.difference_s<=3){
                                                                map[juju.r][juju.s]=3;
                                                }else{
                                                                map[juju.r][juju.s]=4;
                                                }
                                }
                }
                // PRINTING OUT THE STORYLINE

                printf("Not your typical day at the Diamond....\n");
                printf("You've just finished an amazing ACS 130 Lecture with your awesome Lecturer, Tara at the LT09 on the 3rd Floor.");
                printf("Then suddenly you feel drops of water on your head after a while the droplets turn to bigger droplets\n");
                printf("Within 15 minutes, The Diamond becomes flooded.\n\n");
                printf("Your mission is to come out of the Diamond before it gets totally flooded!!!.\n\n");
                printf("Can you escape the flood?\n");

                print_TheDiamondmap(TheDiamondmap);
                for(result=1; result<=10; result++){
                                printf("Enter the x co-ordinate to search\n");
                                    game_on = scanf("%d", &z); // This is to ensure an integer is received //
                                        while (game_on != 1){
                                            while((hunt = getchar()) != EOF && hunt != '\n');
                                                printf("Co-ordinates are numbers; please try again:\t");
                                                    game_on = scanf("%d", &z);
                                                                                }
                                z = z-1;

                                printf("Enter the y co-ordinate to search\n");

                                game_on = scanf("%d", &y);

                                while(game_on != 1){
                                while((hunt = getchar()) != EOF && hunt != '\n');
                                printf("Co-ordinates are numbers; please try again:\t");
                                game_on = scanf("%d", &y);
                }
                                y = y-1;
                                if(y < 0 || y > 4 || z<0 || z>4) {

                                printf("Dead end, you're stuck in the Library ):\n");

                                } else if(map[y][z]==0){

                                printf("Congratulations! You made it out of Diamond !!!:)");

                                if(result==1){

                                printf(" %d turn.\n", result);

                                } else {
                                                printf(" %d turns.\n", result);
                                                                                    }
                            TheDiamondmap[y][z]='X';

                            print_TheDiamondmap(TheDiamondmap);
                            printf("  /\\ \n");
                            printf(" /  \\ \n");
                            printf("/__\\_\\ \n");
                            printf("\\  / / \n");
                            printf(" \\  / \n");
                            printf("  \\/ \n\n");

                            return 0;

                                } else if(map[y][z]==1){
                                  printf("In this room, you have PLC labs.\n");
                                  TheDiamondmap[y][z]='P';

                                } else if(map[y][z]==2){
                                  printf(" A space that is open for all to see.\n");
                                  TheDiamondmap[y][z]='O';

                                } else if(map[y][z]==3){
                                  printf("Only BioEng students use this room.\n");
                                  TheDiamondmap[y][z]='B';

                                } else if(map[y][z]==4){
                                  printf("Everyone visits this part of the diamond, every now and and then.\n");
                                  TheDiamondmap[y][z]='F';
                                }
                                print_TheDiamondmap(TheDiamondmap);
                                        if(result!=10){
                                                printf("Type 'T' to have another try or 'E' to leave the game.\n");
                                                    scanf(" %c", &play_on);
                                                        if(toupper(play_on)!='Y'){
                                                            printf("Sure about that? Type 'Q' to quit or 'P' to keep playing:\t");
                                                                scanf(" %c", &play_on);
                                                                   if(toupper(play_on) == 'Q'){
                                                                                printf("Goodbye\n");
                                                                                return 0;
                                                                }
                                                }
                                printf("\n");
                                }
                                if(result==10){
                                                printf("You've ran out of time --- You have drowned!\n");
                                }
                }

return 0;
}
