#include "Crate.h"

Crate::Crate()
{
	m_sprite = new Texture("./bin/textures/crate.png");

	Matrix3 scale = Matrix3::CreateScale(Vector3(1, 1, 1));
	Matrix3 rotation = Matrix3::CreateRotation(0);
	Matrix3 translation = Matrix3::CreateTranslation(Vector3(640, 360, 1));

	m_local_transform = translation * rotation * scale;
}

Crate::~Crate()
{
}

void Crate::Draw(SpriteBatch* spriteBatch)
{
	spriteBatch->drawSpriteTransformed3x3(m_sprite, m_global_transform);
}
