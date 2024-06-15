#include <vector>

typedef enum class ConnectorType
{
    NARROW_BRIDGE,
    FERRY,
    CROSSROAD,
} ConnectorType;

typedef struct path
{
    ConnectorType connectorType;
    int connectorID;
    std::pair<int, int> direction; // (From Direction, To Direction)
} Path;

typedef struct car
{
    int travelTime;
    int pathLength;
    std::vector<Path> pathList; // (Connector Type, Connector ID) , (From Direction, To Direction): every pair is a path
} Car;

// util functions
char typeToChar(ConnectorType type)
{
    switch (type)
    {
    case ConnectorType::NARROW_BRIDGE:
        return 'N';
    case ConnectorType::FERRY:
        return 'F';
    case ConnectorType::CROSSROAD:
        return 'C';
    default:
        break;
    }
    return '-';
}