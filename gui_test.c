#include "include/raylib.h"

int main() {
    // ৮০০ বাই ৬০০ পিক্সেলের একটা উইন্ডো খুলবে
    InitWindow(800, 600, "Raylib Setup Success, Pagla!");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); // স্ক্রিন সাদা রাখবে
            DrawText("Congrats! Raylib is working!", 240, 280, 24, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}