/*
 * main.c
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#include "db.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
  int i, status = 0;
  sqlite3 *dbh;

  if (argc < 2) {
    printf("Usage: %s <command> ...\n", argv[0]);
    return 0;
  }

  if ((dbh = get_db_handle()) == NULL)
    return 1;

  if (!strcmp(argv[1], "add")) {
    if (argc != 3) {
      printf("Usage: %s add [paths]\n", argv[0]);
      return 1;
    }

    for (i = 2; i < argc; i++)
      add_repo_to_db(dbh, argv[i]);
  }

  close_db_handle(dbh);
  return status;
}
