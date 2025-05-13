



#define OLC_PGE_APPLICATION
// MACOS requires stb_image.h to be placed in the same folder as olcPixelGameEngine.h
// You can still use OLC_IMAGE_LIBPNG by removing the define below
#define OLC_GFX_MACOS_TEMP
#define OLC_IMAGE_STB
#include "olcPixelGameEngine.h"


class Example : public olc::PixelGameEngine {
    public:
        Example() {
            sAppName = "Example";
        }

    public:
        bool OnUserCreate() override {
            // Called once at the start, so create things here
            return true;
        }

        bool OnUserUpdate(float fElapsedTime) override {
            Clear(olc::BLACK);
            // called once per frame
            for (int x = 0; x < ScreenWidth(); x++)
                for (int y = 0; y < ScreenHeight(); y++)
                    Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));
            
            FillRect(GetMouseX(), GetMouseY(), 1, 1);
            return true;
        }
};


int main(int argc, char const *argv[]) {
	Example demo;
	if (demo.Construct(15, 10, 32, 32))
		demo.Start();

	return 0;
}
