#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"
#include <time.h>

// make a new song node
song_node * new_song_node(char * name, char * artist){
  song_node *n = ( song_node * )malloc(sizeof( song_node ));
  strcpy(n->name, name);
  strcpy(n->artist, artist);
  n->next = NULL;
  return n;
}

int codeFor(char ch) {
  if (ch >= 'a' && ch <= 'z') {
      return ch - 'a';
   } else {
      return 99;
   }
}

int length( song_node * n ){
  int c = 0;
  while (n) {
    c++;
    n = n->next; 
  }
  return c;
}

void print_song( song_node *n ){
  if (n == 0){
    printf("no song found");
  }
  printf("artist: %s | ", n->artist);
  printf("name: %s\n",n->name);
}

// print out linked list
void print_list( song_node *n ) {
  if (n == NULL)
    printf("no artists found.\n");
  while(n) {
  //  printf("ENTERED WHILE LOOP OF PRINT LIST");
    printf("song: %s | ", n->name);
    printf("artist: %s\n",n->artist);
    n = n->next;
  }
}

void print_letter(song_node * p[26], char c){
  print_list(p[codeFor(c)]);
}

song_node * insert_front(song_node *n, char name[256], char artist[256]){
  //if null
  song_node *new = ( song_node * )malloc(sizeof( song_node ));
  new = new_song_node(name,artist);
  new->next = n;
  return new;
}

// insert song in order
song_node * insert_order(song_node *n, char name[256], char artist[256]){
   //if n is empty
  song_node *start = ( song_node * )malloc(sizeof( song_node ));
  start = n;
  if (!n || strcmp(artist, n->artist) < 0 || (!strcmp(artist, n->artist) && strcmp(name, n->name) < 0)){
    //printf("ENTERING INSERT FRONT");
    return insert_front(n, name, artist); //will return front node
  }
  else{
    //printf("ENTERING INSERT ORDER");
    song_node *temp = (song_node *)malloc(sizeof(song_node *));
    temp = n->next;
    //temp and n will sandwich 
    //will stop when it hits the same or "lesser" artist
    while (n->next && strcmp(artist, n->artist) > 0){
      n = n->next;
      temp = temp->next;
    }
    //same artist. check song
    while (n->next && strcmp(temp->artist, artist) == 0){
      if (strcmp(name, temp->name) < 0)
        break;
      temp = temp->next;
      n = n->next;
    }

    //inserting the node
    song_node *new_node = new_song_node(name, artist);
    new_node->next = temp;
    n->next = new_node;
    return start;
  }
}

// create new song_node, pass to add_song_node
void add_song(song_node * p[26], char * name, char * artist){  
  //print codeFor(artist[0]);
  //printf("%d", codeFor(artist[0]));
  // if (p[codeFor(artist[0])] == NULL){
  //   p[codeFor(artist[0])] = insert_front(p[codeFor(artist[0])], name, artist);
  // }
  // else

  p[codeFor(artist[0])] = insert_order(p[codeFor(artist[0])], name, artist);
  printf("new song %s by %s added\n",name,artist);
}

// helper for search_song
song_node * search_in_node( song_node * n, char * name, char * artist){
  while (n){
    if (strcmp(name, n->name) && strcmp(artist, n->artist)) {
      n = n->next;
    } 
    else {
      return n;
    }
  }
  return 0;
}

// find pointer to song based on song name first incidence
song_node * search_song( song_node * p[26], char * name, char * artist ){  
  int i = 0;
  while (i<26){
    song_node * r = search_in_node(p[i], name, artist);
    if (r) {
      return r;
    }
    i++;
  }
  printf(">>> song '%s' not found\n",name);
  return 0;
}

// find first song of artist based on artist name
song_node * search_artist_in_node( song_node * n, char * artist){
  while (n){
    if (strcmp(artist, n->artist)) {
      n = n->next;
    } else {
      return n;
    }
  }
  return n;
}

// find artist
song_node * search_artist( song_node * p[26], char * artist ){  
  song_node *start = ( song_node * )malloc(sizeof( song_node ));
  start = p[codeFor(artist[0])];
   while (start){
    if (strcmp(artist, start->artist) == 0)
      return start;
    start = start->next;
  }
  //printf("%d", start);
  return start;
}

// remove single node from list
song_node * remove_node( song_node * p[26], song_node * rem){
  song_node *t = ( song_node * )malloc(sizeof( song_node ));
  song_node *s = ( song_node * )malloc(sizeof( song_node ));
  s = p[codeFor((rem->artist)[0])];
  t = p[codeFor((rem->artist)[0])];
  while (t->next != rem){
    t = t->next;
  }
  t->next = rem->next;
  free(rem);
  return s;
}

// delete song
song_node * delete_song( song_node * p[26], char * name, char * artist){
  song_node *rem = ( song_node * )malloc(sizeof( song_node ));
  rem = search_song(p, name, artist);
  if (rem == NULL){
    return 0;
  }
  return remove_node(p, rem);
}


// shuffle k songs
void shuffle( song_node * p[26], int k){
  song_node * point;
  int i = 0;
  int x;
  srand(time(NULL));
  int r = rand() % 26;
  while (i < k){
     r = rand() % 26;
     point = p[r];
     if (p[r] != NULL){
      x = rand() % length(p[r]);
      while (x > 0){
        point = point->next;
        x--;
      }
      print_song(point);
      i++;
     }
  }
}



// find artist, print out all songs of artist
void print_artist( song_node * p[26], char * artist ){
  song_node *start = ( song_node * )malloc(sizeof( song_node ));
  start = search_artist(p, artist);
  if (start == NULL)
    printf("artist not found");
  else
    while (strcmp(start->artist, artist) == 0){
      print_song(start);
      start = start->next;
    }
}


// print out entire playlist

void print_array(song_node * p[26]){
  int i;
  for (i = 0; i< 26; i++)
       if (p[i] != NULL) 
        print_list(p[i]);  
}

song_node * free_list(song_node * n) {
  song_node *f =  ( song_node * )malloc(sizeof( song_node *));
  f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

void delete(song_node * p[26]){
  int i;
  for (i = 0; i < 25; i++){
    if (p[i]) 
      free_list(p[i]);
    else
      free(p[i]);
  }
  p = NULL;
}

// ------------------------------------------ //
// worked helper fxn tests will be deleted after testing

int main(){
  int i;
  printf("------RUN------\n");
  song_node * playlist[26];
  for (i = 0; i < 26; i++)
    playlist[i] = 0;
  printf("playlist[26]\n");
  printf("------------\n");
  
  add_song(playlist, "xow people move","aoa"); 
  add_song(playlist, "like a cat","aoa"); 
  add_song(playlist, "acer","aoa"); 
  add_song(playlist, "yolo","apink"); 
  add_song(playlist, "hotline bling","drake"); 
  add_song(playlist, "hips don't lie","shakira"); 
  add_song(playlist, "stripes","zebra"); 
  add_song(playlist, "meowody","cat"); 
  add_song(playlist, "corn","pop"); 
  add_song(playlist, "pen","gel"); 
  add_song(playlist, "trump","tower");
  add_song(playlist, "luna","moon"); 
  //print_list(a);
  printf("------------\n");
  printf(">>> searching for song 'like a cat'\n");
  print_song(search_song(playlist, "like a cat", "aoa"));
  printf("------------\n");
  printf("testing search artist. expecting pointer of first incidence to be returned so print list will print out the entire list starting from the pointer\n");
  printf(">>> searching for artist 'apink'\n");
  print_list(search_artist(playlist, "apink"));
  printf(">>> searching for artist 'amudddfdfsdff'\n");
  print_list(search_artist(playlist, "amudddfdfsdff"));
  printf("------------\n");
  printf(">>> printing all song under letter '%c'\n",'a');
  print_letter(playlist,'a');
  printf("------------\n");
  printf(">>> printing all songs by '%s'\n","aoa");
  print_artist(playlist,"aoa");
  printf("------------\n");
  printf(">>> printing entire lib\n");
  print_array(playlist);
  printf("------------\n");
  printf(">>> testing print_list:\n");
  print_list(playlist[0]);
  print_list(playlist[1]);
  printf("------------\n");
  printf(">>> testing delete_song. deleting apink's yolo. before deletion:\n");
  print_array(playlist);
  printf("\nafter deletion:\n");
  print_list(delete_song(playlist, "yolo", "apink"));
  print_array(playlist);
  printf("------------\n");
  printf(">>> testing length. finding length of playlist[0]:\n");
  printf("length: %d\n", length(playlist[0]));
  printf("------------\n");
  printf(">>> testing random & shuffle.\n");
  shuffle(playlist, 4);
  printf("------------\n");
  printf(">>> deleting.\n");
 
  delete(playlist);
  printf("------RUN END------\n");
}


