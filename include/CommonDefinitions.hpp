#ifndef COMMONDEFINITIONS_H
#define COMMONDEFINITIONS_H

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
}

#endif // COMMONDEFINITIONS_H
