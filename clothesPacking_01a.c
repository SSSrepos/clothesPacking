#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int holidayDays = 0;

    printf("How many days are you going on holiday for? ");
    scanf("%d",&holidayDays);

    //Check what season it is
    //char * seasonInput = malloc(sizeof(char)*7);
    char seasonInput[7];
    printf("What season is your holiday taking place in?\n");
    printf("Consider the season the holiday takes place in as the one with most holiday days occuring within it.\n");
    scanf("%6s",seasonInput);
    //Determine what season the user entered then give a number output representing the season
    //1 - Winter
    //2 - Autumn
    //3 - Spring
    //4 - Summer

    int finished = 0;
    int seasonIndicator = 0;
    while(finished != 1){
        switch(*seasonInput){
            case 'W':
            case 'w':
                if(seasonInput[1] == 'I' || seasonInput[1] == 'i'){
                    seasonIndicator = 0;
                    finished = 1;
                    break;
                }else{
                    printf("Please enter a valid season such as Winter, Summer, Autumn or Spring.\n");
                    scanf("%6s",seasonInput);
                    //finished = 0;
                    break;
                }
            case 'A':
            case 'a':
                if(seasonInput[1] == 'U' || seasonInput[1] == 'u'){
                    seasonIndicator = 1;
                    finished = 1;
                    break;
                }else{
                    printf("Please enter a valid season such as Winter, Summer, Autumn or Spring.\n");
                    scanf("%6s",seasonInput);
                    //finished = 0;
                    break;
                }
            case 'S':
            case 's':
                if(seasonInput[1] == 'P' || seasonInput[1] == 'p'){
                    seasonIndicator = 2;
                    finished = 1;
                    break;
                }else if (seasonInput[1] == 'U' || seasonInput[1] == 'u'){
                    seasonIndicator = 3;
                    finished = 1;
                    break;
                }else{
                    printf("Please enter a valid season such as Winter, Summer, Autumn or Spring.\n");
                    scanf("%6s",seasonInput);
                    //finished = 0;
                    break;
                }
            default:
                printf("Please enter a valid season such as Winter, Summer, Autumn or Spring.\n");
                scanf("%6s",seasonInput);

    }
    }
    
    //Clothing calculations section

    //declare all clothing number variables
    int clothNumLength = 6;
    char * clothingTypes[6] = {"Underwear","Pairs of socks","T-shirts","Jumpers/Sweaters","Pants","Shorts","Masks"};
    int clothingNum[6] = {0,0,0,0,0,0,0};

    //1st num -- socks = 0;
    //2nd num -- underwear = 0;
    //3rd num -- t_shirts = 0;
    //4th num -- jumper_sweater = 0;
    //5th num -- pants = 0;
    //6th num -- shorts = 0;
	//7th num -- masks = 0;

    //declare specifc commonly used values
    int everySecondDay = ceil(holidayDays/2);
    int everyFourthDay = floor(holidayDays/4);
    
    //a pair of underwear and socks for each day and a mask for each day, no matter the weather
    clothingNum[0] = holidayDays;
    clothingNum[1] = holidayDays;
	clothingNum[6] = holidayDays;

    //a t-shirt for every second day on the trip -- if decimal is found, round up
    clothingNum[2] = everySecondDay;

    //a jumper/sweater for every second day except if it is summer, then don't pack any
    if(seasonIndicator == 3){
        clothingNum[3] = 0;
    }else{
        clothingNum[3] = everySecondDay;
    }
    
    //If the season is winter, pack only pants - one for every second day. If season is summer, pack only shorts and follow jumper rule in summer
    if(seasonIndicator == 0){
        clothingNum[4] = everySecondDay;
        clothingNum[5] = 0;
    }else if (seasonIndicator == 3){
        clothingNum[4] = everyFourthDay;
        clothingNum[5] = everySecondDay;
    }else{
        clothingNum[5] = everyFourthDay;     //based on personal preference -- I prefer wearing pants 9/10 times
        clothingNum[4] = everySecondDay;
    }

    //print results
    char * seasonNames[4] = {"Winter","Autumn","Spring","Summer"};
    printf("The recommended number of clothing for a trip of %d days during %s is:\n",holidayDays,seasonNames[seasonIndicator]);
    for(int i = 0; i < clothNumLength; i++){
        printf("%s: %d\n",clothingTypes[i],clothingNum[i]);
    }
    system("pause");
    return 0;
}