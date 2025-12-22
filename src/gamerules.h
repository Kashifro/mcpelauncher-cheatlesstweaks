#pragma once
#include <cstddef>
#include <string>
//havent tested em all so idk
enum class GameRulesIndex : int {
    InvalidGameRule           = -1,
    CommandBlockOutput        = 0,
    DoDaylightCycle           = 1,
    DoEntityDrops             = 2,
    DoFireTick                = 3,
    RecipesUnlock             = 4,
    DoLimitedCrafting         = 5,
    DoMobLoot                 = 6,
    DoMobSpawning             = 7,
    DoTileDrops               = 8,
    DoWeatherCycle            = 9,
    DrowningDamage            = 10,
    FallDamage                = 11,
    FireDamage                = 12,
    KeepInventory             = 13,
    MobGriefing               = 14,
    Pvp                       = 15,
    ShowCoordinates           = 16,
    LocatorBar                = 17,
    ShowDaysPlayed            = 18,
    DoNaturalRegeneration     = 19,
    DoTntExplode              = 20,
    SendCommandFeedback       = 21,
    MaxCommandChainLength     = 22,
    DoInsomnia                = 23,
    CommandBlocksEnabled      = 24,
    RandomTickSpeed           = 25,
    DoImmediateRespawn        = 26,
    ShowDeathMessages         = 27,
    FunctionCommandLimit      = 28,
    PlayerSpawnRadius         = 29,
    ShowTags                  = 30,
    FreezeDamage              = 31,
    RespawnBlocksExplode      = 32,
    ShowBorderEffect          = 33,
    ShowRecipeMessages        = 34,
    PlayerSleepingPercentage  = 35,
    ProjectilesCanBreakBlocks = 36,
    TntExplosionDropDecay     = 37,
    VanillaGameRuleCount      = 38,
    GlobalMute                = 38,
    AllowDestructiveObjects   = 39,
    AllowMobs                 = 40,
    CodeBuilder               = 41,
    EduCloudSave              = 42,
    EduGameRuleCount          = 43,
    GameRuleCount             = 43,
};

struct GameRule {
    std::byte  pad0[0x04];        // 0x00
    bool       mEnabled;          // 0x04
    std::byte  pad1[0x03];        // 0x05
    std::string mName;            // 0x08 (libstdc++ = 0x18 bytes)
    std::byte  pad2[0x0B];        // 0x20 → 0x2B
    bool       mRequiresCheats;   // 0x2B
    std::byte  pad3[0x90 - 0x2C]; // rest
};

#include <vector>

struct GameRules {
    std::byte pad0[0x18];
    std::vector<GameRule> mGameRules;
};


// static_assert(sizeof(GameRule) == 0x90);
// static_assert(offsetof(GameRule, mRequiresCheats) == 0x2B);