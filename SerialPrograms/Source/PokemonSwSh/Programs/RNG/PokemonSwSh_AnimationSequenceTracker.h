/*  RNG Manipulation Animation Sequence Tracker
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#ifndef PokemonAutomation_PokemonSwSh_AnimationSequenceTracker_H
#define PokemonAutomation_PokemonSwSh_AnimationSequenceTracker_H

#include "Common/Cpp/Options/BooleanCheckBoxOption.h"
#include "Common/Cpp/Options/SimpleIntegerOption.h"
#include "Common/Cpp/Options/StaticTextOption.h"
#include "Common/Cpp/Options/StringOption.h"
#include "NintendoSwitch/Options/NintendoSwitch_StartInGripMenuOption.h"
#include "NintendoSwitch/NintendoSwitch_SingleSwitchProgram.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonSwSh{

class AnimationSequenceTracker_Descriptor : public SingleSwitchProgramDescriptor{
public:
    AnimationSequenceTracker_Descriptor();
};


class AnimationSequenceTracker : public SingleSwitchProgramInstance{
public:
    AnimationSequenceTracker();

    virtual void program(SingleSwitchProgramEnvironment& env, ProControllerContext& context) override;

private:
    StartInGripOrGameOption START_LOCATION;

    SimpleIntegerOption<uint32_t> ANIMATION_COUNT;
    StringOption SEQUENCE;

    SectionDividerOption m_advanced_options;
    BooleanCheckBoxOption SAVE_SCREENSHOTS;
    BooleanCheckBoxOption LOG_VALUES;
};




}
}
}
#endif


