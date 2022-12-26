// TODO: scale graph more correctly
// TODO: add text markings 

#include "/opt/homebrew/include/raylib.h"
#include <stdio.h>

const int WIDTH = 900;
const int HEIGHT = 500;

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
    InitWindow(WIDTH, HEIGHT, "Collatz Graph");
    SetTargetFPS(60);

    int nodes[1000];
    int n = 0;
    int x;
    int maxnode = x;
    scanf("%d", &x);
    nodes[0] = x;

    while(nodes[n] != 1){
        nodes[n+1] = calculate_next_node(nodes[n]);
        if(nodes[n+1] > maxnode) maxnode = nodes[n+1];
        n++;
    }
    for(int i = 0; i <= n; i++){
        printf("%d ", nodes[i]);
    }
    printf("\n");

    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw axes
        DrawLine(100, HEIGHT - 100, 100, 100, WHITE);
        DrawLine(100, HEIGHT - 100, WIDTH - 100, HEIGHT - 100, WHITE);

        for(int i = 0; i < n; i++){
            DrawCircle(100 + i*5 ,HEIGHT - nodes[i]/(maxnode/HEIGHT) - 100,5,BLUE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
