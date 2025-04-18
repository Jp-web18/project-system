// colors.h
#ifndef COLORS_H
#define COLORS_H


#define RESET   "\x1b[0m"
#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define BG_BLACK   "\x1b[40m" // Background colors (+10)
#define BG_RED     "\x1b[41m"
#define BG_GREEN   "\x1b[42m"
#define BG_YELLOW  "\x1b[43m"
#define BG_BLUE    "\x1b[44m"
#define BG_MAGENTA "\x1b[45m"
#define BG_CYAN    "\x1b[46m"




// Function to set console color
/*
void setConsoleColor() {
    system("color 1F");
}

*/

// ... other background colors
#define YELLOW_ON_BLUE YELLOW BG_BLUE // Combined color

#endif