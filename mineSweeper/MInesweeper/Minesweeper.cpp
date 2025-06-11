// Anees Hamid | Qatada
// Project: Minesweeper
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
using namespace sf;

int main() {
    srand(time(0));

    //---------------------------Game Window / Variables---------------------------------

    RenderWindow app(VideoMode(725, 480), "Minesweeper!", Style::Close);

    // empty tile pressed = 0, bomb = 9, hidden tile = 10, flag = 11 
again1:
    int w = 32;
    int grid[12][12];
    int showngrid[12][12];
    int bomb = 0;
    bool win = true;
    bool a = false;

    //---------------------------Texture/Sprites-----------------------------------------

    Clock clock;
    Texture t;
    t.loadFromFile("Sprites/Tiles.jpg");
    t.setSmooth(true);
    Sprite s(t);

    Texture face;
    face.loadFromFile("Sprites/faces.jpg");
    face.setSmooth(true);
    Sprite smiley;
    smiley.setTexture(face);
    smiley.setTextureRect(IntRect(0, 0, 512, 523));
    smiley.setScale(Vector2f(0.20f, 0.20f));
    smiley.setPosition(14.75 * w, 1 * w);

    Texture title;
    title.loadFromFile("Sprites/minesweeper.jpg");
    Sprite minesweeper;
    minesweeper.setTexture(title);
    minesweeper.setScale(Vector2f(0.53f, 0.53f));
    minesweeper.setPosition(0.35 * w, 12 * w);

    Font f;
    f.loadFromFile("Fonts/Maranello.ttf");

    Font d;
    d.loadFromFile("Fonts/Digital.ttf");

    Font c;
    c.loadFromFile("Fonts/copyright.otf");

    Font m;
    m.loadFromFile("Fonts/mine-sweeper.ttf");

    Text text;
    text.setFont(f);
    text.setCharacterSize(28);
    text.setPosition(2.8 * w, 0.000001 * w);
    text.setFillColor(Color::Red);
    text.setStyle(Text::Bold);

    Text text2;
    text2.setFont(m);
    text2.setCharacterSize(25);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);

    Text number;
    number.setFont(m);
    number.setCharacterSize(22);
    number.setFillColor(Color::Red);
    number.setStyle(Text::Bold);

    Text time;
    time.setFont(m);
    time.setCharacterSize(22);
    time.setFillColor(Color::Blue);
    time.setStyle(Text::Bold);

    Text copyright;
    copyright.setFont(m);
    copyright.setCharacterSize(10);
    copyright.setFillColor(Color::Black);
    copyright.setStyle(Text::Bold);
    //copyright.setRotation(270.0f);

    Text escape;
    escape.setFont(d);
    escape.setFillColor(Color::Black);
    escape.setCharacterSize(30);
    escape.setString("Press esc to exit");
    escape.setPosition(13 * w, 10 * w);

    //---------------------------Game Grid-----------------------------------------------

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            showngrid[i][j] = 10;
            if (rand() % 10 == 0 && bomb < 10) {
                grid[i][j] = 9; // bomb generated
                bomb++;
            }
            else
                grid[i][j] = 0; // unknown element generated
        }
    int flag = bomb;
    int count = 0;
    //-------------------Calculating number of mines around each cell-------------------------

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++)
        {
            int n = 0; //it represents the number of bomb around each centre cell
            if (grid[i][j] == 9)
                continue; //ignore if bomb
            //for all 8 tiles around the centre tile
            if (grid[i + 1][j] == 9)
                n++;
            if (grid[i][j + 1] == 9)
                n++;
            if (grid[i - 1][j] == 9)
                n++;
            if (grid[i][j - 1] == 9)
                n++;
            if (grid[i + 1][j + 1] == 9)
                n++;
            if (grid[i - 1][j - 1] == 9)
                n++;
            if (grid[i - 1][j + 1] == 9)
                n++;
            if (grid[i + 1][j - 1] == 9)
                n++;
            grid[i][j] = n;
        }
    }

    //    // Bomb position check
    //for (int i = 1; i <= 10; i++) {
    //    for (int j = 1; j <= 10; j++)
    //    {
    //        if (grid[i][j] == 9)
    //            showngrid[i][j] = grid[i][j];
    //    }
    //}

    //-------------------------User Input/Flagging/Loop until exiting------------------------

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Escape)
                    app.close();

            if (e.type == Event::MouseButtonPressed) {
                Vector2i pos = Mouse::getPosition(app);
                int x = pos.x / w;
                int y = pos.y / w;
                if (e.key.code == Mouse::Left) {
                    if (count != bomb) {
                        if (showngrid[x][y] != 11) { // for non flagged tiles
                            if (showngrid[x][y] != 0) { // for non empty pressed tile
                                showngrid[x][y] = grid[x][y];
                                for (int i = 1; i <= 10; i++) {
                                    for (int j = 1; j <= 10; j++)
                                        if (showngrid[x][y] == 9) //if bomb all hidden tiles get the value of grid[x][y] therefore showing every tile
                                            showngrid[i][j] = grid[i][j];
                                }
                                count = 0; //count shows the number of flagged or hidden tiles. This variable allows to finish game evem if not every flagged is used just like in minesweeper.
                                for (int i = 1; i <= 10; i++) {
                                    for (int j = 1; j <= 10; j++) {
                                        if (showngrid[i][j] == 10 || showngrid[i][j] == 11) { //if flagged  or hidden
                                            count++;
                                        }
                                    }
                                    if (count > bomb)
                                        break;
                                }
                                if (count == bomb) { //count==bomb means that number of hidden tiles and flags are equal to number of mines resulting in a win
                                    win = true;
                                    goto aggain;
                                }
                                if (showngrid[x][y] == 0) {
                                    // Clicked on an empty tile, reveal adjacent empty tiles
                                    if (showngrid[x - 1][y] != 11)
                                        showngrid[x - 1][y] = grid[x - 1][y];
                                    if (showngrid[x - 1][y + 1] != 11)
                                        showngrid[x - 1][y + 1] = grid[x - 1][y + 1];
                                    if (showngrid[x - 1][y - 1] != 11)
                                        showngrid[x - 1][y - 1] = grid[x - 1][y - 1];
                                    if (showngrid[x][y + 1] != 11)
                                        showngrid[x][y + 1] = grid[x][y + 1];
                                    if (showngrid[x][y - 1] != 11)
                                        showngrid[x][y - 1] = grid[x][y - 1];
                                    if (showngrid[x + 1][y] != 11)
                                        showngrid[x + 1][y] = grid[x + 1][y];
                                    if (showngrid[x + 1][y + 1] != 11)
                                        showngrid[x + 1][y + 1] = grid[x + 1][y + 1];
                                    if (showngrid[x + 1][y - 1] != 11)
                                        showngrid[x + 1][y - 1] = grid[x + 1][y - 1];
                                }
                                else {
                                    showngrid[x][y] = grid[x][y];
                                    if (showngrid[x][y] == 9) { //if any non mine tile is pressed tiles integer decreases
                                        win = false;
                                    }
                                }
                            }
                        }
                    }
                }
                // FLAGS
                else if (e.key.code == Mouse::Right) {
                    if (showngrid[x][y] == 11) { //unflagging
                        showngrid[x][y] = 10;
                        flag++;
                    }
                    else if (showngrid[x][y] == 10) { //flagging
                        showngrid[x][y] = 11;
                        flag--;
                    }

                }
            }
            number.setString(to_string(flag));
        }
    aggain:
        Vector2i mousePosition = Mouse::getPosition(app);
        if (smiley.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            if (e.type == Event::MouseButtonPressed) //retry button
                if (e.key.code == (Mouse::Left))
                {
                    goto again1;
                }
        }
        if (win && count != bomb) { //time runs until game is finished won/loss
            Time elapsed = clock.getElapsedTime();
            ostringstream stream;
            stream << "Time: " << elapsed.asSeconds() << " s";
            time.setString(stream.str());
        }

        //----------------------------Styling Game Grid----------------------------------------

        app.clear(Color::White);

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                s.setTextureRect(IntRect(showngrid[i][j] * w, 0, w, w));
                s.setPosition(i * w, j * w);
                app.draw(s);

            }
        }
        if (count == bomb) {
            text.setFillColor(Color::Green);
            text.setString("YOU WON!");
            app.draw(text);
            app.draw(escape);
            smiley.setTextureRect(IntRect(1024, 0, 512, 523));
            smiley.setScale(Vector2f(0.20f, 0.20f));
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++) {
                    showngrid[i][j] = grid[i][j];
                }
        }

        if (!win) {
            text.setString("YOU LOST!");
            app.draw(text);
            app.draw(escape);
            smiley.setTextureRect(IntRect(512, 0, 512, 523));
            smiley.setScale(Vector2f(0.20f, 0.20f));
            app.draw(smiley);
        }

        text2.setString("Mines:");
        text2.setPosition(13 * w, 6 * w);
        app.draw(text2);

        number.setPosition(18 * w, 6 * w);
        app.draw(number);

        time.setPosition(12.3 * w, 8 * w);
        app.draw(time);

        app.draw(smiley);

        app.draw(minesweeper);

        copyright.setString("By Anees & Qatada");
        copyright.setPosition(8 * w, 14.3 * w);
        app.draw(copyright);

        //--------------------------------Displaying Window-------------------------------------

        app.display();
    }

    return 0;
}