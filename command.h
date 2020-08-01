#ifndef COMMAND_H
#define COMMAND_H

#define MAX_COMMAND_BUF 20

// volatile command variables for interrupt handling

// List of command to commuitcate with main loop
enum command : unsigned char{
    // Empty command
    CMD_NA,
    // Effects command
    CMD_EFFECTS_,
    // UI command
    CMD_UI_SIG_CUR_LEFT,
    CMD_UI_SIG_CUR_RIGHT,
    CMD_UI_SIG_CUR_SELECT,
    CMD_UI_SIG_CUR_ONOFF,
    // Settings command
    CMD_SET_
};

void command_handler();

extern volatile unsigned char cmd_type[MAX_COMMAND_BUF]; // The actuall commands
extern volatile unsigned char cmd_count; // Conunt of how many commands are in the buffer
extern volatile unsigned char cmd_pos; // Record the current command being handled

#endif