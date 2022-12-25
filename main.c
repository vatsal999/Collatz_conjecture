// TODO: add graph

// #include "/opt/homebrew/include/raylib.h"
#include <stdio.h>

const int WIDTH = 1000;
const int HEIGHT = 1000;

int calculate_next_node(int x){
    int y;
    if(x % 2 == 0){
        y = x / 2;
    }else{
        y = 3*x + 1;
    }
    return y;
}

int main(void)
{
    // InitWindow(WIDTH, HEIGHT, "PONG v0.1");
    // SetTargetFPS(60);

    int nodes[1000];
    int n = 0;
    int x;
    scanf("%d", &x);
    nodes[0] = x;

    while(nodes[n] != 1){
        nodes[n+1] = calculate_next_node(nodes[n]);
        n++;
    }
    for(int i = 0; i <= n; i++){
        printf("%d ", nodes[i]);
    }
    printf("\n");

    // while (!WindowShouldClose()){
    //
    //     BeginDrawing();
    //     ClearBackground(BLACK);
    //
    //     EndDrawing();
    // }

    // CloseWindow();

    return 0;
}
