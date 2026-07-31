
// Test code to verify library installation

// #include <mpv/client.h>
// #include <ftxui/dom/elements.hpp>
// #include <ftxui/screen/screen.hpp>
// #include <cstdio>

// int main() {
//   // mpv
//   mpv_handle *mpv = mpv_create();
//   if (!mpv) { std::fprintf(stderr, "mpv_create failed\n"); return 1; }
//   mpv_terminate_destroy(mpv);

//   // ftxui
//   using namespace ftxui;
//   auto doc = paragraph("hello from ftxui + mpv");
//   auto screen = Screen::Create(Dimension::Fixed(40), Dimension::Fixed(3));
//   Render(screen, doc);
//   screen.Print();

//   return 0;
// }
//

#include <print>

int main(void){
    std::print("i am small pea!!");
    return 0;
}
