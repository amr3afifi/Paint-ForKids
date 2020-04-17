#include "Action.h"

class AddTriAction :
	public Action
{
private:
	Point P1, P2, P3; //triangle Points
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();
	~AddTriAction();
};