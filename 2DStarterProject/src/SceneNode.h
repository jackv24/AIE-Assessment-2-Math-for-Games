#pragma once

#include <vector>
#include "Matrix3.h"

class SceneNode
{
public:
	SceneNode();
	~SceneNode();

	void SetParent(SceneNode* node);
	void AddChild(SceneNode* node);
	void RemoveChild(SceneNode* node);

	void UpdateTransforms();
protected:
	//list of children
	std::vector<SceneNode*> m_children;

	SceneNode* m_parent;

	//transform relative to parent
	Matrix3 m_local_transform;
	//transform relative to world origin, recalculated every frame
	Matrix3 m_global_transform;
};