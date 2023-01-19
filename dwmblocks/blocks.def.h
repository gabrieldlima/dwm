#define PATH(name) "/home/gabriel/.local/bin/statusbar/"name

// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/        /*Update Interval*/ /*Update Signal*/
    {" ",    PATH("sb-kernel"), 600,                0},
    {"",     PATH("sb-cpu"),    1,                  0},
    {"",     PATH("sb-memory"), 1,                  0},
    {"",     PATH("sb-temp"),   1,                  0},
    {"",     PATH("sb-pacman"), 600,                0},
    {"",     PATH("sb-volume"), 1,                  0},
    {"",     PATH("sb-date"),   60,                 0},
    {"",     PATH("sb-clock"),  60,                 0},
};

// Sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
