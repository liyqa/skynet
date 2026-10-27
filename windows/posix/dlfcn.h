#ifndef _DLFCN_H_
#define _DLFCN_H_

enum { RTLD_NOW, RTLD_GLOBAL };
void *dlopen(const char *path, int flag);
const char *dlerror();
void *dlsym(void *dl, const char *sym);

#endif
