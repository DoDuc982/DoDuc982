#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int countLetter(string text){
    int i=0;
    int count=0;
    while(i < strlen(text)){
        if((text[i]>=97 && text[i]<=122) || (text[i]>=65 && text[i]<=90)) count++;
        i++;
    }
    return count;
}
int countWord(string text){
    int i=0;
    int count=0;
    while(i < strlen(text)){
        if(text[i]==32) count++;
        i++;
    }
    if(text[strlen(text)-1]==46 || text[strlen(text)-1]==33 || text[strlen(text)-1]==63) count++;
    return count;
}
int countSentences(string text){
    int i=0;
    int count=0;
    while(i < strlen(text)){
        if(text[i]==46 || text[i]==33 || text[i]==63) count++;
        i++;
    }
    return count;
}
int main(void)
{
    string text = get_string("Text: ");
    float l = countLetter(text);
    float w = countWord(text);
    float s = countSentences(text);
    float L = (l/w*100);
    float S = (s/w*100);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) <= 1) printf("Before Grade 1\n");
    else if (round(index) >=16) printf("Grade 16+\n");
    else printf("Grade %.0f\n",round(index));
}