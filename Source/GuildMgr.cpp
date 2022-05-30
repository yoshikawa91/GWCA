#include "stdafx.h"

#include <GWCA/Packets/Opcodes.h>
#include <GWCA/Utilities/Export.h>
#include <GWCA/Utilities/Scanner.h>

#include <GWCA/GameEntities/Guild.h>
#include <GWCA/Context/GameContext.h>
#include <GWCA/Context/GuildContext.h>

#include <GWCA/Managers/Module.h>
#include <GWCA/Managers/UIMgr.h>

#include <GWCA/Managers/CtoSMgr.h>
#include <GWCA/Managers/GuildMgr.h>

namespace GW {

    Module GuildModule{
        "GuildModule",  // name
        NULL,           // param
        NULL,           // init_module
        NULL,           // exit_module
        NULL,           // exit_module
        NULL,           // remove_hooks
    };
    namespace GuildMgr {
        wchar_t* GetPlayerGuildAnnouncer() {
            auto* g = GuildContext::instance();
            return g ? g->announcement_author : nullptr;
        }

        wchar_t* GetPlayerGuildAnnouncement() {
            auto* g = GuildContext::instance();
            return g ? g->announcement : nullptr;
        }

        uint32_t GetPlayerGuildIndex() {
            auto* g = GuildContext::instance();
            return g ? g->player_guild_index : 0;
        }

        GuildArray* GetGuildArray() {
            auto* g = GuildContext::instance();
            return g && g->guilds.valid() ? &g->guilds : nullptr;
        }

        bool TravelGH() {
            auto* g = GuildContext::instance();
            return g ? TravelGH(g->player_gh_key) : false;

        }

        bool TravelGH(GHKey key) {
            UI::SendUIMessage(UI::kGuildHall, &key);
            return true;
        }

        void LeaveGH() {
            UI::SendUIMessage(UI::kLeaveGuildHall, nullptr);
        }
    }
} // namespace GW
