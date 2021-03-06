#pragma once

#include "pch.h"
#include "Cube.h"
#include "CubeCommandList.h"

struct CubePlayerSpeeds
{
    CubePlayerSpeeds()
    {
        solvingSpeed = 0.3f;
        foldingSpeed = 5.0f;
    }

    float solvingSpeed = 0.3f;
    float foldingSpeed = 0.3f;
};

struct CubePlayerDesc
{
    CubePlayerDesc()
    {
		populateColors = true;
        unfoldCubeAtStart = false;
    }

	bool populateColors;
    bool unfoldCubeAtStart;
    CubePlayerSpeeds speeds;
};

class CubePlayer
{
public:
    CubePlayer(CubePlayerDesc* settings);
    ~CubePlayer();

	void Update(float timeTotal, float timeDelta);
	void UseCommandList(CubeCommandList *pCommandList);

	void Play();
	void Pause();

    Cube* GetCube() { return mCube; };

    CubePlayerDesc GetDesc() { return mDesc; };
    void UpdateSolvingSpeed(float newSpeed) { mDesc.speeds.solvingSpeed = newSpeed; };

private:

    enum PlaybackState
    {
        PLAYBACK_STATE_FOLDING = 1,
        PLAYBACK_STATE_SOLVING = 2,
		PLAYBACK_STATE_POPULATING_COLORS = 3
    };

	void Reset();

    Cube* mCube;
	CubeCommandList* mCubeCommandList;

    PlaybackState mPlaybackState;

    // Folding state members
    float mFoldingAngle;

    // Solving state members
	unsigned int uiCurrentCommandPos;
	float fCurrentCommandProportion;
	bool bPaused;

    CubePlayerDesc mDesc;
};
