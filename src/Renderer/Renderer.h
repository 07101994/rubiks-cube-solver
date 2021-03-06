#pragma once

#include "Cube\Cube.h"
#include "Cube\Sticker.h"
#include "AgnosticApp.h"

class Renderer
{
public:
    virtual void DrawCube(Cube* pCube, glm::mat4 *pViewMatrix, glm::mat4 *pProjectionMatrix) { pCube->Draw(this, pViewMatrix, pProjectionMatrix); };

    virtual void RenderSticker(Sticker* pSticker, glm::mat4 *pWorldMatrix, glm::mat4 *pViewMatrix, glm::mat4 *pProjectionMatrix) = 0;

    virtual void Swap() = 0;

	virtual void MakeCurrent() = 0;

    virtual void Clear() = 0;

    virtual void UpdateForWindowSizeChange() = 0;
};
