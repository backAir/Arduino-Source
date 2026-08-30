/*  Braviary Height Glitch
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#ifndef PokemonAutomation_PokemonSwSh_RngAdvances_H
#define PokemonAutomation_PokemonSwSh_RngAdvances_H

#include "Common/Cpp/Options/SimpleIntegerOption.h"
#include "Common/Cpp/Options/TimeDurationOption.h"
#include "CommonFramework/Notifications/EventNotificationsTable.h"
#include "NintendoSwitch/NintendoSwitch_SingleSwitchProgram.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonSwSh{


class RngAdvances_Descriptor : public SingleSwitchProgramDescriptor{
public:
    RngAdvances_Descriptor();

    class Stats;
    virtual std::unique_ptr<StatsTracker> make_stats() const override;
};


class RngAdvances : public SingleSwitchProgramInstance{
public:
    RngAdvances();

    virtual void program(SingleSwitchProgramEnvironment& env, ProControllerContext& context) override;

private:
    SimpleIntegerOption<uint32_t> SKIPS;
    MillisecondsOption ADVANCE_PRESS_DURATION;
    MillisecondsOption ADVANCE_RELEASE_DURATION;

    EventNotificationsOption NOTIFICATIONS;
};





}
}
}
#endif
