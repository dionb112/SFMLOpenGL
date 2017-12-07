#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

enum class Primitive
{
	POINTS,
	LINES,
	LINE_STRIP,
	LINE_LOOP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN,
	QUADS,
	QUAD_STRIP,
	POLYGON
};

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Primitive m_currentPrimitive;
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	

	// // Uncomment for Part 2
	// // ********************
	// const int primatives;

	//GLuint index;
	//Clock clock;
	//Time elapsed;

	//float rotationAngle = 0.0f;
	// // ********************
};