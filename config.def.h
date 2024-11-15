#include "themes/catppuccin.h"

#define BROWSER  "qutebrowser"
#define LAUNCHER "rofi -show drun"
#define TERMINAL "wezterm"

/* appearance */
static const unsigned int borderpx  = 2;    /* border pixel of windows */
static const unsigned int gappx     = 10;   /* gaps between windows */
static const unsigned int snap      = 32;   /* snap pixel */
static const int showbar            = 1;    /* 0 means no bar */
static const int topbar             = 1;    /* 0 means bottom bar */
static const char *fonts[]          = { "FiraCode Nerd Font:size=10" };
static const char *colors[][3]      = {
    /*               fg           bg           border         */
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
static const char *tags[] = { "cmd", "web", "dev", "sys", "kvm" };

/* rules */
static const Rule rules[] = {
    /* class            instance    title    tags mask    isfloating    monitor */
    { NULL,             NULL,       NULL,    0,           False,       -1 },
    { "Brave-browser",  NULL,       NULL,    1 << 1,      False,       -1 },
};

/* layout(s) */
static const float mfact         = 0.5;     /* factor of master area size [0.05..0.95] */
static const int nmaster         = 1;       /* number of clients in master area */
static const int resizehints     = 0;       /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen  = 1;       /* 1 will force focus on the fullscreen window */
static const Layout layouts[]    = {
    { "[]=", tile    },
    { "><>", NULL    },
    { "[M]", monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *browser[]   = { BROWSER,    NULL };
static const char *launcher[]  = { LAUNCHER,   NULL };
static const char *terminal[]  = { TERMINAL ,  NULL };

static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          {.v = launcher } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = terminal } },
    { MODKEY,                       XK_b,      spawn,          {.v = browser } },
    { MODKEY,                       XK_e,      spawn,          {.v = (const char*[]){ TERMINAL, "-e", "lf", NULL } } },
    { MODKEY,                       XK_o,      togglebar,      {0} },
    { MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,  spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%; pkill -RTMIN+10 dwmblocks") },
    { MODKEY,                       XK_equal,  spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%; pkill -RTMIN+10 dwmblocks") },
    { MODKEY|ShiftMask,             XK_Tab,    spawn,          SHCMD("sb-keyboard toogle; pkill -RTMIN+11 dwmblocks") },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = terminal } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
