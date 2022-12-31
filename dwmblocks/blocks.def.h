// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/                              /*Update Interval*/ /*Update Signal*/
    {"  ",  "$HOME/.local/bin/dwmblocks/dwm-kernel", 3600,               0},
    {"﬙ ",   "$HOME/.local/bin/dwmblocks/dwm-memory", 1,                  0},
    {" ",   "$HOME/.local/bin/dwmblocks/dwm-temp",   5,                  0},
    {" ",   "$HOME/.local/bin/dwmblocks/dwm-pacman", 600,                0},
    {"墳 ",   "$HOME/.local/bin/dwmblocks/dwm-volume", 0,                10},
    {" ",   "$HOME/.local/bin/dwmblocks/dwm-date",	  3600,               0},
    {" ",   "$HOME/.local/bin/dwmblocks/dwm-clock",  60,                 0},
};

// Sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
