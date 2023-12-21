/**
* @file  main.h
* @author Губеев Е.Д.
* @version 1.0
* @brief Описание классов, подключение библиотек и переменных
* @date 16.12.2023
* @copyright ИБСТ ПГУ
*/
#include "mdfile.h"
int main(int argc, char *argv[]) {
    Server Server;
    auth auth;
    while (true) {
        string* com = Server.comstr(argc, argv);
        int s = Server.self_addr(com[3], com[2], stoi(com[1]));
        int work_sock = Server.client_addr(s, com[3], com[2]);
        auth.autorized(work_sock, com[0], com[2]);
        math(work_sock);
        delete[] com; 
        return 0;
    }
    return 0;
}
