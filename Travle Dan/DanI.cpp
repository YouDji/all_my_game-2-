#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
 #include <iostream>
 #include<math.h>
 #include <vector>
using namespace sf; 
using namespace std;
int offsetX=0, offsetY=0, maxhp,maxhpsize;
sf::Window app;
//персонаж
sf::Image avatar;sf::Texture texture;sf::Sprite sprite;
sf::Image avatartwo;sf::Texture texturetwo;sf::Sprite spritetwo;
sf::Image imagehp;
sf::RectangleShape bar;
//________-_---_-_

//червоні башні для нерушимості
sf::CircleShape square;
sf::CircleShape mainsquare;
sf::CircleShape squaretwo;
sf::CircleShape squareblue;
sf::CircleShape mainsquareblue;
sf::CircleShape squarebluetwo;
//___-__-___-__
float dx,dy;
float speed= 6;
float CurrentFrame=0;
class Bullettwo
{
	public:
CircleShape shapetwo;
Vector2f  currVelocitytwo;
float maxSpeedtwo;
Bullettwo(float radius =5.f)
:currVelocitytwo(0.f,0.f), maxSpeedtwo(-10.f)
{
	this->shapetwo.setRadius(radius);
this->shapetwo.setFillColor(Color::Blue);	
	}
};


class Bullet
{
public:
CircleShape shape;
Vector2f  currVelocity;
float maxSpeed;
Bullet(float radius =5.f)
:currVelocity(0.f,0.f), maxSpeed(10.f)
{
	this->shape.setRadius(radius);
this->shape.setFillColor(Color::Red);	
	}
};

int main()
{	
srand(time(0));
//розмірекрану та фпс
RenderWindow app(VideoMode(525,840), "NYXT ROALE");
app.setFramerateLimit(60);
//_________________

//червоні башні
CircleShape square(35.f, 130);
square.setPosition(45, 140); 
square.setFillColor(Color::Red); 
app.draw(square);


CircleShape mainsquare(45.f, 130);
mainsquare.setPosition(234, 120); 
mainsquare.setFillColor(Color::Green); 
app.draw(mainsquare);


CircleShape squaretwo(30.f, 130);
squaretwo.setPosition(430, 150); 
squaretwo.setFillColor(Color::White); 
app.draw(squaretwo);

CircleShape squareblue(37.f, 130);
squareblue.setPosition(42, 625); 
squareblue.setFillColor(Color::Yellow); 
app.draw(squareblue);

CircleShape squarebluetwo(37.f, 130);
squarebluetwo.setPosition(426, 625); 
squarebluetwo.setFillColor(Color::White); 
app.draw(squarebluetwo);
//ШКАЛА ХП  
//____-_-_-_-__-
//для аватару
Texture t1,t2,t3,t4,t5,t6,t7,t8,t9 ;
avatar.loadFromFile("images/avatar.png");
texture.loadFromImage(avatar);
sprite.setTexture(texture);
sprite.setPosition(245,20);

avatartwo.loadFromFile("images/avatartwo.png");
texturetwo.loadFromImage(avatartwo);
spritetwo.setTexture(texturetwo);
spritetwo.setPosition(245,500);
//____________
//пнж картинки
t2.loadFromFile("images/Roal Tower.png");	 
t3.loadFromFile("images/Princess Tower right.png");
t4.loadFromFile("images/Princess Tower left.png");
t5.loadFromFile("images/Arena.jpg");
t6.loadFromFile("images/Princess Towerblue right.png");
t7.loadFromFile("images/Princess Towerblue left.png");
Sprite hpr;
imagehp.loadFromFile("images/Xitpoint.png");
t8.loadFromImage(imagehp);

hpr.setTexture(t8);
hpr.setTextureRect(IntRect(0,0,150,20));
bar.setFillColor(Color(0,0,0));

t9.loadFromFile("images/Xitpointblue.png");

//_________________
Sprite sTwo(t2),sThree(t3),sFour(t4),sFive(t5),sSix(t6),sSeven(t7),sEight(t8),sNine(t9);
//розтавляемо картинки
sTwo.setPosition(230,100);
sFour.setPosition(45,130);
sThree.setPosition(430,130);
sSix.setPosition(340,500);
sSeven.setPosition(-45,500);
sEight.setPosition(15,13);
sNine.setPosition(20,800);
//_________-__-___-
float dx=6, dy=5;
float x=100, y=100;
int HeroDirection;
int HeroDirectiontwo;



Bullet b1;
std::vector<Bullet>bullets;

Bullettwo b2;
std::vector<Bullettwo>bulletstwo;
Vector2f playerCenter;
Vector2f mousePosApp;
Vector2f aimDir;
Vector2f aimDirNorm;


Vector2f playerCentertwo;
Vector2f mousePosApptwo;
Vector2f aimDirtwo;
Vector2f aimDirNormtwo;
while (app.isOpen())
{
sf::Event e;
while (app.pollEvent(e))
{
if (e.type == Event::Closed)
app.close();
}

playerCenter= Vector2f(sprite.getPosition().x,sprite.getPosition().y);
mousePosApp=Vector2f(Mouse::getPosition(app));
aimDir=mousePosApp - playerCenter;
aimDirNorm= aimDir / aimDir.x;
aimDirNorm= aimDir/ aimDir.y;

playerCentertwo= Vector2f(spritetwo.getPosition().x,spritetwo.getPosition().y);
//mousePosApptwo=Vector2f(getPosition(app));
aimDirtwo=mousePosApptwo - playerCentertwo;
aimDirNormtwo= aimDirtwo / aimDirtwo.x;
aimDirNormtwo= aimDirtwo/ aimDirtwo.y;
//передвижение
if (Keyboard::isKeyPressed(Keyboard::D))
{
    HeroDirection=0;
	sprite.move(speed,0);
}
if (Keyboard::isKeyPressed(Keyboard::A)) 
{	
HeroDirection=1;
sprite.move(-speed,0);
}
if (Keyboard::isKeyPressed(Keyboard::W)) 
{
	HeroDirection=2;
	sprite.move(0,speed);
}
if (Keyboard::isKeyPressed(Keyboard::S)) 
{
	HeroDirection=3;
	sprite.move(0,-speed);
}
//_________________________________


//движение аватара с синей стороны
if (Keyboard::isKeyPressed(Keyboard::Right))
{
    HeroDirectiontwo=0;
	spritetwo.move(speed,0);
}
if (Keyboard::isKeyPressed(Keyboard::Left)) 
{	
HeroDirectiontwo=1;
spritetwo.move(-speed,0);
}
if (Keyboard::isKeyPressed(Keyboard::Up)) 
{
	HeroDirectiontwo=2;
	spritetwo.move(0,speed);
}
if (Keyboard::isKeyPressed(Keyboard::Down)) 
{
	HeroDirectiontwo=3;
	spritetwo.move(0,-speed);
}



//стрельба 
if(Mouse::isButtonPressed(Mouse::Left))
{
	b1.shape.setPosition(playerCenter);
	b1.currVelocity=aimDirNorm*b1.maxSpeed;
	
	
	bullets.push_back(Bullet(b1));
	
}
for(size_t i = 0; i<bullets.size(); i++)
{
	bullets[i].shape.move(bullets[i].currVelocity);
	if(bullets[i].shape.getPosition().x<0|| bullets[i].shape.getPosition().x>app.getSize().x
	||bullets[i].shape.getPosition().y<0 || bullets[i].shape.getPosition().y>app.getSize().y)
	{
		bullets.erase(bullets.begin()+i);
	}
	
}



if(Keyboard::isKeyPressed(Keyboard::P))
{
	b2.shapetwo.setPosition(playerCentertwo);
	b2.currVelocitytwo=aimDirNormtwo*b2.maxSpeedtwo;
	
	
	bulletstwo.push_back(Bullettwo(b2));
	
}
for(size_t j = 0; j<bulletstwo.size(); j++)
{
	bulletstwo[j].shapetwo.move(bulletstwo[j].currVelocitytwo);
	if(bulletstwo[j].shapetwo.getPosition().x<0|| bulletstwo[j].shapetwo.getPosition().x>app.getSize().x
	||bulletstwo[j].shapetwo.getPosition().y<0 || bulletstwo[j].shapetwo.getPosition().y>app.getSize().y)
	{
		bulletstwo.erase(bulletstwo.begin()+j);
	}
}


//__________________________________

//для заднего фона
if(x>320) offsetX =x-320;
if(y>240) offsetY =y-240;
//_____________--__

//для нерушимості башен от красного игрока
sf::FloatRect spriteBounds = sprite.getGlobalBounds();
sf::FloatRect spritetwoBounds = spritetwo.getGlobalBounds();
sf::FloatRect  squareBounds = square.getGlobalBounds();
sf::FloatRect  mainsquareBounds = mainsquare.getGlobalBounds();
sf::FloatRect  squaretwoBounds = squaretwo.getGlobalBounds();
sf::FloatRect  squareblueBounds = squareblue.getGlobalBounds();
sf::FloatRect  squarebluetwoBounds = squarebluetwo.getGlobalBounds();

if(spriteBounds.intersects(squareBounds))
{
	if(HeroDirection==0)
	{
		sprite.move(-speed,0);
	}
	if(HeroDirection==1)
	{
		sprite.move(speed,0);
	}
	if(HeroDirection==2)
	{
	sprite.move(0,-speed);
	}
	if(HeroDirection==3)
	{
	sprite.move(0,speed);
	}

}
if(spriteBounds.intersects(mainsquareBounds))
{
if(HeroDirection==0)
	{
		sprite.move(-speed,0);
	}
		if(HeroDirection==1)
	{
		sprite.move(speed,0);
	}
	if(HeroDirection==2)
	{
	sprite.move(0,-speed);
	}
	if(HeroDirection==3)
	{
	sprite.move(0,speed);
	}
}
if(spriteBounds.intersects(squaretwoBounds))
{
if(HeroDirection==0)
	{
		sprite.move(-speed,0);
	}
		if(HeroDirection==1)
	{
		sprite.move(speed,0);
	}
	if(HeroDirection==2)
	{
	sprite.move(0,-speed);
	}
	if(HeroDirection==3)
	{
	sprite.move(0,speed);
	}
}
if(spriteBounds.intersects(squareblueBounds))
{
	if(HeroDirection==0)
	{
		sprite.move(-speed,0);
	}
		if(HeroDirection==1)
	{
		sprite.move(speed,0);
	}
	if(HeroDirection==2)
	{
	sprite.move(0,-speed);
	}
	if(HeroDirection==3)
	{
	sprite.move(0,speed);
	}
}
if(spriteBounds.intersects(squarebluetwoBounds))
{
	if(HeroDirection==0)
	{
		sprite.move(-speed,0);
	}
		if(HeroDirection==1)
	{
		sprite.move(speed,0);
	}
	if(HeroDirection==2)
	{
	sprite.move(0,-speed);
	}
	if(HeroDirection==3)
	{
	sprite.move(0,speed);
	}
}
//_____-_-_

if(spritetwoBounds.intersects(squareBounds))
{
	if(HeroDirectiontwo==0)
	{
		spritetwo.move(-speed,0);
	}
	if(HeroDirectiontwo==1)
	{
		spritetwo.move(speed,0);
	}
	if(HeroDirectiontwo==2)
	{
	spritetwo.move(0,-speed);
	}
	if(HeroDirectiontwo==3)
	{
	spritetwo.move(0,speed);
	}
	
}
if(spritetwoBounds.intersects(mainsquareBounds))
{
if(HeroDirectiontwo==0)
	{
		spritetwo.move(-speed,0);
	}
		if(HeroDirectiontwo==1)
	{
		spritetwo.move(speed,0);
	}
	if(HeroDirectiontwo==2)
	{
	spritetwo.move(0,-speed);
	}
	if(HeroDirectiontwo==3)
	{
	spritetwo.move(0,speed);
	}
}
if(spritetwoBounds.intersects(squaretwoBounds))
{
if(HeroDirectiontwo==0)
	{
		spritetwo.move(-speed,0);
	}
		if(HeroDirectiontwo==1)
	{
		spritetwo.move(speed,0);
	}
	if(HeroDirectiontwo==2)
	{
	spritetwo.move(0,-speed);
	}
	if(HeroDirectiontwo==3)
	{
	spritetwo.move(0,speed);
	}
}
if(spritetwoBounds.intersects(squareblueBounds))
{
	if(HeroDirectiontwo==0)
	{
		spritetwo.move(-speed,0);
	}
		if(HeroDirectiontwo==1)
	{
		spritetwo.move(speed,0);
	}
	if(HeroDirectiontwo==2)
	{
	spritetwo.move(0,-speed);
	}
	if(HeroDirectiontwo==3)
	{
	spritetwo.move(0,speed);
	}
}
if(spritetwoBounds.intersects(squarebluetwoBounds))
{
	if(HeroDirectiontwo==0)
	{
		spritetwo.move(-speed,0);
	}
		if(HeroDirectiontwo==1)
	{
		spritetwo.move(speed,0);
	}
	if(HeroDirectiontwo==2)
	{
	spritetwo.move(0,-speed);
	}
	if(HeroDirectiontwo==3)
	{
	spritetwo.move(0,speed);
	}
}
app.clear(Color::White);
sFive.setPosition(-offsetX,-offsetY);
app.draw(sFive);
app.draw(sTwo);
for(size_t i = 0; i<bullets.size(); i++)
{
	app.draw(bullets[i].shape);
}
for(size_t j = 0; j<bulletstwo.size(); j++)
{
	app.draw(bulletstwo[j].shapetwo);
}
app.draw(sThree);
app.draw(sFour);
app.draw(sprite);
app.draw(spritetwo);
app.draw(sSix);
app.draw(sSeven);
app.draw(sEight);
app.draw(sNine);
maxhp=100;
int k;

if(k>0)
if(k<maxhpsize)	
//уменьшение хп
bar.setSize(Vector2f(10,(maxhp-k)*70/maxhp));
//04.06.2022
	if(	 aimDirNorm==playerCentertwo)
	{
		//bar.setSize=maxhp-20;
	}

//Vector2f centerhp =app.getView().getCenter();
//Vector2f sizehp= app.getView().getSize();
//hpr.setPosition(centerhp.x-sizehp.x / 2+10, centerhp.y -sizehp.y/2+10);
//hpr.setPosition(centerhp.x-sizehp.x / 2+14, centerhp.y -sizehp.y/2+14);

//app.draw(hpr);
app.draw(bar);
app.display();
}
return 0;
} 


