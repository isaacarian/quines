#include "stdio.h"

int main()
{
  FILE *fp;
  fp = fopen("quine_copy.c", "w");

  char c1[] = "#include \"stdio.h\"\r\n\r\nint main()\r\n{\r\n  FILE *fp;\r\n  fp = fopen(\"quine_copy.c\", \"w\");\r\n";
  char c2[] = "#include \\\"stdio.h\\\"\\r\\n\\r\\nint main()\\r\\n{\\r\\n  FILE *fp;\\r\\n  fp = fopen(\\\"quine_copy.c\\\", \\\"w\\\");\\r\\n";
  char c3[] = "\r\n  fprintf(fp,\"%s\", c1);\r\n\r\n  fprintf(fp,\"\\n  char c1[] = \\\"%s\\\";\", c2);\r\n  fprintf(fp,\"\\n  char c2[] = \\\"\");\r\n  for (int i = 0; i < sizeof(c2) - 1; i++)\r\n  {\r\n    if (c2[i] == \'\\\\\')\r\n      fprintf(fp,\"\\\\\");\r\n    else if (c2[i] == \'\"\')\r\n      fprintf(fp,\"\\\\\");\r\n    fprintf(fp,\"%c\", c2[i]);\r\n  }\r\n  fprintf(fp, \"\\\";\");\r\n\r\n  fprintf(fp,\"\\n  char c3[] = \\\"%s\\\";\", c4);\r\n  fprintf(fp,\"\\n  char c4[] = \\\"\");\r\n  for (int i = 0; i < sizeof(c4) - 1; ++i)\r\n  {\r\n    if (c4[i] == \'\\\\\')\r\n      fprintf(fp,\"\\\\\");\r\n    else if (c4[i] == \'\"\')\r\n      fprintf(fp,\"\\\\\");\r\n    fprintf(fp,\"%c\", c4[i]);\r\n  }\r\n  fprintf(fp, \"\\\";\");\r\n\r\n  fprintf(fp,\"%s\", c3);\r\n  return 0;\r\n}";
  char c4[] = "\\r\\n  fprintf(fp,\\\"%s\\\", c1);\\r\\n\\r\\n  fprintf(fp,\\\"\\\\n  char c1[] = \\\\\\\"%s\\\\\\\";\\\", c2);\\r\\n  fprintf(fp,\\\"\\\\n  char c2[] = \\\\\\\"\\\");\\r\\n  for (int i = 0; i < sizeof(c2) - 1; i++)\\r\\n  {\\r\\n    if (c2[i] == \\\'\\\\\\\\\\\')\\r\\n      fprintf(fp,\\\"\\\\\\\\\\\");\\r\\n    else if (c2[i] == \\\'\\\"\\\')\\r\\n      fprintf(fp,\\\"\\\\\\\\\\\");\\r\\n    fprintf(fp,\\\"%c\\\", c2[i]);\\r\\n  }\\r\\n  fprintf(fp, \\\"\\\\\\\";\\\");\\r\\n\\r\\n  fprintf(fp,\\\"\\\\n  char c3[] = \\\\\\\"%s\\\\\\\";\\\", c4);\\r\\n  fprintf(fp,\\\"\\\\n  char c4[] = \\\\\\\"\\\");\\r\\n  for (int i = 0; i < sizeof(c4) - 1; ++i)\\r\\n  {\\r\\n    if (c4[i] == \\\'\\\\\\\\\\\')\\r\\n      fprintf(fp,\\\"\\\\\\\\\\\");\\r\\n    else if (c4[i] == \\\'\\\"\\\')\\r\\n      fprintf(fp,\\\"\\\\\\\\\\\");\\r\\n    fprintf(fp,\\\"%c\\\", c4[i]);\\r\\n  }\\r\\n  fprintf(fp, \\\"\\\\\\\";\\\");\\r\\n\\r\\n  fprintf(fp,\\\"%s\\\", c3);\\r\\n  return 0;\\r\\n}";

  fprintf(fp,"%s", c1);

  fprintf(fp,"\n  char c1[] = \"%s\";", c2);
  fprintf(fp,"\n  char c2[] = \"");
  for (int i = 0; i < sizeof(c2) - 1; i++)
  {
    if (c2[i] == '\\')
      fprintf(fp,"\\");
    else if (c2[i] == '"')
      fprintf(fp,"\\");
    fprintf(fp,"%c", c2[i]);
  }
  fprintf(fp, "\";");

  fprintf(fp,"\n  char c3[] = \"%s\";", c4);
  fprintf(fp,"\n  char c4[] = \"");
  for (int i = 0; i < sizeof(c4) - 1; ++i)
  {
    if (c4[i] == '\\')
      fprintf(fp,"\\");
    else if (c4[i] == '"')
      fprintf(fp,"\\");
    fprintf(fp,"%c", c4[i]);
  }
  fprintf(fp, "\";");

  fprintf(fp,"%s", c3);
  return 0;
}
