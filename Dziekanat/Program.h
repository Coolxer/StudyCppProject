#pragma once
#include "Window.h"
#include "CmdManager.h"

class Program
{
private:
	CmdManager cmdManager;
	Window window;

public:
	Program();
	void run();
};

