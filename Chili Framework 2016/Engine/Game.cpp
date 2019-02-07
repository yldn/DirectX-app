/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}
/////////main loop//////
void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {

		}
		else {
			vy -= 1;
			inhibitUp = true;
		}
	}
	else {
		inhibitUp = false;
	}

	 if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		 if (inhibitDown) {

		 }
		 else {
			 vy += 1;
			 inhibitDown = true;
		 }
	}
	 else {
		 inhibitDown = false;
	 }
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {

		}
		else {
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else {
		inhibitLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {

		}
		else {
			vx += 1;
			inhibitRight = true;
		}
	}
	else {
		inhibitRight = false;
	}


	centreX += vx;
	centreY += vy;

	shapeChanged = wnd.kbd.KeyIsPressed(VK_SPACE);


	//clamp
	if (centreX+5 > gfx.ScreenWidth-1) {
		centreX = gfx.ScreenWidth-5-1;
	}
	if (centreX - 5 < 0) {
		centreX = 5;
	}
	if (centreY + 5 >= gfx.ScreenHeight - 1) {
		centreY = gfx.ScreenHeight - 5 - 1;
	}
	if (centreY - 5 < 0) {
		centreY = 5;
	}


}


void Game::ComposeFrame()
{
	drawCrossair();
}
void Game::drawCrossair()
{


	if (shapeChanged) {

		for (int i = -5; i <= 5; i++) {
			if ((i < -2) || (i > 2)) {
				gfx.PutPixel(centreX + i, centreY, 255, 255, 255);
				gfx.PutPixel(centreX, centreY + i, 255, 255, 255);
			}
		}
	}
	//square by default
	else{
		for (int i = -5; i <= 5; i++) {
			for (int j = -5; j <= 5; j++) {
				if (i == -5 || i == 5) {
					if ((j < -2) || (j > 2)) {
						gfx.PutPixel(centreX + i, centreY + j, 255, 255, 255);
					}
				}
				if (j == -5 || j == 5) {
					if ((i < -2) || (i > 2)) {
						gfx.PutPixel(centreX + i, centreY + j, 255, 255, 255);
					}
				}
			}
		}
	}

}
