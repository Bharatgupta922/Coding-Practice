#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 160
#define HEIGHT 40

#define idx(a, b) ((a) + WIDTH * (b))

//user defined datatype
struct trail
{
    float start;
    float end;
    float speed;
} trails[WIDTH];

void init_trail(struct trail *trail)
{
    trail->start = -(float)(rand() % HEIGHT);
    //random height

    trail->end = 0;
    //initialises from zero index i.e row

    trail->speed = (rand() % 5) / 10.2f + 0.2f;
    //with random speed
}

void update_rain(CHAR_INFO consoleBuffer[])
{
    CHAR_INFO space = {.Char.AsciiChar = ' ', .Attributes = 0};
    //defining space between two consecutive trails in individual trails

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
            consoleBuffer[idx(x, y)] = space;
        //getting an apropriate space according to the coordinates
        // by formula ((a) + WIDTH * (b))  where a,b are coordinates

        int start = trails[x].start < 0 ? 0 : (int)trails[x].start;
        // pointer starts with zero

        int end = trails[x].end > HEIGHT ? HEIGHT : (int)trails[x].end;
        //pointer ends with the height of last trail + random height assigned for the space above
        for (int y = start; y < end; y++)
            consoleBuffer[idx(x, y)] = (CHAR_INFO){
                .Char.AsciiChar = rand() % 256, .Attributes = FOREGROUND_GREEN | (y < (int)trails[x].end - 1 ? 0 : 0x0004 | 0x0001)};
        //fill the trials with random characters with head white and tail green

        trails[x].start += trails[x].speed;
        trails[x].end += trails[x].speed;
        //update every index of trails to move
        if (trails[x].start >= HEIGHT)
            init_trail(&trails[x]);
    }
}

int main(void)
{

    // srand((unsigned)time(NULL));

    /* Console window */
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE); //handle is typedefine

    SMALL_RECT windowSize = {0, 0, WIDTH - 1, HEIGHT - 1};
    //setting the window size with left top right & bottom

    // SetConsoleWindowInfo(wHnd, FALSE, &windowSize);

    COORD bufferSize = {WIDTH, HEIGHT};
    // Defines the coordinates of a character cell in a console screen buffer.
    //The origin of the coordinate system (0,0) is at the top, left cell of the buffer.
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    CHAR_INFO consoleBuffer[WIDTH * HEIGHT];
    //consolement area

    COORD charBufSize = {WIDTH, HEIGHT};
    COORD characterPos = {0, 0};
    //initiation
    SMALL_RECT write = {0, 0, WIDTH - 1, HEIGHT - 1};
    //defining rectangle to write

    /* Trails */
    for (int i = 0; i < WIDTH; ++i)
        if (i % 2 == 0)
            init_trail(&trails[i]);

    /* Matrix */
    for (;;) //infinite loop
    {
        update_rain(consoleBuffer);
        WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &write);
        Sleep(10);
    }

    return 0;
}