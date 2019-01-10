#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

// initial vertices
float initVertices[] = {
	-1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -5.0f, -1.0f, 1.0f, -5.0f,
	1.0f, 1.0f, -7.0f, -1.0f, -1.0f, -7.0f, -1.0f, 1.0f, -7.0f,
	1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -7.0f, 1.0f, -1.0f, -7.0f,
	1.0f, 1.0f, -7.0f, 1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -7.0f,
	-1.0f, -1.0f, -7.0f, -1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -7.0f,
	1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -7.0f,
	-1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f, 1.0f, -1.0f, -5.0f,
	1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -7.0f, 1.0f, 1.0f, -7.0f,
	1.0f, -1.0f, -7.0f, 1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f,
	1.0f, 1.0f, -5.0f, 1.0f, 1.0f, -7.0f, -1.0f, 1.0f, -7.0f,
	1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -7.0f, -1.0f, 1.0f, -5.0f,
	1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f };

// Vertices for one Triangle
float vertices[] = { 
	-1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -5.0f, -1.0f, 1.0f, -5.0f, 
	1.0f, 1.0f, -7.0f, -1.0f, -1.0f, -7.0f, -1.0f, 1.0f, -7.0f, 
	1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -7.0f, 1.0f, -1.0f, -7.0f,
	1.0f, 1.0f, -7.0f, 1.0f, -1.0f, -7.0f, -1.0f, -1.0f, -7.0f,
	-1.0f, -1.0f, -7.0f, -1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -7.0f,
	1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -7.0f,
	-1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f, 1.0f, -1.0f, -5.0f,
	1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -7.0f, 1.0f, 1.0f, -7.0f,
	1.0f, -1.0f, -7.0f, 1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f,
	1.0f, 1.0f, -5.0f, 1.0f, 1.0f, -7.0f, -1.0f, 1.0f, -7.0f,
	1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -7.0f, -1.0f, 1.0f, -5.0f,
	1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f };

// Colors for those vertices
float colors[] = { 
	1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, };

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 ,20 ,21 ,22 , 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	// increase or decrease scale
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_scale += 0.005f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_scale -= 0.005f;
	}

	// move the cube in each direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_displacementVec.y += 0.005f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_displacementVec.y -= 0.005f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_displacementVec.x -= 0.005f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_displacementVec.x += 0.005f;
	}

	// rotate the cube in x, y and z axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		m_rotationX += 0.005f;

		if (m_rotationX > 360.f)
		{
			m_rotationX -= 360.f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		m_rotationY += 0.005f;

		if (m_rotationY > 360.f)
		{
			m_rotationY -= 360.f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_rotationZ += 0.005f;

		if (m_rotationZ > 360.f)
		{
			m_rotationZ -= 360.f;
		}
	}

	// update the positions of vertices
	for (int i = 0; i < 36; i++)
	{
		MyVector3 tempVec{ initVertices[i * 3], initVertices[i * 3 + 1], initVertices[i * 3 + 2] + 6 };
		tempVec = MyMatrix3::rotationX(m_rotationX) * tempVec;
		tempVec = MyMatrix3::rotationY(m_rotationY) * tempVec;
		tempVec = MyMatrix3::rotationZ(m_rotationZ) * tempVec;
		tempVec = MyMatrix3::scale(m_scale) * tempVec;
		tempVec += m_displacementVec;
		vertices[i * 3] = tempVec.x;
		vertices[i * 3 + 1] = tempVec.y;
		vertices[i * 3 + 2] = tempVec.z - 6;
	}
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{

}

