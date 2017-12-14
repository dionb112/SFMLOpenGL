#include <Game.h>

/// <summary>
/// Part 2
/// </summary>
Game::Game() 
	: window(VideoMode(800, 600), "OpenGL")
	, m_primitives(2)
	, m_rotationAngle(1)
{
	 m_index = glGenLists(m_primitives);
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
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);

	// Loading identity matrix
	// 1 0 0
	// 0 1 0
	// 0 0 1 
	glLoadIdentity();

	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(m_index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(m_index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	sf::Clock clock;
	sf::Time elapsed;
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!m_flip)
		{
			m_flip = true;
			m_current++;
			if (m_current > m_primitives)
			{
				m_current = 1;
			}
		}
		else
			m_flip = false;
	}

	if (m_flip)
	{
		m_rotationAngle += 0.005f;

		if (m_rotationAngle > 360.0f)
		{
			m_rotationAngle -= 360.0f;
		}
	}

	cout << "Update up" << endl;
}

void Game::draw()
{

	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Rotate primitve around Z axis (rotate facing us)
	glRotatef(m_rotationAngle, 0, 0.0f, 1.0f);

	// Translate shape along x axis (move shape right)
	glTranslatef(0.01, 0.0f, 0.0f);

	// Grow that thing !  ( Just on x and y, if scale on Z with this perspective ; things get weird)
	glScalef(1.001, 1.001f, 1.0f);

	cout << "Drawing Primative " << m_current << endl;
	glCallList(m_current);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::processEvents()
{
}

