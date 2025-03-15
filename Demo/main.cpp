#include <iostream>
#include <SFML/Graphics.hpp>
#define PI 3.14159265359f
sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Engine");
#include "Demo.h"
#include <World.h>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    demo1();
    World::init({ 0.0f, 10.0f });


    sf::Clock clock;
    bool pause = false;
    float dt = 0.0f;
    float timeScale = 1.0f;
    sf::View originalView = window.getDefaultView();
    sf::View zoomedView = window.getDefaultView();
    zoomedView.zoom(1.0f / 10.0f);

    while (window.isOpen())
    {
        sf::Event evt;
        while (window.pollEvent(evt))
        {
            if (evt.type == sf::Event::Closed)
                window.close();
            if (evt.type == sf::Event::KeyPressed)
            {
                switch (evt.key.code)
                {
                case sf::Keyboard::Num1: World::reset(); demo1(); break;
                case sf::Keyboard::Num2: World::reset(); demo2(); break;
                case sf::Keyboard::Num3: World::reset(); demo3(); break;
                case sf::Keyboard::Num4: World::reset(); demo4(); break;
                }
            }
                //pause = !pause;
        }
        dt += clock.restart().asSeconds();
        //
        // threshold값이 step의 dt값보다 n배 크면 실제 시뮬레이션은 1/n배속된다.
        if (dt < 0.01f / timeScale) continue;
        if (pause) continue;
        window.clear(sf::Color::Black);
        //dt = clock.restart().asSeconds();
        World::step(0.01f, 8, 6);
        window.setView(zoomedView);
        window.display();
        dt = 0.0f;
    }
    return 0;
}