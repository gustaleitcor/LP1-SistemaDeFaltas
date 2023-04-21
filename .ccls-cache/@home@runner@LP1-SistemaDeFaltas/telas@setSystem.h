#pragma once
#ifdef _WIN32
#define CLEAR_CONSOLE "cls"
#elif __linux__
#define CLEAR_CONSOLE "clear"
#endif