#pragma once

#include "SceneNode.h"
#include "Texture.h"
#include "SpriteBatch.h"

class Crate : public SceneNode
{
public:
	Crate();
	~Crate();

	void Draw(SpriteBatch* spriteBatch);

private:
	Texture* m_sprite;
};

