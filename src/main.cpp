#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio/miniaudio.h>
#include <iostream>
#include <string>

int main()
{
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(nullptr, &engine);
    if (result != MA_SUCCESS)
        return -1;

    std::string filePath;
    std::cout << "Enter sound path: ";
    std::getline(std::cin, filePath);   
    if (ma_engine_play_sound(&engine, filePath.c_str(), nullptr) != MA_SUCCESS)
        std::cerr << "Could not play sound\n";

    std::cout << "Press Enter to quit...";
    std::cin.get();

    ma_engine_uninit(&engine);
    return 0;
}