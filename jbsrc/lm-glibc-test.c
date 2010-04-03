#include <features.h>

int main() {
#ifndef __GLIBC__
#error "glibc not found"
#endif
}
