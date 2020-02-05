#pragma once
class Vector2Int
{
public:
	int x = 0, y = 0;

	Vector2Int(int xPosition = 0, int yPosition = 0);

	/// <summary>Exists only to prove the class exists.
	/// </summary>
	void awake() {}

	void set(int xPosition = 0, int yPosition = 0);
};