/// <summary>
/// @author Dion Buckley
/// 
/// NOTES:
///		GLU is important for openGL
///		Model view
///		draw method using older method (immidiate mode)
///		Notice weird ass rotations
/// 
///		https://onedrive.live.com/view.aspx?resid=5E66DFE2F20FD7ED!337480&ithint=file%2cdocx&app=Word&authkey=!AEueKYV5GYuUEw8
///		https://en.wikibooks.org/wiki/OpenGL_Programming/GLStart/Tut3
///		https://www.khronos.org/opengl/wiki/Primitive
///		[PRIMITIVE]_STRIP is for effeciency, this way we re-use vertices between shapes (think complex 3D models with MANY triangles)
/// </summary>
/// 
#include <Game.h>

int main(void)
{
	Game& game = Game();
	game.run();
}