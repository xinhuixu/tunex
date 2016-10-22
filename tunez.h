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
song_node * new_song_node(char * name, char * artist);
int codeFor(char ch);
int length( song_node * n );
void print_song( song_node *n );
void print_list( song_node *n );
void print_letter(song_node * p[26], char c);
song_node * insert_front(song_node *n, char name[256], char artist[256]);
song_node * insert_order(song_node *n, char name[256], char artist[256]);
void add_song(song_node * p[26], char * name, char * artist);
song_node * search_in_node( song_node * n, char * name, char * artist);
song_node * search_song( song_node * p[26], char * name, char * artist );
song_node * search_artist_in_node( song_node * n, char * artist);
song_node * search_artist( song_node * p[26], char * artist );
song_node * remove_node( song_node * p[26], song_node * rem);
song_node * delete_song( song_node * p[26], char * name, char * artist);
void shuffle( song_node * p[26], int k);
void print_artist( song_node * p[26], char * artist );
void print_array(song_node * p[26]);
song_node * free_list(song_node * n);
void delete(song_node * p[26]);

#endif
