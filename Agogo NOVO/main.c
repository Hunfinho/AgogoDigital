#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <raylib.h>
#define MENU_QUANT 4
#define AGOGO_QUANT 35

// gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

typedef enum{
    DESAFIO,
    PRATICAR,
    CONFIGURACAO,
    SAIR
}Opcao;

typedef enum{
    PBOCAUM,
    SBOCAUM,
    PBOCADOIS,
    SBOCADOIS,
    PBOCATRES,
    SBOCATRES,
    PBOCAQUATRO,
    SBOCAQUATRO,
    PBOCATODOS,
    SBOCATODOS
}Binds;

static const char *textoMenus[] = {
    "Desafio", 
    "Praticar",
    "Configurações",
    "Sair",
    "Voltar",
    "Padrão"
};

static const char* textoAgogo[] = {
    "3 2 1 4321   3 2 1 4321   3 2 1 4321   1  2  3  4",
    "121  121  121  121 121 1212121 121 121 1212121",
    "5 5   1221221",
    "1 21 121  1 21 121  1 21 121  1 21 12 3332341",
    "1121 121 123333   1121 121 12333",
    "1 1 1",
    "2343 2343 2343  1 2 3 4",
    "1213212  1213212  3434332  1  1213212",
    "1 121 121 12333   1 121 121 12333   1 121 121 12333",
    "111111 222222 333333 4",
    "(nova cavalgada)",
    "333 22 11 22 333 2 4   2 1 2 1 212   44 33 22",
    "1232 1232 1232   1 1 1   12324 1232 12324",
    "43432 444333221 43434 434",
    "(novo tokyo)",
    "1 1 1 1 123 11123 111234 4 432124 432124 12311",
    "1 1 1 1 123 11123 111234 4 432124 432124 12311",
    "1 1 1 1 1",
    "(novo tokyo)",
    "1   1 23  4323231",
    "111 3212 333 43234 444 323 21 21 21 21 2",
    "111 3212 333 43234 444 323 21 21 21 21 2 11",
    "111123 333212   111123 333212", 
    "111123 333212   111123 333212",
    "(novo final)",
    "12321 123212 1 1 1   1 1 11 1112223332",
};

void descarregaUso(){}

int main(){

    //const int screenWidth = 540;
    const int screenWidth = 900;
    const int screenHeight = 675;

    InitWindow(screenWidth, screenHeight , "Agogo da shopee");
    InitAudioDevice();

    Texture agogoPadrao, agogoBocaUm, agogoBocaUmDois, agogoBocaUmTres, agogoBocaUmQuatro,
        agogoBocaDois, agogoBocaDoisTres, agogoBocaDoisQuatro,
        agogoBocaTres, agogoBocaTresQuatro,
        agogoBocaQuatro, agogoTodos, agogoTroca,
        agoguinhoBocaUm, agoguinhoBocaDois,
        agoguinhoBocaTres, agoguinhoBocaQuatro,
        agoguinhoTodos, agogoBackground;

    Image agogoIcone;

    Sound sndBocaUm = LoadSound("sounds/Boca-1.mp3");
    Sound sndBocaDois = LoadSound("sounds/Boca-2.mp3");
    Sound sndBocaTres = LoadSound("sounds/Boca-3.mp3");
    Sound sndBocaQuatro = LoadSound("sounds/Boca-4.mp3");
    Sound sndTeste = LoadSound("sounds/adventuring_song.mp3");
    Sound sndDesafio = LoadSound("sounds/desafio.mp3");

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
    agogoBackground = LoadTexture("images/background.png");
    agoguinhoBocaUm = LoadTexture("images/agoguinho_1.png");
    agoguinhoBocaDois = LoadTexture("images/agoguinho_2.png");
    agoguinhoBocaTres = LoadTexture("images/agoguinho_3.png");
    agoguinhoBocaQuatro = LoadTexture("images/agoguinho_4.png");
    agoguinhoTodos = LoadTexture("images/agoguinho_1234.png");
    agogoIcone = LoadImage("images/icon.ico");

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

    char tocaBocaUm = KEY_ONE;
    char tocaBocaUmToo= KEY_F;
    char tocaBocaDois = KEY_TWO;
    char tocaBocaDoisToo = KEY_G;
    char tocaBocaTres = KEY_THREE;
    char tocaBocaTresToo = KEY_H; 
    char tocaBocaQuatro = KEY_FOUR;
    char tocaBocaQuatroToo = KEY_J;
    char tocaTodasBocas = KEY_FIVE;
    char tocaTodasBocasToo = KEY_K;

    agogoTroca = agogoPadrao;

    bool sndDesafioTocado = false;

    int processoAtual;
    int mouseHover = -1;
    int voltarCheck = 404;
    int redefinirCheck = 303;
    char alteraKey = -1;
    bool digitarKey = false;
    bool menuPrincipal = 1;

    SetWindowIcon(agogoIcone);

    Rectangle barraOpcao[MENU_QUANT] = {0};
    Rectangle barraVoltar = {0};
    Rectangle barraRedefinir = {0};
    //Rectangle textBox[10] = {88, 88, 16, 50};
    Rectangle textBox[10] = {0};
    for(int i = 0 ; i < 10 ; i++){
        textBox[i] = (Rectangle){32+88*i, 405, 44, 44};
    }
    Rectangle container = {545.0f, 5.0f, 350.0f, 665.0f};

    while(!WindowShouldClose()){    

        if(menuPrincipal){

            for(int i = 0 ; i < MENU_QUANT ; i++){
                barraOpcao[i] = (Rectangle){ 300.0f, (float)(413 + 32*i), 300.0f, 30.0f };
            }

            for(int i = 0; i < MENU_QUANT; i++){
                if(CheckCollisionPointRec(GetMousePosition(), barraOpcao[i])){
                    mouseHover = i;
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        processoAtual = i;
                        menuPrincipal = false;
                    }
                    break;
                }
                else mouseHover = -1;
            }

            if(sndDesafioTocado){
                PauseSound(sndDesafio);
                sndDesafioTocado = false;
            }
        }

        else{
            
            switch(processoAtual){
                case DESAFIO:
                    if(!sndDesafioTocado){
                        PlaySound(sndDesafio);
                        sndDesafioTocado = true;
                    }
                    if((IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)) && (IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo))){
                        if(!keyOneTwoPressed){
                            agogoTroca = agogoBocaUmDois;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaDois);
                            keyOneTwoPressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)) && (IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo))){
                        if(!keyOneThreePressed){
                            agogoTroca = agogoBocaUmTres;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaTres);
                            keyOneThreePressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)) && (IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo))){
                        if(!keyOneFourPressed){
                            agogoTroca = agogoBocaUmQuatro;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaQuatro);
                            keyOneFourPressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo)) && (IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo))){
                        if(!keyTwoThreePressed){
                            agogoTroca = agogoBocaDoisTres;
                            PlaySound(sndBocaDois);
                            PlaySound(sndBocaTres);
                            keyTwoThreePressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo)) && (IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo))){
                        if(!keyTwoFourPressed){
                            agogoTroca = agogoBocaDoisQuatro;
                            PlaySound(sndBocaDois);
                            PlaySound(sndBocaQuatro);
                            keyTwoFourPressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo)) && (IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo))){
                        if(!keyThreeFourPressed){
                            agogoTroca = agogoBocaTresQuatro;
                            PlaySound(sndBocaTres);
                            PlaySound(sndBocaQuatro);
                            keyThreeFourPressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaTodasBocas)||IsKeyDown(tocaTodasBocasToo)){
                        if(!keyAllPressed){
                            agogoTroca = agogoTodos;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaDois);
                            PlaySound(sndBocaTres);
                            PlaySound(sndBocaQuatro);
                            keyAllPressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)){
                        if(!keyOnePressed){
                            agogoTroca = agogoBocaUm;
                            PlaySound(sndBocaUm);
                            keyOnePressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo)){
                        if(!keyTwoPressed){
                            agogoTroca = agogoBocaDois;
                            PlaySound(sndBocaDois);
                            keyTwoPressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo)){
                        if(!keyThreePressed){
                            agogoTroca = agogoBocaTres;
                            PlaySound(sndBocaTres);
                            keyThreePressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo)){
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
                    barraVoltar = (Rectangle){ 0.0f, 645.0f, 75.0f, 30.0f };
                    for(int i = 0; i < 1; i++){
                        if(CheckCollisionPointRec(GetMousePosition(), barraVoltar)){
                            mouseHover = voltarCheck;
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                processoAtual = i;
                                menuPrincipal = true;
                            }
                            break;
                        }
                        else mouseHover = -1;
                    }
                break;
                case PRATICAR:
                    if((IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)) && (IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo))){
                        if(!keyOneTwoPressed){
                            agogoTroca = agogoBocaUmDois;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaDois);
                            keyOneTwoPressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)) && (IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo))){
                        if(!keyOneThreePressed){
                            agogoTroca = agogoBocaUmTres;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaTres);
                            keyOneThreePressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)) && (IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo))){
                        if(!keyOneFourPressed){
                            agogoTroca = agogoBocaUmQuatro;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaQuatro);
                            keyOneFourPressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo)) && (IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo))){
                        if(!keyTwoThreePressed){
                            agogoTroca = agogoBocaDoisTres;
                            PlaySound(sndBocaDois);
                            PlaySound(sndBocaTres);
                            keyTwoThreePressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo)) && (IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo))){
                        if(!keyTwoFourPressed){
                            agogoTroca = agogoBocaDoisQuatro;
                            PlaySound(sndBocaDois);
                            PlaySound(sndBocaQuatro);
                            keyTwoFourPressed = true;
                        }
                    }
                    else if((IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo)) && (IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo))){
                        if(!keyThreeFourPressed){
                            agogoTroca = agogoBocaTresQuatro;
                            PlaySound(sndBocaTres);
                            PlaySound(sndBocaQuatro);
                            keyThreeFourPressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaTodasBocas)||IsKeyDown(tocaTodasBocasToo)){
                        if(!keyAllPressed){
                            agogoTroca = agogoTodos;
                            PlaySound(sndBocaUm);
                            PlaySound(sndBocaDois);
                            PlaySound(sndBocaTres);
                            PlaySound(sndBocaQuatro);
                            keyAllPressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaUm)||IsKeyDown(tocaBocaUmToo)){
                        if(!keyOnePressed){
                            agogoTroca = agogoBocaUm;
                            PlaySound(sndBocaUm);
                            keyOnePressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaDois)||IsKeyDown(tocaBocaDoisToo)){
                        if(!keyTwoPressed){
                            agogoTroca = agogoBocaDois;
                            PlaySound(sndBocaDois);
                            keyTwoPressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaTres)||IsKeyDown(tocaBocaTresToo)){
                        if(!keyThreePressed){
                            agogoTroca = agogoBocaTres;
                            PlaySound(sndBocaTres);
                            keyThreePressed = true;
                        }
                    }
                    else if(IsKeyDown(tocaBocaQuatro)||IsKeyDown(tocaBocaQuatroToo)){
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
                    barraVoltar = (Rectangle){ 0.0f, 645.0f, 75.0f, 30.0f };
                    for(int i = 0; i < 1; i++){
                    if(CheckCollisionPointRec(GetMousePosition(), barraVoltar)){
                        mouseHover = voltarCheck;
                        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                            processoAtual = i;
                            menuPrincipal = true;
                        }
                        break;
                    }
                    else mouseHover = -1;
                }
                break;
                case CONFIGURACAO:
                    barraVoltar = (Rectangle){ 0.0f, 645.0f, 75.0f, 30.0f };
                    barraRedefinir = (Rectangle){ 825.0f, 645.0f, 75.0f, 30.0f};
                    for(int i = 0; i < 10; i++){
                        if(CheckCollisionPointRec(GetMousePosition(), textBox[i])){
                            mouseHover = i;
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                alteraKey = i;
                                digitarKey = true;
                            }
                            break;
                        }
                        else if(CheckCollisionPointRec(GetMousePosition(), barraVoltar)){
                            mouseHover = voltarCheck;
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                processoAtual = i;
                                menuPrincipal = true;
                            }
                            break;
                        }
                        else if(CheckCollisionPointRec(GetMousePosition(), barraRedefinir)){
                            mouseHover = redefinirCheck;
                            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                                tocaBocaUm = KEY_ONE;
                                tocaBocaUmToo= KEY_F;
                                tocaBocaDois = KEY_TWO;
                                tocaBocaDoisToo = KEY_G;
                                tocaBocaTres = KEY_THREE;
                                tocaBocaTresToo = KEY_H; 
                                tocaBocaQuatro = KEY_FOUR;
                                tocaBocaQuatroToo = KEY_J;
                                tocaTodasBocas = KEY_FIVE;
                                tocaTodasBocasToo = KEY_K;
                            }
                        }
                        else mouseHover = -1;
                    }


                    if(digitarKey){
                        char tempKey = GetCharPressed();
                        if(tempKey){
                            tempKey = toupper(tempKey); 
                            switch(alteraKey){
                                case PBOCAUM:
                                    tocaBocaUm = tempKey;
                                break;
                                case SBOCAUM:
                                    tocaBocaUmToo = tempKey;
                                break;
                                case PBOCADOIS:
                                    tocaBocaDois = tempKey;
                                break;
                                case SBOCADOIS:
                                    tocaBocaDoisToo = tempKey;
                                break;
                                case PBOCATRES:
                                    tocaBocaTres = tempKey;
                                break;
                                case SBOCATRES:
                                    tocaBocaTresToo = tempKey;
                                break;
                                case PBOCAQUATRO:
                                    tocaBocaQuatro = tempKey;
                                break;
                                case SBOCAQUATRO:
                                    tocaBocaQuatroToo = tempKey;
                                break;
                                case PBOCATODOS:
                                    tocaTodasBocas = tempKey;
                                break;
                                case SBOCATODOS:
                                    tocaTodasBocasToo = tempKey;
                                break;
                                default:
                                break;
                            }
                            digitarKey = false;
                        }
                    }                   
                break;
                default:
                break;     
            }  

            
            //barraVoltar = (Rectangle){ 300.0f, 413.0f, 75.0f, 30.0f };
            //barraRedefinir = (Rectangle){ 825.0f, 645.0f, 75.0f, 30.0f};
        /*
            //barraVoltar = (Rectangle){ 0.0f, 645.0f, 75.0f, 30.0f };
        
            for(int i = 0; i < 1; i++){
                if(CheckCollisionPointRec(GetMousePosition(), barraVoltar)){
                    mouseHover = voltarCheck;
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                        processoAtual = i;
                        menuPrincipal = true;
                    }
                    break;
                }
                else mouseHover = -1;
            }   */     
               
        }         

        BeginDrawing();

            Color grena = {131, 29, 28, 255};

            if(menuPrincipal){
                DrawTexture(agogoBackground, 0, 0, WHITE);
                for (int i = 0; i < MENU_QUANT; i++)
                {
                    DrawRectangleRec(barraOpcao[i], (i == mouseHover) ? SKYBLUE : grena);
                    DrawRectangleLines((int)barraOpcao[i].x, (int) barraOpcao[i].y, (int) barraOpcao[i].width, (int) barraOpcao[i].height, (i == mouseHover) ? BLUE : BLACK);
                    DrawText( textoMenus[i], (int)( barraOpcao[i].x + barraOpcao[i].width/2 - MeasureText(textoMenus[i], 10)/2), (int) barraOpcao[i].y + 11, 12, (i == mouseHover) ? DARKBLUE : BLACK);
                }
            }
            else{
                ClearBackground(grena);
                switch(processoAtual){
                    case DESAFIO:
                        DrawTexture(agogoTroca, 0, 0, WHITE);
                        DrawRectangleRec(barraVoltar, (voltarCheck == mouseHover) ? SKYBLUE : grena);
                        DrawRectangleLines((int)barraVoltar.x, (int) barraVoltar.y, (int) barraVoltar.width, (int) barraVoltar.height, (voltarCheck == mouseHover) ? BLUE : BLACK);
                        DrawText( textoMenus[4], (int)( barraVoltar.x + barraVoltar.width/2 - MeasureText(textoMenus[4], 10)/2), (int) barraVoltar.y + 11, 12, (voltarCheck == mouseHover) ? DARKBLUE : BLACK);                   

                        DrawRectangleLinesEx(container, 3, BLACK);

                        for(int i = 0 ; i < AGOGO_QUANT ; i++){
                            DrawText(textoAgogo[i], 561, 20+16*i, 14, BLACK);
                        }

                    break;
                    case PRATICAR:
                        DrawTexture(agogoTroca, 0, 0, WHITE);
                        DrawRectangleRec(barraVoltar, (voltarCheck == mouseHover) ? SKYBLUE : grena);
                        DrawRectangleLines((int)barraVoltar.x, (int) barraVoltar.y, (int) barraVoltar.width, (int) barraVoltar.height, (voltarCheck == mouseHover) ? BLUE : BLACK);
                        DrawText( textoMenus[4], (int)( barraVoltar.x + barraVoltar.width/2 - MeasureText(textoMenus[4], 10)/2), (int) barraVoltar.y + 11, 12, (voltarCheck == mouseHover) ? DARKBLUE : BLACK);
                        
                        DrawRectangleLinesEx(container, 3, BLACK);

                    break;
                    case CONFIGURACAO:
                        DrawTexture(agoguinhoBocaUm, 16, 188, WHITE);
                        DrawTexture(agoguinhoBocaDois, 193, 188, WHITE);
                        DrawTexture(agoguinhoBocaTres, 370, 188, WHITE);
                        DrawTexture(agoguinhoBocaQuatro, 547, 188, WHITE);
                        DrawTexture(agoguinhoTodos, 724, 188, WHITE);
                        for(int i = 0 ; i < 10 ; i++){
                            DrawRectangleRec(textBox[i], (i == mouseHover) ? SKYBLUE : grena);
                            if(digitarKey){
                                DrawRectangleRec(textBox[alteraKey], BLUE);
                            }
                            DrawRectangleLines((int)textBox[i].x, (int) textBox[i].y, (int) textBox[i].width, (int) textBox[i].height, (i == mouseHover) ? BLUE : BLACK);
                            if(i==PBOCAUM){
                                DrawText(TextFormat("%c", tocaBocaUm), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaUm), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==SBOCAUM){
                                DrawText(TextFormat("%c", tocaBocaUmToo), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaUmToo), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==PBOCADOIS){
                                DrawText(TextFormat("%c", tocaBocaDois), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaDois), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==SBOCADOIS){
                                DrawText(TextFormat("%c", tocaBocaDoisToo), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaDoisToo), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==PBOCATRES){
                                DrawText(TextFormat("%c", tocaBocaTres), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaTres), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==SBOCATRES){
                                DrawText(TextFormat("%c", tocaBocaTresToo), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaTresToo), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==PBOCAQUATRO){
                                DrawText(TextFormat("%c", tocaBocaQuatro), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaQuatro), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==SBOCAQUATRO){
                                DrawText(TextFormat("%c", tocaBocaQuatroToo), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaBocaQuatroToo), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==PBOCATODOS){
                                DrawText(TextFormat("%c", tocaTodasBocas), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaTodasBocas), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                            else if(i==SBOCATODOS){
                                DrawText(TextFormat("%c", tocaTodasBocasToo), (int)( textBox[i].x + textBox[i].width/2 - MeasureText(TextFormat("%c", tocaTodasBocasToo), 17)/2), (int) textBox[i].y + 14, 17, (i == mouseHover) ? DARKBLUE : BLACK);
                            }
                        }
                        DrawRectangleRec(barraVoltar, (voltarCheck == mouseHover) ? SKYBLUE : grena);
                        DrawRectangleLines((int)barraVoltar.x, (int) barraVoltar.y, (int) barraVoltar.width, (int) barraVoltar.height, (voltarCheck == mouseHover) ? BLUE : BLACK);
                        DrawText( textoMenus[4], (int)( barraVoltar.x + barraVoltar.width/2 - MeasureText(textoMenus[4], 10)/2), (int) barraVoltar.y + 11, 12, (voltarCheck == mouseHover) ? DARKBLUE : BLACK);

                        DrawRectangleRec(barraRedefinir, (redefinirCheck == mouseHover) ? SKYBLUE : grena);
                        DrawRectangleLines((int)barraRedefinir.x, (int) barraRedefinir.y, (int) barraRedefinir.width, (int) barraRedefinir.height, (redefinirCheck == mouseHover) ? BLUE : BLACK);
                        DrawText( textoMenus[5], (int)( barraRedefinir.x + barraRedefinir.width/2 - MeasureText(textoMenus[5], 10)/2), (int) barraRedefinir.y + 11, 12, (redefinirCheck == mouseHover) ? DARKBLUE : BLACK);
                        
                    break;
                    case SAIR:
                            goto fecharPrograma;
                        break;
                    default:
                    break;
                }
        

        }
        EndDrawing();
        
    }

    fecharPrograma:

    UnloadTexture(agogoPadrao);
    UnloadTexture(agogoBocaUm);
    UnloadTexture(agogoBocaUmDois);
    UnloadTexture(agogoBocaUmTres);
    UnloadTexture(agogoBocaUmQuatro);
    UnloadTexture(agogoBocaDois);
    UnloadTexture(agogoBocaDoisTres);
    UnloadTexture(agogoBocaDoisQuatro);
    UnloadTexture(agogoBocaTres);
    UnloadTexture(agogoBocaTresQuatro);
    UnloadTexture(agogoBocaQuatro);
    UnloadTexture(agogoTodos);
    UnloadTexture(agogoBackground);
    UnloadTexture(agoguinhoBocaUm);
    UnloadTexture(agoguinhoBocaDois);
    UnloadTexture(agoguinhoBocaTres);
    UnloadTexture(agoguinhoBocaQuatro);
    UnloadTexture(agoguinhoTodos);

    UnloadSound(sndBocaUm);
    UnloadSound(sndBocaDois);
    UnloadSound(sndBocaTres);
    UnloadSound(sndBocaQuatro);
    UnloadSound(sndTeste);
    UnloadSound(sndDesafio);

    CloseAudioDevice();
    CloseWindow();


    return 0;
}
