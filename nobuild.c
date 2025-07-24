#include "nb.h"

int main(void){
  nb_arr cmd;

  nb_append(&cmd, "gcc");
  nb_append(&cmd, "-Wextra -Wall");
  nb_append(&cmd, "-o snakec");
  nb_append(&cmd, "main.c");
  nb_append(&cmd, "-lraylib");

  nb_print_info(&cmd);
  nb_cmd(&cmd);
  return 0;
}
