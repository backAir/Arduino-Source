/*  RNG Manipulation Animation Sequence Tracker
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#include "CommonFramework/Exceptions/OperationFailedExceptionWithScreenshot.h"
#include "NintendoSwitch/NintendoSwitch_Settings.h"
#include "NintendoSwitch/Commands/NintendoSwitch_Commands_PushButtons.h"
#include "NintendoSwitch/Programs/NintendoSwitch_GameEntry.h"
#include "Pokemon/Pokemon_Strings.h"
#include "PokemonSwSh/Inference/RNG/PokemonSwSh_OrbeetleAttackAnimationDetector.h"
#include "PokemonSwSh/Programs/PokemonSwSh_GameEntry.h"
#include "PokemonSwSh/Programs/RNG/PokemonSwSh_AnimationSequenceTracker.h"

#include <string>

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonSwSh{
using namespace Pokemon;

AnimationSequenceTracker_Descriptor::AnimationSequenceTracker_Descriptor()
    : SingleSwitchProgramDescriptor(
        "PokemonSwSh:AnimationSequenceTracker",
        STRING_POKEMON + " SwSh", "Animation Sequence Tracker",
        "Programs/PokemonSwSh/AnimationSequenceTracker.html",
        "Tracks special/physical Orbeetle attack animations and logs the sequence.",
        ProgramControllerClass::StandardController_NoRestrictions,
        FeedbackType::REQUIRED,
        AllowCommandsWhenRunning::DISABLE_COMMANDS
    )
{}

AnimationSequenceTracker::AnimationSequenceTracker()
    : ANIMATION_COUNT(
        "<b>Number of Animations:</b>",
        LockMode::LOCK_WHILE_RUNNING,
        128, 1, 10000
    )
    , m_advanced_options(
        "<font size=4><b>Advanced Options:</b> You should not need to touch anything below here.</font>"
    )
    , SAVE_SCREENSHOTS(
        "<b>Save Debug Screenshots:</b>",
        LockMode::LOCK_WHILE_RUNNING,
        false
    )
    , LOG_VALUES(
        "<b>Log Animation Values:</br>",
        LockMode::LOCK_WHILE_RUNNING,
        false
    )
{
    PA_ADD_OPTION(START_LOCATION);
    PA_ADD_OPTION(ANIMATION_COUNT);

    PA_ADD_STATIC(m_advanced_options);
    PA_ADD_OPTION(SAVE_SCREENSHOTS);
    PA_ADD_OPTION(LOG_VALUES);
}



void AnimationSequenceTracker::program(SingleSwitchProgramEnvironment& env, ProControllerContext& context){
    if (START_LOCATION.start_in_grip_menu()){
        grip_menu_connect_go_home(context);
        resume_game_back_out(
            env.console,
            context,
            ConsoleSettings::instance().TOLERATE_SYSTEM_UPDATE_MENU_FAST,
            1600ms
        );
    }else{
        require_player(env.console, context, BUTTON_LEFT);
    }

    OrbeetleAttackAnimationDetector detector(env.console, context);
    std::string sequence;
    sequence.reserve(ANIMATION_COUNT);

    for (size_t i = 0; i < ANIMATION_COUNT; i++){
        context.wait_for_all_requests();

        std::string text = std::to_string(i + 1) + "/" + std::to_string((size_t)ANIMATION_COUNT);
        OrbeetleAttackAnimationDetector::Detection detection = detector.run(SAVE_SCREENSHOTS, LOG_VALUES);
        switch (detection){
        case OrbeetleAttackAnimationDetector::NO_DETECTION:
            OperationFailedExceptionWithScreenshot::fire(
                ErrorReport::SEND_ERROR_REPORT,
                "Attack animation could not be detected.",
                env.console
            );
        case OrbeetleAttackAnimationDetector::SPECIAL:
            text += " : Special";
            sequence += '1';
            break;
        case OrbeetleAttackAnimationDetector::PHYSICAL:
            text += " : Physical";
            sequence += '0';
            break;
        }
        env.console.overlay().add_log(text, COLOR_BLUE);
        pbf_wait(context, 1440ms);
    }

    env.console.log("Animation sequence: " + sequence);
}


}
}
}
