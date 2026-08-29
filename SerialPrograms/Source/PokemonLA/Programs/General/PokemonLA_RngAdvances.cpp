/*  Braviary Height Glitch
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#include "NintendoSwitch/Commands/NintendoSwitch_Commands_PushButtons.h"
#include "NintendoSwitch/Programs/NintendoSwitch_GameEntry.h"
#include "Pokemon/Pokemon_Strings.h"
#include "PokemonLA_RngAdvances.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonLA{
    using namespace Pokemon;


RngAdvances_Descriptor::RngAdvances_Descriptor()
    : SingleSwitchProgramDescriptor(
        "PokemonLA:RngAdvances",
        STRING_POKEMON + " LA", "Rng Advances",
        "Programs/PokemonLA/RngAdvances.html",
        "Increase your height in place using the height glitch.",
        ProgramControllerClass::StandardController_NoRestrictions,
        FeedbackType::NONE,
        AllowCommandsWhenRunning::DISABLE_COMMANDS
    )
{}


RngAdvances::RngAdvances(){}


void RngAdvances::program(SingleSwitchProgramEnvironment& env, ProControllerContext& context){
    //  Connect the controller.
    require_player(env.console, context, BUTTON_LCLICK);

    while (true){
        pbf_press_button(context, BUTTON_Y, 240ms, 0ms);
        pbf_press_button(context, BUTTON_PLUS, 240ms, 80ms);
        pbf_press_button(context, BUTTON_PLUS, 240ms, 240ms);
    }
}




}
}
}
