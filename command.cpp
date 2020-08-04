#include "command.h"
#include "display.h"
#include "main_window.h"
#include "effect_param_window.h"
#include "effects_rack.h"

volatile unsigned char cmd_type[MAX_COMMAND_BUF] = {CMD_NA}; // The actuall commands
volatile unsigned char cmd_count = 0;                        // Conunt of how many commands are in the buffer
volatile unsigned char cmd_pos;                              // Record the current command being handled

// The command handler
void command_handler()
{
    //------------------------INT disabled
    noInterrupts();
    if (cmd_count == 0)
    {
        interrupts();
        return;
    }
    unsigned char cmd_type_cpy = cmd_type[cmd_pos];
    cmd_pos++;
    cmd_pos %= 20;
    cmd_count--;
    interrupts();
    //------------------------INT enabled

    switch (cmd_type_cpy)
    {
    case CMD_NA:
        break;

    case CMD_EFFECTS_PARAM_INC:
        if (signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].enable)
        {
            if (signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value + effect_param_window_ins.cur_step <= 255)
            {
                signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value += effect_param_window_ins.cur_step;
            }
            else
            {
                signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value = 255;
            }
            signal_chain[main_window_ins.cur_effect]->set_param(effect_param_window_ins.cur_param,
                                                                signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value);
        }
        break;

    case CMD_EFFECTS_PARAM_DEC:
        if (signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].enable)
        {
            if (signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value - effect_param_window_ins.cur_step >= 0)
            {
                signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value -= effect_param_window_ins.cur_step;
            }
            else
            {
                signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value = 0;
            }
            signal_chain[main_window_ins.cur_effect]->set_param(effect_param_window_ins.cur_param,
                                                                signal_chain[main_window_ins.cur_effect]->param[effect_param_window_ins.cur_param].value);
        }
        break;

    case CMD_UI_SIG_CUR_LEFT:
        if (main_window_ins.cur_effect != 9)
        {
            main_window_ins.cur_effect++;
        }
        break;

    case CMD_UI_SIG_CUR_RIGHT:
        if (main_window_ins.cur_effect != 0)
        {
            main_window_ins.cur_effect--;
        }
        break;

    case CMD_UI_SIG_CUR_SELECT:
        if (signal_chain[main_window_ins.cur_effect] != nullptr)
            display.change_window(EFFECT_PARAM_WINDOW);
        break;

    case CMD_UI_SIG_CUR_ONOFF:
        if (signal_chain[main_window_ins.cur_effect] != nullptr)
        {
            signal_chain[main_window_ins.cur_effect]->enable = !signal_chain[main_window_ins.cur_effect]->enable;
        }
        break;

    case CMD_UI_PARAM_CUR_LEFT:
        if (effect_param_window_ins.cur_param > 1)
        {
            effect_param_window_ins.cur_param -= 2;
        }
        break;

    case CMD_UI_PARAM_CUR_RIGHT:
        if (effect_param_window_ins.cur_param < 4)
        {
            effect_param_window_ins.cur_param += 2;
        }
        break;

    case CMD_UI_PARAM_CUR_UP:
        if (effect_param_window_ins.cur_param % 2 != 0)
        {
            effect_param_window_ins.cur_param--;
        }
        break;

    case CMD_UI_PARAM_CUR_DOWN:
        if (effect_param_window_ins.cur_param % 2 != 1)
        {
            effect_param_window_ins.cur_param++;
        }
        break;

    case CMD_UI_PARAM_CUR_SELECT:
        display.change_window(MAIN_WINDOW);
        break;

    case CMD_UI_PARAM_STEP:
        if (effect_param_window_ins.cur_step == 1)
        {
            effect_param_window_ins.cur_step = 4;
        }
        else if (effect_param_window_ins.cur_step == 4)
        {
            effect_param_window_ins.cur_step = 8;
        }
        else if (effect_param_window_ins.cur_step == 8)
        {
            effect_param_window_ins.cur_step = 1;
        }
        break;

    default:
        break;
    }
}