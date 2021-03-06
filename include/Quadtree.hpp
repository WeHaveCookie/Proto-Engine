#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
#include "Structure.hpp"
#include "Constante.hpp"

#define DEBUG 1
#define DEBUGLOCAL 0
class Quadtree
{

    public:
        Quadtree(float x, float y, float width, float height);
        ~Quadtree();
        Quadtree(float x, float y, float width, float height, std::vector<std::shared_ptr<sf::Sprite>> obj);
        bool add(sf::Sprite obj);
        std::vector<std::shared_ptr<sf::Sprite>> del(sf::FloatRect pos);
        std::vector<std::shared_ptr<sf::Sprite>> queryRange(sf::FloatRect pos);
        inline sf::FloatRect getShape() {return m_shape;}

        void clear();
        void draw(sf::RenderWindow* window);
        void displayTile(bool b);
        inline bool isDisplayTile() {return m_displayTile;}
        inline bool isEnable() {return m_enable;}

    protected:
        inline bool isEmpty() {return m_elements.empty();}
        int nbElement();
        inline  std::vector<std::shared_ptr<sf::Sprite>> getElements() {return m_elements;}
    private:
        void subdivide();
        void merge();
        std::vector<std::shared_ptr<sf::Sprite>> eraseSplitedElement(sf::FloatRect pos);
        Quadtree* m_northWest;
        Quadtree* m_northEast;
        Quadtree* m_southWest;
        Quadtree* m_southEast;
        std::vector<std::shared_ptr<sf::Sprite>> m_elements;
        std::vector<std::shared_ptr<SplitedSprite>> m_splitedElements;
        sf::RectangleShape m_boundary;
        sf::FloatRect m_shape;
        bool m_enable;
        bool m_displayTile;
};

#endif // QUADTREE_H
