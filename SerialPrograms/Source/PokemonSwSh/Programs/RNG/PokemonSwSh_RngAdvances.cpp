/*  Braviary Height Glitch
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#include "CommonFramework/ProgramStats/StatsTracking.h"
#include "NintendoSwitch/Commands/NintendoSwitch_Commands_PushButtons.h"
#include "NintendoSwitch/Programs/NintendoSwitch_GameEntry.h"
#include "Pokemon/Pokemon_Strings.h"
#include "PokemonSwSh_RngAdvances.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonSwSh{
    using namespace Pokemon;


class RngAdvances_Descriptor::Stats : public StatsTracker{
public:
    Stats()
        : advances(m_stats["Advances"])
        , errors(m_stats["Errors"])
    {
        m_display_order.emplace_back(Stat("Advances"));
        m_display_order.emplace_back(Stat("Errors"));
    }

public:
    std::atomic<uint64_t>& advances;
    std::atomic<uint64_t>& errors;
};
std::unique_ptr<StatsTracker> RngAdvances_Descriptor::make_stats() const{
    return std::unique_ptr<StatsTracker>(new Stats());
}


RngAdvances_Descriptor::RngAdvances_Descriptor()
    : SingleSwitchProgramDescriptor(
        "PokemonSwSh:RngAdvances",
        STRING_POKEMON + " SwSh", "Rng Advances",
        "Programs/PokemonSwSh/RngAdvances.html",
        "Increase your height in place using the height glitch.",
        ProgramControllerClass::StandardController_NoRestrictions,
        FeedbackType::NONE,
        AllowCommandsWhenRunning::DISABLE_COMMANDS
    )
{}


RngAdvances::RngAdvances()
    : SKIPS(
        "<b>Number of Skips:</b>",
        LockMode::LOCK_WHILE_RUNNING,
        3, 0, 60
    )
{
    PA_ADD_OPTION(SKIPS);
}


void RngAdvances::program(SingleSwitchProgramEnvironment& env, ProControllerContext& context){
    RngAdvances_Descriptor::Stats& stats = env.current_stats<RngAdvances_Descriptor::Stats>();

    require_player(env.console, context, BUTTON_LCLICK);
    for (size_t i = 0; i < SKIPS; i++){
        pbf_press_button(context, BUTTON_RCLICK, 20ms, 25ms);
    }
    stats.advances+=SKIPS;
    env.update_stats();
}




}
}
}
