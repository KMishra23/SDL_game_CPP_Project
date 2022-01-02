#include "GameObject.h"
#include "TextureManager.h"
#include "PlayerAnimationHandler.h"

GameObject::GameObject(const char* textureSheet, int x, int y, int scale)
{
	objectTexture = TextureManager::LoadTexture(textureSheet);
	if (objectTexture == NULL)
	{
		cout << "Player texture not loaded" << endl;
	}
	xpos = x;
	ypos = y;
	this->objectSizeScale = scale;
}

void GameObject::Update()
{

	srcRect.h = 26;
	srcRect.w = 16;
	srcRect.x = 1;
	srcRect.y = 1;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

int GameObject::xPosQuery()
{
	return xpos;
}

int GameObject::yPosQuery()
{
	return ypos;
}