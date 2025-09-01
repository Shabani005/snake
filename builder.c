#define NB_IMPLEMENTATION
#include "nb.h"

int main(int argc, char **argv){
  nb_rebuild(argc, argv);
  nb_arr cmd;

  nb_append(&cmd, "gcc");
  nb_append_da(&cmd, "-Wextra", "-Wall");
  nb_append(&cmd, "-o snakec");
  nb_append(&cmd, "snakegrid.c");
  nb_append(&cmd, "-O3");
  nb_append(&cmd, "-lraylib");

  nb_cmd(&cmd);
  
  if (argc > 1){
    if (strcmp(argv[1], "-r") == 0){
      nb_append(&cmd, "./snakec");
      nb_cmd(&cmd);
    } else if (strcmp(argv[1], "help") == 0){
      printf("Commands:\n-r: Execute after build.\n");
    }
  }
  return 0;
}
