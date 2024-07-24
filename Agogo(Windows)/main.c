#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

int main(){

    const int screenWidth = 540;
    //const int screenWidth = 900;
    const int screenHeight = 675;

    InitWindow(screenWidth, screenHeight , "Agogo da shopee");
    InitAudioDevice();

    Texture agogoPadrao, agogoBocaUm, agogoBocaUmDois, agogoBocaUmTres, agogoBocaUmQuatro,
        agogoBocaDois, agogoBocaDoisTres, agogoBocaDoisQuatro,
        agogoBocaTres, agogoBocaTresQuatro,
        agogoBocaQuatro, agogoTodos, agogoTroca;
   
    Sound sndBocaUm = LoadSound("sounds/Boca-1.mp3");
    Sound sndBocaDois = LoadSound("sounds/Boca-2.mp3");
    Sound sndBocaTres = LoadSound("sounds/Boca-3.mp3");
    Sound sndBocaQuatro = LoadSound("sounds/Boca-4.mp3");

    agogoPadrao = LoadTexture("images/agogo.png");
    agogoBocaUm = LoadTexture("images/agogo_1.png");
    agogoBocaUmDois = LoadTexture("images/agogo_12.png");
    agogoBocaUmTres = LoadTexture("images/agogo_13.png");
    agogoBocaUmQuatro = LoadTexture("images/agogo_14.png");
    agogoBocaDois = LoadTexture("images/agogo_2.png");
    agogoBocaDoisTres = LoadTexture("images/agogo_23.png");
    agogoBocaDoisQuatro = LoadTexture("images/agogo_24.png");
    agogoBocaTres = LoadTexture("images/agogo_3.png");
    agogoBocaTresQuatro = LoadTexture("images/agogo_34.png");
    agogoBocaQuatro = LoadTexture("images/agogo_4.png");
    agogoTodos = LoadTexture("images/agogo_1234.png");

    bool keyOnePressed = false;
    bool keyOneTwoPressed = false;
    bool keyOneThreePressed = false;
    bool keyOneFourPressed = false;
    bool keyTwoPressed = false;
    bool keyTwoThreePressed = false;
    bool keyTwoFourPressed = false;
    bool keyThreePressed = false;
    bool keyThreeFourPressed = false;
    bool keyFourPressed = false;
    bool keyAllPressed = false;

    agogoTroca = agogoPadrao;

    while(!WindowShouldClose()){    

        if(IsKeyDown(KEY_ONE) && IsKeyDown(KEY_TWO)){
            if(!keyOneTwoPressed){
                agogoTroca = agogoBocaUmDois;
                PlaySound(sndBocaUm);
                PlaySound(sndBocaDois);
                keyOneTwoPressed = true;
            }
        }
        else if(IsKeyDown(KEY_ONE) && IsKeyDown(KEY_THREE)){
            if(!keyOneThreePressed){
                agogoTroca = agogoBocaUmTres;
                PlaySound(sndBocaUm);
                PlaySound(sndBocaTres);
                keyOneThreePressed = true;
            }
        }
        else if(IsKeyDown(KEY_ONE) && IsKeyDown(KEY_FOUR)){
            if(!keyOneFourPressed){
                agogoTroca = agogoBocaUmQuatro;
                PlaySound(sndBocaUm);
                PlaySound(sndBocaQuatro);
                keyOneFourPressed = true;
            }
        }
        else if(IsKeyDown(KEY_TWO) && IsKeyDown(KEY_THREE)){
            if(!keyTwoThreePressed){
                agogoTroca = agogoBocaDoisTres;
                PlaySound(sndBocaDois);
                PlaySound(sndBocaTres);
                keyTwoThreePressed = true;
            }
        }
        else if(IsKeyDown(KEY_TWO) && IsKeyDown(KEY_FOUR)){
            if(!keyTwoFourPressed){
                agogoTroca = agogoBocaDoisQuatro;
                PlaySound(sndBocaDois);
                PlaySound(sndBocaQuatro);
                keyTwoFourPressed = true;
            }
        }
        else if(IsKeyDown(KEY_THREE) && IsKeyDown(KEY_FOUR)){
            if(!keyThreeFourPressed){
                agogoTroca = agogoBocaTresQuatro;
                PlaySound(sndBocaTres);
                PlaySound(sndBocaQuatro);
                keyThreeFourPressed = true;
            }
        }
        else if(IsKeyDown(KEY_FIVE)){
            if(!keyAllPressed){
                agogoTroca = agogoTodos;
                PlaySound(sndBocaQuatro);
                PlaySound(sndBocaTres);
                PlaySound(sndBocaDois);
                PlaySound(sndBocaUm);
                keyAllPressed = true;
            }
        }
        else if(IsKeyDown(KEY_ONE)){
            if(!keyOnePressed){
                agogoTroca = agogoBocaUm;
                PlaySound(sndBocaUm);
                keyOnePressed = true;
            }
        }
        else if(IsKeyDown(KEY_TWO)){
            if(!keyTwoPressed){
                agogoTroca = agogoBocaDois;
                PlaySound(sndBocaDois);
                keyTwoPressed = true;
            }
        }
        else if(IsKeyDown(KEY_THREE)){
            if(!keyThreePressed){
                agogoTroca = agogoBocaTres;
                PlaySound(sndBocaTres);
                keyThreePressed = true;
            }
        }
        else if(IsKeyDown(KEY_FOUR)){
            if(!keyFourPressed){
                agogoTroca = agogoBocaQuatro;
                PlaySound(sndBocaQuatro);
                keyFourPressed = true;
            }
        }
        else{
            keyOnePressed = false;
            keyOneTwoPressed = false;
            keyOneThreePressed = false;
            keyOneFourPressed = false;
            keyTwoPressed = false;
            keyTwoThreePressed = false;
            keyTwoFourPressed = false;
            keyThreePressed = false;
            keyThreeFourPressed = false;
            keyFourPressed = false;
            keyAllPressed = false;
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
