/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 50;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 40;   /* vert outer gap between windows and screen edge */
static const int smartgaps               = 1;   /* 1 means no outer gap when there is only one window */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int horizpadbar             = 5;   /* horizontal padding for statusbar */
static const int vertpadbar              = 5;   /* vertical padding for statusbar */
static const int focusonnetactive        = 1;   /* 0 means default behaviour, 1 means auto-focus on urgent window */
static const int attachmode              = 2;   /* 0 = master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const int pertag                  = 1;   /* 0 means global layout across all tags (default), 1 = layout per tag (pertag) */
static const int pertagbar               = 0;   /* 0 means using pertag, but with the same barpos, 1 = normal pertag */
static const int zoomswap                = 1;   /* 0 means default behaviour, 1 = zoomswap patch */
static const int fancybar                = 0;   /* 0 means default behaviour, 1 = fancybar patch */
static const int savefloats              = 1;   /* 0 means default behaviour, 1 = savefloats patch */
static const int losefullscreen          = 1;   /* 0 means default behaviour, 1 = losefullscreen patch */
static const int nrg_force_vsplit        = 1;   /* nrowgrid layout, 1 means force 2 clients to always split vertically */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 0;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const char *fonts[]               = { "Ubuntu Mono Bold:size=12" };
static const char dmenufont[]            = "Ubuntu Mono Bold:size=12";
static const char col_gray1[]            = "#1c2023";
static const char col_gray2[]            = "#111111";
static const char col_gray3[]            = "#c5c8c6";  // status fg
static const char col_gray4[]            = "#1d1f21";
static const char col_cyan[]             = "#f0c674"; // bar color
static const unsigned int baralpha       = 0xd0;
static const unsigned int borderalpha    = OPAQUE;


// ! special
// *.foreground:   #c5c8c6
// *.background:   #1d1f21
// *.cursorColor:  #c5c8c6
//
// ! black
// *.color0:       #1d1f21
// *.color8:       #969896
//
// ! red
// *.color1:       #cc6666
// *.color9:       #cc6666
//
// ! green
// *.color2:       #b5bd68
// *.color10:      #b5bd68
//
// ! yellow
// *.color3:       #f0c674
// *.color11:      #f0c674
//
// ! blue
// *.color4:       #81a2be
// *.color12:      #81a2be
//
// ! magenta
// *.color5:       #b294bb
// *.color13:      #b294bb
//
// ! cyan
// *.color6:       #8abeb7
// *.color14:      #8abeb7
//
// ! white
// *.color7:       #c5c8c6
// *.color15:      #ffffff


static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  WM_WINDOW_ROLE(STRING) = role1c2023
	 */
	/* class            role                          instance     title   tags mask  switchtag  iscentered   isfloating   monitor */
	{ "Gimp",           NULL,                         NULL,        NULL,   1 << 4,    1,         0,           1,           -1 },
	{ "Firefox",        NULL,                         NULL,        NULL,   1 << 7,    1,         0,           0,           -1 },
	{ "Google-chrome",  "GtkFileChooserDialog",       "Save File", NULL,   0,         0,         1,           1,           -1 },
	{ "Google-chrome",  "pop-up",                     NULL,        NULL,   0,         0,         1,           1,           -1 },
	{ "Google-chrome",  "browser",                    NULL,        NULL,   1 << 7,    1,         1,           0,            2 },
	{ "Slack",          NULL,                         NULL,        NULL,   1 << 1,    1,         0,           0,            1 },
	{ "Sublime_text",   NULL,                         NULL,        NULL,   1 << 6,    1,         0,           0,           -1 },
	{ "Diffuse",        NULL,                         NULL,        NULL,   1 << 3,    1,         0,           0,           -1 },
	{ "File-roller",    NULL,                         NULL,        NULL,   1 << 8,    1,         1,           1,           -1 },
	{ "Gedit",          NULL,                         NULL,        NULL,   0,         0,         1,           1,           -1 },
	{ "SpiderOakONE",   NULL,                         NULL,        NULL,   0,         0,         1,           1,           -1 },
	{ "Gnome-terminal", "gnome-terminal-preferences", NULL,        NULL,   0,         0,         1,           0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "vanitygaps.c"
#include <X11/XF86keysym.h>

static const int layoutaxis[] = {
	SPLIT_VERTICAL,   /* layout axis: 1 = x, 2 = y; negative values mirror the layout, setting the master area to the right / bottom instead of left / top */
	TOP_TO_BOTTOM,    /* master axis: 1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle), 4 = grid */
	TOP_TO_BOTTOM,    /* stack axis:  1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle), 4 = grid */
};

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[]=",	flextile }, /* first entry is default */
	{ "[M]",	monocle },
	{ "=M=",	centeredmaster },
	{ "⧉⟧⧠",	NULL },    /* no layout function means floating behavior */
	{ "⧉M⧠",	centeredfloatingmaster },
	{ "⚎⚎⚎",	bstack },
	{ "☰☰☰",	bstackhoriz },
	{ "𝍖𝍖𝍖",	grid },
	{ ":::",	gaplessgrid },
	{ "---",	horizgrid },
	{ "###",	nrowgrid },
	{ "⟦@⟧",	spiral },
	{ "⟦➘⟧",	dwindle },
	{ "D[]",	deck },
	{ "[]=",	tile },
	{ NULL,		NULL },
};

/* key definitions */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4,  NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static Key keys[] = {
	/* modifier                     key        function           argument */
	{ MODKEY,                       XK_d,      spawn,             {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,             {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,         {0} },
	{ MODKEY,                       XK_j,      focusstack,        {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_j,      rotatestack,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_k,      rotatestack,       {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,        {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,        {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,          {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,          {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,          {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,          {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,          {.f =  0.00} },
	{ MODKEY,                       XK_m,      zoom,              {0} },
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,          {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,          {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,         {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,         {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,        {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,       {0} },
	{ MODKEY,                       XK_Tab,    view,              {0} },
	{ Mod1Mask,                     XK_Tab,    view,              {0} },
	{ Mod1Mask|ControlMask,         XK_Tab,    view,              {0} },
	{ MODKEY,                       XK_q,      killclient,        {0} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_1,      setlayout,         {.v = &layouts[0]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_2,      setlayout,         {.v = &layouts[1]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_3,      setlayout,         {.v = &layouts[2]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_4,      setlayout,         {.v = &layouts[3]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_5,      setlayout,         {.v = &layouts[4]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_6,      setlayout,         {.v = &layouts[5]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_7,      setlayout,         {.v = &layouts[6]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_8,      setlayout,         {.v = &layouts[7]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_9,      setlayout,         {.v = &layouts[8]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_0,      setlayout,         {.v = &layouts[9]} },
	{ MODKEY,                       XK_w,      setflexlayout,     {.i = 293 } }, // centered master
	{ MODKEY,                       XK_e,      setflexlayout,     {.i = 273 } }, // bstackhoriz layout
	{ MODKEY,                       XK_r,      setflexlayout,     {.i = 272 } }, // bstack layout
	{ MODKEY,                       XK_t,      setflexlayout,     {.i = 261 } }, // default tile layout
	{ MODKEY,                       XK_g,      setflexlayout,     {.i = 263 } }, // tile + grid layout
	{ MODKEY|ControlMask,           XK_w,      setflexlayout,     {.i =   7 } }, // grid
	{ MODKEY|ControlMask,           XK_e,      setflexlayout,     {.i = 262 } }, // deck layout
	{ MODKEY|ControlMask,           XK_r,      setflexlayout,     {.i =   6 } }, // monocle
	{ MODKEY|ControlMask,           XK_g,      setflexlayout,     {.i = 257 } }, // columns (col) layout
	{ MODKEY,                       XK_space,  setlayout,         {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,    {0} },
	// { MODKEY,                       XK_f,      togglefullscreen,  {0} },
	{ MODKEY,                       XK_0,      view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,               {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,          {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,          {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_comma,  tagmon,            {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_period, tagmon,            {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_comma,  tagallmon,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_period, tagallmon,         {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_comma,  tagswapmon,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_period, tagswapmon,        {.i = -1 } },
	TAGKEYS(                        XK_1,                         0)
	TAGKEYS(                        XK_2,                         1)
	TAGKEYS(                        XK_3,                         2)
	TAGKEYS(                        XK_4,                         3)
	TAGKEYS(                        XK_5,                         4)
	TAGKEYS(                        XK_6,                         5)
	TAGKEYS(                        XK_7,                         6)
	TAGKEYS(                        XK_8,                         7)
	TAGKEYS(                        XK_9,                         8)
	TAGKEYS(                        XK_F1,                        0)
	TAGKEYS(                        XK_F2,                        1)
	TAGKEYS(                        XK_F3,                        2)
	TAGKEYS(                        XK_F4,                        3)
	TAGKEYS(                        XK_F5,                        4)
	TAGKEYS(                        XK_F6,                        5)
	TAGKEYS(                        XK_F7,                        6)
	TAGKEYS(                        XK_F8,                        7)
	TAGKEYS(                        XK_F9,                        8)
	{ MODKEY|ShiftMask,             XK_q,      quit,              {0} },
	{ MODKEY|ControlMask,           XK_t,      rotatelayoutaxis,  {.i = 0} },    /* flextile, 0 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,    rotatelayoutaxis,  {.i = 1} },    /* flextile, 1 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,    rotatelayoutaxis,  {.i = 2} },    /* flextile, 2 = stack axis */
	{ MODKEY|ControlMask,           XK_Return, mirrorlayout,      {0} },         /* flextile, flip master and stack areas */
	{ 0, XF86XK_AudioMute,	       	spawn,		SHCMD("/home/igg/git/configs/custom_scripts/vol_mute") },
	{ 0, XF86XK_AudioRaiseVolume,		spawn,		SHCMD("/home/igg/git/configs/custom_scripts/vol_up") },
	{ 0, XF86XK_AudioLowerVolume,		spawn,		SHCMD("/home/igg/git/configs/custom_scripts/vol_down") },
	{ 0, XF86XK_MonBrightnessUp,  	spawn,		SHCMD("light -A 15") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("light -U 15") },
	{ MODKEY, 											XK_p,			spawn,	          	SHCMD("firefox") },
	{ MODKEY, 											XK_o,			spawn,	          	SHCMD("atom") },
	{ MODKEY, 											XK_z,			spawn,	          	SHCMD("alacritty -e nvim /home/igg/git/wiki_me/wiki_me.md") },
	{ MODKEY, 											XK_x,			spawn,	          	SHCMD("alacritty -e nvim /home/igg/git/wiki_me/to_do.md") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask         button          function        argument */
	{ ClkLtSymbol,          0,                 Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                 Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkLtSymbol,          0,                 Button4,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,                 Button5,        cyclelayout,    {.i = -1 } },
	{ ClkWinTitle,          0,                 Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                 Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,            Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,            Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,            Button4,        rotatestack,    {.i = +1 } },
	{ ClkClientWin,         MODKEY,            Button5,        rotatestack,    {.i = -1 } },
	{ ClkClientWin,         MODKEY,            Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button4,        cyclelayout,    {.i = -1 } },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button5,        cyclelayout,    {.i = +1 } },
	{ ClkTagBar,            0,                 Button1,        view,           {0} },
	{ ClkTagBar,            0,                 Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,            Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,            Button3,        toggletag,      {0} },
};

