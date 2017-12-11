#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	// White flush
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

	// Setting to projection mode
	glMatrixMode(GL_PROJECTION); 

	/* Loading identity matrix
	1 0 0
	0 1 0
	0 0 1 */
	glLoadIdentity();

	// Setting up 2D perspective for SFML window
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);

	// Setting to model view for drawing the primitives
	glMatrixMode(GL_MODELVIEW);

	// Default state of enum class instance - change for debug
	m_currentPrimitive = Primitive::TRIANGLE_FAN;

	// Bool for tracking game over state
	isRunning = true;
}

void Game::update()
{
	cout << "Update up" << endl;
}

/// <summary>
/// Immidiate mode render function
/// </summary>
void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Blue colour for shapes
	glColor3f(0.0f, 0.0f, 1.0f);

	switch (m_currentPrimitive)
	{
	case Primitive::POINTS:
		glPointSize(10.0f);
		glBegin(GL_POINTS); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		break;
	case Primitive::LINES:
		glBegin(GL_LINES); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(0.0, -2.0, -5.0);
		}
		break;
	case Primitive::LINE_STRIP:
		glBegin(GL_LINE_STRIP); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(0.0, -2.0, -5.0);
			glVertex3f(2, 0, -5.0);
			glVertex3f(-2, -0, -5.0);
			glVertex3f(0.0, 2.0, -5.0);
		}
		break;
	case Primitive::LINE_LOOP:
		glBegin(GL_LINE_LOOP); {
			glVertex3f(-1.0f, 0.0f, -5.0);
			glVertex3f(0.0f, -1.0f, -5.0);
			glVertex3f(1.0f, 0.0f, -5.0);
			glVertex3f(0.0f, 1.0f, -5.0);
		}
		break;
	case Primitive::TRIANGLES:
		glBegin(GL_TRIANGLES); {
			glVertex3f(-2, -2, -5.0);
			glVertex3f(-1, -1, -5.0);
			glVertex3f(-2, -0, -5.0);

			glVertex3f(2, 2, -5.0);
			glVertex3f(1, 1, -5.0);
			glVertex3f(2, 0, -5.0);
		}
		break;
	case Primitive::TRIANGLE_STRIP:
		glBegin(GL_TRIANGLE_STRIP); {
			glVertex3f(-2, -2, -5.0);
			glVertex3f(-1, -1, -5.0);
			glVertex3f(-2, -0, -5.0);

			glVertex3f(2, 2, -5.0);
			glVertex3f(1, 1, -5.0);
			glVertex3f(2, 0, -5.0);
		}
	case Primitive::TRIANGLE_FAN:
		glBegin(GL_TRIANGLE_FAN); {
			glVertex3f(0.0, 1, -5.0);
			glVertex3f(-1, -1, -5.0);
			glVertex3f(1, -1, -5.0);

			glVertex3f(1, 2, -5.0);
			glVertex3f(-2, -2, -5.0);
			glVertex3f(2, -2, -5.0);

			glVertex3f(2, 3, -5.0);
			glVertex3f(-3, -3, -5.0);
			glVertex3f(3, -3, -5.0);
		}
		break;
	}

	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

