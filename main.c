#define WEBVIEW_IMPLEMENTATION
#include "webview.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#define PATH_MAX 4096
struct webview example = {
    .title = "Example",
    .width = 600,
    .height = 250,
    .debug = 1,
    .resizable = 1,
};

void open_url(struct webview *w, const char *website_url) {
  webview("xxx", "http://localhost:8080/arquivo/show/1", 1200, 800, 1);
}

int main() {
  char cwd[PATH_MAX];
  char path[PATH_MAX] = "file://";
  
  getcwd(cwd, sizeof(cwd)); 
  strcat(path, cwd);
  strcat(path, "/app.flr"); // concatenated path ends up being something like "file:///home/username/directory/c-webview-example/app.html"

  example.url = path;
  
  printf("%s", path);
  webview_init(&example);
  example.external_invoke_cb = open_url; //  open_url is the name of the function invoked from JS
  while (webview_loop(&example, 1) == 0); // starts rendering the front-end
  return 0;
}