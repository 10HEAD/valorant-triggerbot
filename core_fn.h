#pragma once
#include <Windows.h>
#include <cstdint>
#include <iostream>
#include "rzctl.h"
#include <Psapi.h>
#include "color_ref.h"


#define PROCESS_NAME L"VALORANT  " 

BOOL r = FALSE;
BOOL t = FALSE;

void toggle_check(char value) {

    if (GetAsyncKeyState(VK_F1))
    {
        r = TRUE;
    }
    if (GetAsyncKeyState(VK_HOME))
    {
        r = FALSE;
    }
}

void toggle_checkt(char value) {

    if (GetAsyncKeyState(VK_INSERT))
    {
        t = TRUE;
    }
    if (GetAsyncKeyState(VK_F2))
    {
        t = FALSE;
    }
}

int start()
{
        printf("VLTB 1.0 - 10HEAD - 0 at 0 \n", 0);
        printf("[*] checking for rzctl driver...\n", 0);
        Sleep(1000);
        int toleration = 50;
        struct vlp preset;
        preset.x = 20;
        preset.y = 20;
        preset.d = 0;
        if (!rzctl::init()) {
            printf("Failed to initalize rzctl\n", 0);
            return 0;
        }
        else
        {
            printf("[+] rzctl driver is present\n", 0);
        }
        Sleep(1000);
        printf("[*] getting display capture...\n", 0); // xddddddddddddddddddddddddddddddddddddddddddddddddddd lol 
        Sleep(1000);
        printf("[+] display capture module loaded\n", 0);


}


    void additional()
    {
        if (GetAsyncKeyState(VK_F9)) {
            printf("[vlp]", 2); printf(" modify preset : \n", 0);
            printf("[#] Modify X amount (0-99): ", 0);
            scanf_s("%d", &data_vlp.x);
            printf("[#] Modify Y amount (0-99): ", 0);
            scanf_s("%d", &data_vlp.y);
            printf("[#] Modify D amount (0-250): ", 0);
            scanf_s("%d", &data_vlp.d);
            printf("[#] Modify R amount (0-5): ", 0);
            scanf_s("%d", &data_vlp.r);
            printf("[vlp]", 1); printf("preset set\n", 0);
        }
    }

    void run() {
        printf("[*] modify presets <F9>\n", 0);
        HWND game_window;
        game_window = FindWindowW(NULL, PROCESS_NAME);
        HDC hDC1 = GetDC(game_window);
        POINT pt1;
        COLORREF rgb1;
        BOOL color_check;

        while (1) {
            toggle_check('r');
            additional();
            toggle_checkt('t');
            if (t) {
                while (1) {
                    if (!t)
                        break;
                    color_check = scan(hDC1, 960, 540);
                    if (color_check == TRUE) {
                        color_check = scan(hDC1, 960, 540);
                        if (color_check == TRUE) {
                            rzctl::mouse_click(1);
                            Sleep(1);
                            rzctl::mouse_click(2);
                            Sleep(1);
                            //printf("SHOOT \n");
                            Sleep(100);
                            break;
                        }
                    }
                }
            }
        }


        if (r)
        {
            if (GetAsyncKeyState(VK_LBUTTON)) {
                while (1) {
                    if (!GetAsyncKeyState(VK_LBUTTON))
                        break;
                    rzctl::mouse_move((char)0, (char)data_vlp.r);
                    Sleep(1);
                }
            }
        }
        Sleep(1);

    }
        
    
    
  