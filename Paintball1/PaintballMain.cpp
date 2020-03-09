#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Ball.h"

sf::RectangleShape createField();
sf::CircleShape createReticule();
sf::Vector2f calculateReticulePosition(sf::RenderWindow &wndw);
void positionTeams(std::vector<std::vector<Player*>> &teams, sf::Vector2u &windowSize);



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
std::vector<Player> players;
std::vector<std::vector<Player*>> teams;
Player *mainPlayer;
std::cout << "How many players to make? ";
int noOfPlayers = 0;
int noOfTeams = 2;
std::cin >> noOfPlayers;
for (int i = 0; i < noOfPlayers; i++)
{
    Player player;
    players.push_back(player);
    players.at(i).setPlayerPosition(15.0f * i, 50.0f);
}
mainPlayer = &players.at(0);
mainPlayer->setPlayerPosition(200.0f, 700.0f);

int pcount = 0;
for (int t = 0; t < noOfTeams; t++)
{
    std::vector<Player*> temp;
    for (unsigned int i = 0; i < players.size() / noOfTeams; i++)
    {
        temp.push_back(&players.at(pcount));
        pcount++;
    }
    teams.push_back(temp);
}
std::cout << "Players: " << players.size() << ". Teams: " << teams.size();
positionTeams(teams, windowSize);


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
bool play = true;
while (play)
{
    //Events
    while(window.pollEvent(evnt))
    {
        switch(evnt.type)
        {
            //window closed event
            case sf::Event::Closed:
                play = false;
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
    if(wButton) mainPlayer->movePlayer('w', dt);//up
    if(aButton) mainPlayer->movePlayer('a', dt);//left
    if(dButton) mainPlayer->movePlayer('d', dt);//right
    if(sButton) mainPlayer->movePlayer('s', dt); //down
    if(sButton) teams.at(1).at(1)->movePlayer('s', dt);


    //Set reticule position
    sf::Vector2f mousePosition = calculateReticulePosition(window);
    reticule.setPosition(mousePosition);


    //shoot
    if(mouseLPressed)
    {
        mouseLPressed=false;
        targetVector = reticule.getPosition() - mainPlayer->getPosition();
        Ball paintball(targetVector);
        paintball.setPosition(mainPlayer->getPosition());
        balls.push_back(paintball);
    }
    for (unsigned int i = 0; i < balls.size(); i++)
        {
            balls.at(i).shootBall(dt);
        }



    //Rendering
    window.clear();
    window.draw(field);

    for (unsigned int i = 0; i < teams.size(); i++)
    {
        for (unsigned int t = 0; t < teams.at(i).size(); t++)
        {
            window.draw(teams.at(i).at(t)->getPlayer());
        }
    }
    window.draw(reticule);
    for (unsigned int i = 0; i < balls.size(); i++) {window.draw(balls.at(i).getBall());}
    window.display();


    //Restart the clock and set dt to the time since the clock was last restarted
    dt = clock.restart().asSeconds();
}

window.close();

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



//Finish this
void positionTeams(std::vector<std::vector<Player*>> &teams, sf::Vector2u &windowSize)
{
    float teamWidth = (teams.at(0).size() * (teams.at(0).at(0)->getRadius() * 2));
    float spacing;
    float offset;
    for (int t = 0; t < teams.size(); t++)
    {
        spacing = (teams.at(t).at(0)->getRadius() * 2.0f) + 5.0f;
        offset = 0.0f;
        if (t % 2 == 0)
        {
            for (int p = 0; p < teams.at(t).size(); p++)
            {
                teams.at(t).at(p)->setPlayerPosition(
                    ((windowSize.x / 2) - teamWidth / 2.0f) + offset, 700.0f );
                                    std::cout << " " << teams.at(t).at(p)->getRadius();
                offset += spacing;
            }
        }
        else
        {
            for (int p = 0; p < teams.at(t).size(); p++)
            {
                teams.at(t).at(p)->setPlayerPosition(
                    ((windowSize.x / 2) - teamWidth / 2.0f) + offset, 20.0f);
                std::cout << " " << teams.at(t).at(p)->getRadius();
                offset += spacing;
            }
        }
    }
}
