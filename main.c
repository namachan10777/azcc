#include "codegen.h"
#include "parse.h"
#include "tokenize.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return EXIT_FAILURE;
  }

  //トークナイズしてパースする
  char *user_input = argv[1];
  Token *head = tokenize(user_input);
  ListNode *node = parse(head); // FunctionDefinition List

  //コード生成
  generate_code(node);

  return EXIT_SUCCESS;
}
