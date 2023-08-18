#ifndef _JOSEPHUS_H_
#define _JOSEPHUS_H_

#include <stdlib.h>

typedef int data_type;
typedef struct Josephus Josephus;

//Initiate the rules of the game
Josephus *Josephus_init(int M, size_t N);
//Remove the person in position M of the circle
void remove_mnth_person(Josephus *josephus);
//Check if the game already has a winner
int has_ended(Josephus *josephus);

#endif