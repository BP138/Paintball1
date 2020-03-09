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
//Create Window
sf::RenderWindow window(sf::VideoMode(400, 720), "Paintball!",
                        sf::Style::Close | sf::Style::Resize);
window.setFramerateLimit(60);
sf::Vector2u windowSize = window.getSize();


//Create field
sf::RectangleShape field(sf::Vector2f(400.0f, 720.0f));
sf::Texture fieldTexture;
fieldTexture.loadFromFile("green-grass-texture-background.png");
field.setTexture(&fieldTexture);


//Create players vector and teams vector
std::cout << "How many players to make? ";
int noOfPlayers = 0;
std::cin >> noOfPlayers;
Game game(2, noOfPlayers);
//game.positionTeams(windowSize);

std::cout << "Teams: " << game.getTeams().size();
std::cout << "Team 1 size: " << game.getTeam(0).size() << std::endl;
std::cout << "Team 2 size: " << game.getTeam(1).size() << std::endl;



//Create mouse position variable and set position of reticule shape
sf::CircleShape reticule = createReticule();


//Create paintbll projectile
std::vector<Ball> balls;
sf::Vector2f targetVector;


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

            //window resize event
            case sf::Event::Resized:
                printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);
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
    if(wButton) game.getPlayers().at(0)->movePlayer('w', dt);//up
    if(aButton) game.getPlayers().at(0)->movePlayer('a', dt);//left
    if(dButton) game.getPlayers().at(0)->movePlayer('d', dt);//right
    if(sButton) game.getPlayers().at(0)->movePlayer('s', dt); //down


    //Set reticule position
    sf::Vector2f mousePosition = calculateReticulePosition(window);
    reticule.setPosition(mousePosition);


    //shoot
    if(mouseLPressed)
    {
        mouseLPressed=false;
        targetVector = reticule.getPosition() - game.getTeamPlayer(0, 0).getPosition();
        Ball paintball(targetVector);
        paintball.setPosition(game.getTeamPlayer(0, 0).getPosition());
        balls.push_back(paintball);
    }
    for (unsigned int i = 0; i < balls.size(); i++)
        {
            balls.at(i).shootBall(dt);
        }



    //Rendering
    window.clear();
    window.draw(field);
    window.draw(reticule);
    /*for (unsigned int t = 0; t < game.getTeams().size(); t++)
    {
        for (unsigned int p = 0; p < game.getTeamsAt(0).getTeamSize(); p++)
        {
            window.draw(game.getTeamsAt(t).getPlayerAt(p).getPlayer());
        }
    }*/

    game.getPlayers().at(0)->setPosition(200.0f, 360.0f);
    
    for (int i = 0; i < game.getPlayers().size(); i++)
    {
        window.draw(game.getPlayers().at(i)->getPlayer());
    }
    
    for (unsigned int i = 0; i < balls.size(); i++) {window.draw(balls.at(i).getBall());}
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