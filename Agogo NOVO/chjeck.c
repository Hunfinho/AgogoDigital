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