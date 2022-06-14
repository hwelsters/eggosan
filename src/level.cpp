#include "../include/level.h"
#include "../include/tinyxml2.h"

Level::Level() {}
Level::~Level() {}

void Level::update(int elapsedTime)
{
}

void Level::draw(Graphics &graphics)
{
    for (Sprite tile : this->_backgroundTileList)
        tile.draw(graphics);

    for (Sprite tile : this->_midgroundTileList)
        tile.draw(graphics);

    for (Sprite tile : this->_foregroundTileList)
        tile.draw(graphics);
}

// Every tile sprite will be placed into one PNG file.
// I don't want to go back and change the XML file everytime I decide to change something
void Level::loadMap(Graphics &graphics, std::string mapName)
{
    int tileWidth, tileHeight;
    int levelWidth, levelHeight;

    tinyxml2::XMLDocument levelDocument;
    levelDocument.LoadFile(mapName.c_str());

    if (levelDocument.Error())
    {
        levelDocument.PrintError();
        return;
    }

    tinyxml2::XMLElement *mapElement = levelDocument.FirstChildElement("map");
    if (mapElement == nullptr)
    {
        printf("Map Element does not exist in XML Document: %s\n", mapName);
        return;
    }

    mapElement->QueryIntAttribute("tilewidth", &tileWidth);
        mapElement->QueryIntAttribute("tileheight", &tileHeight);
        mapElement->QueryIntAttribute("width", &levelWidth);
        mapElement->QueryIntAttribute("height", &levelHeight);
}