#ifndef TUNEZ_H
#define TUNEZ_H

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list( song_node * );
song_node * insert_front(song_node *, char name[256], char artist[256]);
song_node * free_list(song_node * );

#endif
