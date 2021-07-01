#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* toLower(char * seasonText){
   for(int i = 0; i <= strlen(seasonText); i++){
      if(seasonText[i] >= 65 && seasonText[i] <= 90)            //if character in string is a capital letter, set it to the lowercase equivalent
         seasonText[i] = seasonText[i]+32;
   }
   return seasonText;
}

int main(void){
    int holidayDays = 0;

    printf("How many days are you going on holiday for? ");
    scanf("%d",&holidayDays);

    //Check what season it is
    char * seasonInput = malloc(sizeof(char)*7);
    printf("What season is your holiday taking place in?\n");
    printf("Consider the season the holiday takes place in as the one with most holiday days occuring within it.\n");
    scanf("%6s",seasonInput);
    //to check that first letter of season given is capitalised 
    if(seasonInput[0] >= 97 && seasonInput[0] <= 122){
        seasonInput[0] = seasonInput[0]-32;
    }else{

    }
    char * seasonLower = toLower(seasonInput);
    //printf("%s\n",seasonLower);

    //Clothing calculations section

    //declare all clothing number variables
    int clothNumLength = 6;
    char * clothingTypes[6] = {"Underwear","Pairs of socks","T-shirts","Jumpers/Sweaters","Pants","Shorts"};
    int clothingNum[6] = {0,0,0,0,0,0};

    //1st num -- socks = 0;
    //2nd num -- underwear = 0;
    //3rd num -- t_shirts = 0;
    //4th num -- jumper_sweater = 0;
    //5th num -- pants = 0;
    //6th num -- shorts = 0;

    //declare specifc commonly used values
    int everySecondDay = ceil(holidayDays/2);
    int everyFourthDay = floor(holidayDays/4);
    
    //a pair of underwear and socks for each day, no matter the weather
    clothingNum[0] = holidayDays;
    clothingNum[1] = holidayDays;

    //a t-shirt for every second day on the trip -- if decimal is found, round up
    clothingNum[2] = everySecondDay;

    //a jumper/sweater for every second day except if it is summer, then only one jumper for every four days -- floor function
    //used here
    if(strcmp(seasonLower,"summer") == 0){
        clothingNum[3] = everyFourthDay;
    }else{
        clothingNum[3] = everySecondDay;
    }
    
    //If the season is winter, pack only pants - one for every second day. If season is summer, pack only shorts and follow jumper rule in summer
    if(strcmp(seasonLower,"winter") == 0){
        clothingNum[4] = everySecondDay;
        clothingNum[5] = 0;
    }else if (strcmp(seasonLower,"summer") == 0){
        clothingNum[4] = everyFourthDay;
        clothingNum[5] = everySecondDay;
    }else{
        clothingNum[5] = everyFourthDay;     //based on personal preference -- I prefer wearing pants 9/10 times
        clothingNum[4] = everySecondDay;
    }
    free(seasonLower);
    //print results
    printf("The recommended number of clothing for a trip of %d days during %s is:\n",holidayDays,seasonInput);
    for(int i = 0; i < clothNumLength; i++){
        printf("%s: %d\n",clothingTypes[i],clothingNum[i]);
    }
    system("pause");
    return 0;
}