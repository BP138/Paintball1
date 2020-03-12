#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"
#include "Ball.h"

sf::CircleShape createReticule();
sf::Vector2f calculateReticulePosition(sf::RenderWindow &wndw);



int main()
{
//Create Window //x6
sf::RenderWindow window(sf::VideoMode(720, 900), "Paintball!",
                        sf::Style::Close | sf::Style::Resize);
window.setFramerateLimit(60);
sf::Vector2u windowSize = window.getSize();
window.setMouseCursorVisible(false);


//Create field
//NXL 5 man field size: 150x120 feet
//NXL 10 man field size: 200x150 feet
sf::RectangleShape field(sf::Vector2f(720.0f, 900.0f));
sf::Texture fieldTexture;
fieldTexture.loadFromFile("green-grass-texture-background.png");
field.setTexture(&fieldTexture);

//Determine players per team and create game
std::cout << "How many players per team? ";
int pPerTeam = 0;
std::cin >> pPerTeam;
Game game(2, pPerTeam);
game.positionTeams(windowSize);

std::cout << "Total players: " << game.getPlayers().size() << std::endl;
std::cout << "Team 1 size: " << game.getTeam(0).size() << std::endl;
std::cout << "Team 2 size: " << game.getTeam(1).size() << std::endl;


//Create mouse position variable and set position of reticule shape
sf::CircleShape reticule = createReticule();

//Key event booleans
bool wButton = false;
bool aButton = false;
bool sButton = false;
bool dButton = false;
bool mouseLPressed = false;


//Time. Still need to figure out how to make it more fixed or accurate
sf::Clock clock;
float dt = 0;
sf::Time time;

//Create event and start game loop
sf::Event evnt;

while (window.isOpen())
{
    //Events
    while(window.pollEvent(evnt))
    {
        switch(evnt.type)
        {
            //window closed event
            case sf::Event::Closed:
                window.close();
                break;

                //window resize event
            case sf::Event::Resized:
                printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);

                break;

            //keyboard events
            case sf::Event::KeyPressed:
                if (evnt.key.code == sf::Keyboard::W) wButton = true;
                if (evnt.key.code == sf::Keyboard::A) aButton = true;
                if (evnt.key.code == sf::Keyboard::S) sButton = true; 
                if (evnt.key.code == sf::Keyboard::D) dButton = true; 
                break;

            case sf::Event::KeyReleased:
                if (evnt.key.code == sf::Keyboard::W) wButton = false;
                if (evnt.key.code == sf::Keyboard::A) aButton = false;
                if (evnt.key.code == sf::Keyboard::S) sButton = false;
                if (evnt.key.code == sf::Keyboard::D) dButton = false;
                break;

            //mouse events
            case sf::Event::MouseButtonPressed:
                if (evnt.mouseButton.button == sf::Mouse::Left) mouseLPressed = true;
                break;
            case sf::Event::MouseButtonReleased:
                if (evnt.mouseButton.button == sf::Mouse::Left) mouseLPressed = false;
                break;

            

            /*
            //print text entered
            case sf::Event::TextEntered:
                if(evnt.text.unicode < 128) printf("%c", evnt.text.unicode);
                break;
            */

            default: break;
        }
    }

    //Keybinds
    if(wButton) game.getTeamPlayer(0,0).movePlayer('w', dt);//up
    if(aButton) game.getTeamPlayer(0,0).movePlayer('a', dt);//left
    if(dButton) game.getTeamPlayer(0,0).movePlayer('d', dt);//right
    if(sButton) game.getTeamPlayer(0,0).movePlayer('s', dt); //down

    //Set reticule position
    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    reticule.setPosition(mousePosition);


    //shoot
    //Need to figure out how to put this in its own function
    if(mouseLPressed)
    {
        mouseLPressed = false;
        game.getTeamPlayer(0, 0).shootGun(mousePosition);
    }

    for (int p = 0; p < game.getNumberofPlayers(); p++)
    {
        for (int b = 0; b < game.getPlayers().at(p).getBallsFired().size(); b++)
        {
            if (game.getPlayers().at(p).getBallsFired().at(b).getLifeTime() > 2.0f) game.getPlayers().at(p).removeBall(b);
            else game.getPlayers().at(p).getBallsFired().at(b).updateBall(dt);
        }
    }



    
    //Rendering
    window.clear();
    window.draw(field);
    window.draw(reticule);
    //Render players
    for (int p = 0; p < game.getNumberofPlayers(); p++){
        window.draw(game.getPlayers().at(p).getPlayer());
    }
    //Render players' balls fired
    for (int p = 0; p < game.getNumberofPlayers(); p++)
    {
        for (int b = 0; b < game.getPlayers().at(p).getBallsFired().size(); b++)
        {
            window.draw(game.getPlayers().at(p).getBallsFired().at(b).getBall());
        }
    }

    window.display();

   
    //Restart the clock and set dt to the time since the clock was last restarted
    dt = clock.restart().asSeconds();
}


return 0;
}


sf::CircleShape createReticule()
{
    sf::CircleShape ret(4);
    ret.setFillColor(sf::Color::Transparent);
    ret.setOutlineColor(sf::Color::Yellow);
    ret.setOutlineThickness(1.15f);
    ret.setOrigin(ret.getRadius(), ret.getRadius());
    return ret;
}

sf::Vector2f calculateReticulePosition(sf::RenderWindow &wndw)
{
    return static_cast<sf::Vector2f>(sf::Mouse::getPosition(wndw));
}
