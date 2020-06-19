#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "nxjson-master/nxjson.h"
/*------------------------------------------------------------------------------------------------*/
/* Prototype */
char *load_file(const char *filepath);
static void dump(const nx_json *json, char *out, char **end, int indent);

/*------------------------------------------------------------------------------------------------*/
char *load_file(const char *filepath)
{
  struct stat st;
  if (stat(filepath, &st) == -1)
  {
    // ERROR("Can't find file\n", filepath);
    return NULL;
  }
  int fd = open(filepath, O_RDONLY);
  if (fd == -1)
  {
    // ERROR("Can't open file\n", filepath);
    return NULL;
  }
  char *text = (char *)malloc(st.st_size + 1);
  if (st.st_size != read(fd, text, st.st_size))
  {
    // ERROR("Can't read file\n");
    close(fd);
    return NULL;
  }
  close(fd);
  text[st.st_size] = '\0';
  return text;
}

static void dump(const nx_json *json, char *out, char **end, int indent)
{
  if (!json)
  {
    *end = out;
    return;
  }
  int i;
  for (i = 0; i < indent; i++)
    *out++ = ' ';
  if (json->key)
  {
    strcpy(out, json->key);
    out += strlen(json->key);
    *out++ = ':';
  }
  switch (json->type)
  {
  case NX_JSON_NULL:
    strcpy(out, "null");
    out += 4;
    break;
  case NX_JSON_OBJECT:
    *out++ = '{';
    *out++ = '\n';
    {
      nx_json *js = json->child;
      for (js = json->child; js; js = js->next)
      {
        dump(js, out, &out, indent + 2);
      }
    }
    for (i = 0; i < indent; i++)
      *out++ = ' ';
    *out++ = '}';
    break;
  case NX_JSON_ARRAY:
    *out++ = '[';
    *out++ = '\n';
    {
      nx_json *js = json->child;
      for (js = json->child; js; js = js->next)
      {
        dump(js, out, &out, indent + 2);
      }
    }
    for (i = 0; i < indent; i++)
      *out++ = ' ';
    *out++ = ']';
    break;
  case NX_JSON_STRING:
    *out++ = '"';
    strcpy(out, json->text_value);
    out += strlen(json->text_value);
    *out++ = '"';
    break;
  case NX_JSON_INTEGER:
    out += sprintf(out, "%lld", json->int_value);
    break;
  case NX_JSON_DOUBLE:
    out += sprintf(out, "%le", json->dbl_value);
    break;
  case NX_JSON_BOOL:
    *out++ = json->int_value ? 'T' : 'F';
    break;
  default:
    strcpy(out, "????");
    out += 4;
    break;
  }
  *out++ = '\n';
  *end = out;
}

const char json_file[] = "Json_Test_File/Json_test_file.json";

void test_json()
{
  char *json_data;
  json_data = load_file(json_file);

  if (json_data == NULL)
  {
    printf("load file error\n");
    exit(0);
  }

  const nx_json *json = nx_json_parse_utf8(json_data);
  if (!json)
  {
    printf("Failed to parse json file");
  }
  char *buffer = (char *)malloc(strlen(json_data) * 32 + 4000000);
  char *buffer_p = buffer;
  dump(json, buffer_p, &buffer_p, 0);
  nx_json_free(json);
  *buffer_p = '\0';
  printf("%s", buffer);
}

int main(int argc, char **argv)
{
  printf("Begin Json Test\n");
  test_json();
  return 0;
}