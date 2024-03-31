```
emsdk activate latest
```

```
emcc wrapping.c -o wrapping.js -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=[ccall]
```

- NO_EXIT_RUNTIME
- EXPORTED_RUNTIME_METHODS


```c
#include<stdio.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
int addNums(int a, int b)
{
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
int main()
{
    printf("hello world %d\n",addNums(3,5));
    return 0;
}
```

```html
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>CCall and Cwrap</title>
        <link
            rel="stylesheet"
            href="https://cdn.jsdelivr.net/npm/bulma@1.0.0/css/bulma.min.css"
            >
        <script src="wrapping.js"></script>
    </head>
    <body>
        <p class="title">Hello WebAssembly</p>
        <script>
            function run_wasm(){
                var result = Module.ccall(
                    "main",
                    "number",
                    null,
                    null
                );
                console.log(result)
            }
        </script>
        <button class="button" onclick="run_wasm()">Trigger</button>

    </body>
    </html>
```

```js

const num1 = document.querySelector("#num1").value;
const num2 = document.querySelector("#num2").value;


var result = Module.ccall(
    "addNums",
    "number",
    ["number","number"],
    [num1,num2]
)
console.log(`${num1} + ${num2} = ${result}`);
```

```
emcc wrapping.c -o wrapping.js -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=ccall,cwrap   
```

```
var addNums = Module.cwrap(
        "addNums",
        "number",
        ["number","number"]
    );

```