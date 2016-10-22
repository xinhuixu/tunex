#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tunez.h"

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
