/*  Home Day Skipper (EU)
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#ifndef PokemonAutomation_PokemonSwSh_HomeDaySkipperEU_H
#define PokemonAutomation_PokemonSwSh_HomeDaySkipperEU_H

#include "Common/Cpp/Options/StaticTextOption.h"
#include "Common/Cpp/Options/SimpleIntegerOption.h"
#include "CommonFramework/Notifications/EventNotificationsTable.h"
#include "NintendoSwitch/Options/NintendoSwitch_StartInGripMenuOption.h"
#include "NintendoSwitch/NintendoSwitch_SingleSwitchProgram.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonSwSh{


class HomeDaySkipperEU_Descriptor : public SingleSwitchProgramDescriptor{
public:
    HomeDaySkipperEU_Descriptor();

    virtual std::unique_ptr<StatsTracker> make_stats() const override;
};



class HomeDaySkipperEU : public SingleSwitchProgramInstance{
public:
    HomeDaySkipperEU();
    virtual void program(SingleSwitchProgramEnvironment& env, ProControllerContext& context) override;

private:
    void go_to_home_menu(SingleSwitchProgramEnvironment& env, ProControllerContext& context);
    void run_switch1(SingleSwitchProgramEnvironment& env, ProControllerContext& context);
    void run_switch2(SingleSwitchProgramEnvironment& env, ProControllerContext& context);

private:
    StartInGripOrGameOption START_LOCATION;

    SimpleIntegerOption<uint32_t> SKIPS;
    SimpleIntegerOption<uint16_t> REAL_LIFE_YEAR;

    EventNotificationOption NOTIFICATION_PROGRESS_UPDATE;
    EventNotificationOption NOTIFICATION_PROGRAM_FINISH;
    EventNotificationsOption NOTIFICATIONS;

    SectionDividerOption m_advanced_options;
    SimpleIntegerOption<uint16_t> CORRECTION_SKIPS;
};


}
}
}
#endif


