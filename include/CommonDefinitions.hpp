#ifndef COMMONDEFINITIONS_H
#define COMMONDEFINITIONS_H

#include <string>
namespace SemantisedTriangleMesh {
    enum class FlagType
    {
        VISITED,
        USED,
        ON_BOUNDARY,
        ON_HOLE,
        INSIDE,
        OUTSIDE,
        TO_BE_REMOVED,
        SELECTED
    };

    static std::string flagToString(FlagType value)
    {
        std::string result;

        switch (value) {
            case FlagType::VISITED: result = "VISITED"; break;
            case FlagType::USED: result = "USED"; break;
            case FlagType::ON_BOUNDARY: result = "ON_BOUNDARY"; break;
            case FlagType::ON_HOLE: result = "ON_HOLE"; break;
            case FlagType::INSIDE: result = "INSIDE"; break;
            case FlagType::OUTSIDE: result = "OUTSIDE"; break;
            case FlagType::TO_BE_REMOVED: result = "TO_BE_REMOVED"; break;
            case FlagType::SELECTED: result = "SELECTED"; break;
            default: result = "UNKNOWN";
        }

        return result;
    }

}
#endif // COMMONDEFINITIONS_H
