#include <emscripten.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div_t(int a, int b);

EMSCRIPTEN_KEEPALIVE
int sumOfNInts(int n){
    return div_t(mul(n,add(n,1)),2);
}