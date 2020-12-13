#include "stdio.h"

int main()
{
  FILE *fp;
  fp = fopen("quine_copy.c", "w");

  char c1[] = "#include \"stdio.h\"\r\n\r\nint main()\r\n{\r\n  FILE *fp;\r\n  fp = fopen(\"quine_copy.c\", \"w\");\r\n";
  char c2[] = "\r\n  printf(\"%s\", c1);\r\n  printf(\"\\n  char c1[] = \");\r\n  for (int i = 0; i < sizeof(c1); ++i)\r\n  {\r\n    if (c1[i] == \'n\' && c1[i-1] == \'\\\\\')\r\n      printf(\"\\\\\");\r\n    else if (c1[i] == \'\"\' && c1[i-1] == \'\\\\\')\r\n      printf(\"\\\\\\\\\");\r\n    printf(\"%c\", c1[i]);\r\n  }\r\n  printf(\"\\\"\");\r\n  printf(\"  char c1[] = \");\r\n  for (int i = 0; i < sizeof(c2); ++i)\r\n  {\r\n    if ((c2[i] == \'n\'|| c2[i] == \'r\') && c2[i-1] == \'\\\\\')\r\n      printf(\"\\\\\");\r\n    else if (c2[i] == \'\"\' && c2[i-1] == \'\\\\\')\r\n      printf(\"\\\\\\\\\");\r\n    printf(\"%c\", c2[i]);\r\n  }\r\n  printf(\"\\\"\");\r\n\r\n  printf(\"%s\", c2);\r\n\r\n  return 0;\r\n}";

  printf("%s", c1);
  printf("\n  char c1[] = ");
  for (int i = 0; i < sizeof(c1); ++i)
  {
    if ((c1[i] == 'n' || c1[i] == 'r') && c1[i-1] == '\\')
      printf("\\");
    else if (c1[i] == '"' && c1[i-1] == '\\')
      printf("\\\\");
    printf("%c", c1[i]);
  }
  printf("\"");
  printf("  char c2[] = ");
  for (int i = 0; i < sizeof(c2); ++i)
  {
    if ((c2[i] == 'n'|| c2[i] == 'r') && c2[i-1] == '\\')
      printf("\\");
    else if (c2[i] == '"' && c2[i-1] == '\\')
      printf("\\\\");
    printf("%c", c2[i]);
  }
  printf("\"");

  printf("%s", c2);

  return 0;
}
