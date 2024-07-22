#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

int main(){

    const int screenWidth = 563;
    const int screenHeight = 641;

    InitWindow(screenWidth, screenHeight , "Agogo da shopee");
    InitAudioDevice();

    Texture agogoPadrao, agogoBocaUm, agogoBocaDois, agogoBocaTres, agogoBocaQuatro, agogoTroca;
   
    Sound sndBoca1 = LoadSound("sounds/Boca-1.mp3");
    Sound sndBoca2 = LoadSound("sounds/Boca-2.mp3");
    Sound sndBoca3 = LoadSound("sounds/Boca-3.mp3");
    Sound sndBoca4 = LoadSound("sounds/Boca-4.mp3");

    agogoPadrao = LoadTexture("images/Agogo.png");
    agogoBocaUm = LoadTexture("images/Agogo1.png");
    agogoBocaDois = LoadTexture("images/Agogo2.png");
    agogoBocaTres = LoadTexture("images/Agogo3.png");
    agogoBocaQuatro = LoadTexture("images/Agogo4.png");
    agogoTroca = agogoPadrao;

    while(!WindowShouldClose()){    

        if(IsKeyDown(KEY_ONE)){
            agogoTroca = agogoBocaUm;
            PlaySound(sndBoca1);
        }
        else if(IsKeyDown(KEY_TWO)){
            agogoTroca = agogoBocaDois;
            PlaySound(sndBoca2);
        }
        else if(IsKeyDown(KEY_THREE)){
            agogoTroca = agogoBocaTres;
            PlaySound(sndBoca3);
        }
        else if(IsKeyDown(KEY_FOUR)){
            agogoTroca = agogoBocaQuatro;
            PlaySound(sndBoca4);
        }
        else{
            agogoTroca = agogoPadrao;
        }           

        BeginDrawing();

        DrawTexture(agogoTroca, 0, 0, WHITE);
        
        EndDrawing();
        
    }

    CloseAudioDevice();
    CloseWindow();


    return 0;
}
