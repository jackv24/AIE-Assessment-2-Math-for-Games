#pragma once

#include "SceneNode.h"

class Scene
{
public:
	void UpdateTransforms();
private:
	SceneNode* m_scene_root;
};