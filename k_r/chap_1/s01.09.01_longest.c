/* 
 * Program from K&R 2nd edition pg 29 Meant to show how functions
 * and character arrays interact.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum input line size */

static int get_line(char line[], int len);
static void copy(char to[], char from[]);

/* print the longest line */
int main(){
    int len=0; /* current line length */
    int max=0; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line is stored here */
    int i=0;
    
    for (i=0;i<MAXLINE;i++){
	line[i]='\0';
	longest[i]='\0';
    }
    
    do {
	len = get_line(line, MAXLINE);
	if (len > max) {
	    max = len;
	    copy(longest, line);
	}
    } while ( len > 0);
    if (max > 0){ /* there was a line longer than 0 */
	printf("Longest line had %d chars\n",max);
	printf("%s\n",longest);
    }
    exit(EXIT_SUCCESS);
}

/* get_line: read a line into string array, return length */
int get_line(char line[],int len){
    int c = 0;
    int i = 0;

    for (i=0; i<len-1 && (c=getchar())!=EOF && (char) c!='\n'; ++i)
	line[i]=(char) c;
    if ((char) c == '\n'){
	line[i] = (char) c;
	i++;
    }
    line[i]= '\0';
    return i;
}

/* copy: copy a string 'from' into 'to'; assume to is big enough. */
void copy(char to[], char from[]){
    int i=0;

    do {
	to[i] = from[i];
	i++;
    } while (from[i] != '\0');

}
