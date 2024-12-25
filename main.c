#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib 3D Example");

    // Camera setup
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 4.0f, 4.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };   // Look-at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };       // Camera up vector
    camera.fovy = 45.0f;                             // Field of view
    camera.projection = CAMERA_PERSPECTIVE;          // Perspective projection

    // SetTargetFPS to 60 for smooth rendering
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        UpdateCamera(&camera, CAMERA_FREE); // Update camera movement

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawCube((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKGRAY);
                DrawGrid(10, 1.0f); // Draw a grid for reference
            EndMode3D();

            DrawText("Use WASD and Mouse to move the camera", 10, 10, 20, DARKGRAY);
            DrawFPS(10, 40);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
