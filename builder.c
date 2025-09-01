#define NB_IMPLEMENTATION
#include "nb.h"

int main(int argc, char **argv){
  nb_rebuild(argc, argv);
  nb_arr cmd;

  nb_append(&cmd, "gcc");
  nb_append(&cmd, "-Wextra -Wall");
  nb_append(&cmd, "-o snakec");
  nb_append(&cmd, "snakegrid.c");
  nb_append(&cmd, "-O3");
  nb_append(&cmd, "-lraylib");

  nb_cmd(&cmd);
  return 0;
}
