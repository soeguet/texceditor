/*******************************************************************************************
 *
 *   raylib [text] example - Input Box
 *
 *   Example complexity rating: [★★☆☆] 2/4
 *
 *   Example originally created with raylib 1.7, last time updated with
 *raylib 3.5
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an
 *OSI-certified, BSD-like license that allows static linking with closed source
 *software
 *
 *   Copyright (c) 2017-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"

typedef struct {
    char *chars;
    int32_t length;
    int32_t capacity;
} String;

void initString(String *str) {
    str->chars = malloc(16);
    str->length = 0;
    str->capacity = 16;
    str->chars[0] = '\0';
}

void removeChar(String *str) {
    if (str->length > 0) {
        str->chars[str->length - 1] = '\0';
        str->length--;
    }
}

void appendChar(String *str, char c) {
    if (str->length + 1 >= str->capacity) {
        str->capacity *= 2;
        str->chars = realloc(str->chars, str->capacity);
    }
    str->chars[str->length++] = c;
    str->chars[str->length] = '\0';
}

void freeString(String *str) {
    free(str->chars);
    str->chars = NULL;
    str->length = 0;
    str->capacity = 0;
}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - input box");

    String custom_user_input;
    initString(&custom_user_input);


    int letterCount = 0;

    const Font fontTtf = LoadFontEx("assets/Monoid.ttf", 40, 0, 250);

    const Rectangle textBox = {0, 0, screenHeight, screenHeight};

    int framesCounter = 0;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0) {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125)) {
                appendChar(&custom_user_input, (char) key);
                letterCount++;
            }

            key = GetCharPressed(); // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (custom_user_input.length > 0) {
                removeChar(&custom_user_input);
            }
        } else if (IsKeyPressed(KEY_ENTER)) {
            appendChar(&custom_user_input, '\n');
        }


        framesCounter++;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextEx(fontTtf, custom_user_input.chars,
                   (Vector2){(textBox.x), (textBox.y)},
                   (float) fontTtf.baseSize, 3, RED);


        // BLINKING CURSOR
        // if (((framesCounter / 40) % 2) == 0)
        //     DrawLine((int) textBox.x + 8 + MeasureText(custom_user_input.chars, 40),
        //              (int) textBox.y + 3,
        //              (int) textBox.x + 8 + MeasureText(custom_user_input.chars, 40) + 1,
        //              (int) textBox.y + (int) textBox.height - 3, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Check if any key is pressed
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
bool IsAnyKeyPressed() {
    bool keyPressed = false;
    const int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126))
        keyPressed = true;

    return keyPressed;
}
